# -*- coding: utf-8 -*-
# ---
# jupyter:
#   jupytext:
#     text_representation:
#       extension: .py
#       format_name: percent
#       format_version: '1.3'
#       jupytext_version: 1.16.6
#   kernelspec:
#     display_name: Python 3 (ipykernel)
#     language: python
#     name: python3
# ---

# %% [markdown]
# # Content
#
# * ### 1 - Enviornment settings
# * ### 2 - Weather data preparation
# * ### 3 - SBB data preparation
#     * ### 3.1 - Filter trips from SBB Istdaten
#     * ### 3.2 - Transform the data
#     * ### 3.3 - Create journey dataframe
# * ### 4 - Delay model
#     * ### 4.1 - Feature engineering
#     * ### 4.2 - Model building
#     * ### 4.3 - Performance evaluation

# %% [markdown]
# # Define region names here

# %%
region_names = ['Lausanne', 'Ouest lausannois']
region_tuple_sql = "(" + ",".join(f"'{r}'" for r in region_names) + ")"

# %% [markdown]
# # 1 - Environment settings

# %%
# used later, need to be installed
# !pip install shapely

# %%
groupName='L1'

# %%
import os
import warnings

warnings.simplefilter(action='ignore', category=UserWarning)
warnings.filterwarnings("ignore", category=UserWarning, message="pandas only supports SQLAlchemy connectable .*")

# %%
import base64 as b64
import json
import time
import re
import pandas as pd

def getUsername():
    payload = os.environ.get('EPFL_COM490_TOKEN').split('.')[1]
    payload=payload+'=' * (4 - len(payload) % 4)
    obj = json.loads(b64.urlsafe_b64decode(payload))
    if (time.time() > int(obj.get('exp')) - 3600):
        raise Exception('Your credentials have expired, please restart your Jupyter Hub server:'
                        'File>Hub Control Panel, Stop My Server, Start My Server.')
    time_left = int((obj.get('exp') - time.time())/3600)
    return obj.get('sub'), time_left


# %%
username, validity_h = getUsername()
hadoopFS = os.environ.get('HADOOP_FS')
namespace = 'iceberg.' + username
sharedNS = 'iceberg.com490_iceberg'

if not re.search('[A-Z][0-9]', groupName):
    raise Exception('Invalid group name {groupName}')

print(f"you are: {username}")
print(f"credentials validity: {validity_h} hours left.")
print(f"shared namespace is: {sharedNS}")
print(f"your namespace is: {namespace}")
print(f"your group is: {groupName}")

# %%
import trino
from contextlib import closing
from urllib.parse import urlparse
from trino.dbapi import connect
from trino.auth import BasicAuthentication, JWTAuthentication

trinoAuth = JWTAuthentication(os.environ.get('EPFL_COM490_TOKEN'))
trinoUrl  = urlparse(os.environ.get('TRINO_URL'))
Query=[]

print(f"Warehouse URL: {trinoUrl.scheme}://{trinoUrl.hostname}:{trinoUrl.port}/")

conn = connect(
    host=trinoUrl.hostname,
    port=trinoUrl.port,
    auth=trinoAuth,
    http_scheme=trinoUrl.scheme,
    verify=True
)

print('Connected!')

# %% [markdown]
# ### Start a spark Session environment

# %% [markdown]
# We provide the `username` and `hadoopFS` as Python variables accessible in both environments. You can use them to enhance the portability of your code, as demonstrated in the following Spark SQL command. Additionally, it's worth noting that you can execute Iceberg SQL commands directly from Spark on the Iceberg data.

# %%
import os
import pwd
import numpy as np
import sys

from pyspark.sql import SparkSession
from random import randrange
import pyspark.sql.functions as F
#np.bool = np.bool_


username = pwd.getpwuid(os.getuid()).pw_name
hadoopFS=os.getenv('HADOOP_FS', None)
groupName = 'L1'

print(os.getenv('SPARK_HOME'))
print(f"hadoopFSs={hadoopFS}")
print(f"username={username}")
print(f"group={groupName}")

# %%
spark = SparkSession\
            .builder\
            .appName(pwd.getpwuid(os.getuid()).pw_name)\
            .config('spark.ui.port', randrange(4040, 4440, 5))\
            .config("spark.executorEnv.PYTHONPATH", ":".join(sys.path)) \
            .config('spark.jars', f'{hadoopFS}/data/com-490/jars/iceberg-spark-runtime-3.5_2.13-1.6.1.jar')\
            .config('spark.sql.extensions', 'org.apache.iceberg.spark.extensions.IcebergSparkSessionExtensions')\
            .config('spark.sql.catalog.iceberg', 'org.apache.iceberg.spark.SparkCatalog')\
            .config('spark.sql.catalog.iceberg.type', 'hadoop')\
            .config('spark.sql.catalog.iceberg.warehouse', f'{hadoopFS}/data/com-490/iceberg/')\
            .config('spark.sql.catalog.spark_catalog', 'org.apache.iceberg.spark.SparkSessionCatalog')\
            .config('spark.sql.catalog.spark_catalog.type', 'hadoop')\
            .config('spark.sql.catalog.spark_catalog.warehouse', f'{hadoopFS}/user/{username}/assignment-3/warehouse')\
            .config("spark.sql.warehouse.dir", f'{hadoopFS}/user/{username}/assignment-3/spark/warehouse')\
            .config('spark.eventLog.gcMetrics.youngGenerationGarbageCollectors', 'G1 Young Generation')\
            .config("spark.executor.memory", "6g")\
            .config("spark.executor.cores", "4")\
            .config("spark.executor.instances", "4")\
            .master('yarn')\
            .getOrCreate()

# %%
spark.sparkContext

# %%
# %%time
spark.sql(f'CREATE SCHEMA IF NOT EXISTS spark_catalog.{username}')

# %%
# %%time
spark.sql(f'USE spark_catalog.{username}')

# %%
# %%time
spark.read.options(header=True).csv(f'/data/com-490/csv/weather_stations').withColumns({
      'lat': F.col('lat').cast('double'),
      'lon': F.col('lon').cast('double'),
    }).createOrReplaceTempView("weather_stations")

# %% [markdown]
# ---
# # 2 - Weather data preparation
#
# ### Load the weather data
# To be included as feature of the predicitve model.

# %%
from pyspark.sql.functions import explode
from pyspark.sql.functions import from_unixtime, year, month, dayofmonth, hour, minute, timestamp_seconds, from_utc_timestamp

# %%
# %%time
# Load
weather_json = spark.read.option("multiline", True).json("/data/com-490/json/weather_history/")

# Explode the 'observations' array into individual rows
weather_data = weather_json.select(
    "metadata",
    "site",
    "year",
    "month",
    F.explode("observations").alias("observation")
)

# %%
# %%time
# From weather_data, created in Part 1.a, we select the columns that need to appear in weather_df
weather_df = weather_data.select(
    weather_data.site,
    weather_data.observation.valid_time_gmt,
    from_utc_timestamp(F.from_unixtime("observation.valid_time_gmt"), "Europe/Zurich").alias("observation_time_tz"),
    weather_data.observation.valid_time_gmt.alias("valid_time_gmt"),
    weather_data.observation.clds.alias("clds"),
    weather_data.observation.day_ind.alias("day_ind"),
    weather_data.observation.dewPt.alias("dewPt"),
    weather_data.observation.feels_like.alias("feels_like"),
    weather_data.observation.gust.alias("gust"),
    weather_data.observation.heat_index.alias("heat_index"),
    weather_data.observation.obs_name.alias("obs_name"),
    weather_data.observation.precip_hrly.alias("precip_hourly"),
    weather_data.observation.precip_total.alias("precip_total"),
    weather_data.observation.pressure.alias("pressure"),
    weather_data.observation.rh.alias("rh"),
    weather_data.observation.temp.alias("temp"),
    weather_data.observation.uv_desc.alias("uv_desc"),
    weather_data.observation.uv_index.alias("uv_index"),
    weather_data.observation.vis.alias("vis"),
    weather_data.observation.wc.alias("wc"),
    weather_data.observation.wdir_cardinal.alias("wdir_cardinal"),
    weather_data.observation.wspd.alias("wspd"),
    weather_data.observation.wx_phrase.alias("wx_phrase"),
    F.year(from_utc_timestamp(F.from_unixtime("observation.valid_time_gmt"), "Europe/Zurich")).alias("year"),
    F.month(from_utc_timestamp(F.from_unixtime("observation.valid_time_gmt"), "Europe/Zurich")).alias("month"),
    F.dayofmonth(from_utc_timestamp(F.from_unixtime("observation.valid_time_gmt"), "Europe/Zurich")).alias("dayofmonth"),
    F.hour(from_utc_timestamp(F.from_unixtime("observation.valid_time_gmt"), "Europe/Zurich")).alias("hour"),
    F.minute(from_utc_timestamp(F.from_unixtime("observation.valid_time_gmt"), "Europe/Zurich")).alias("minute")
)

weather_df = weather_df.filter(weather_df.year.isin(2022, 2023, 2024))

# %% [markdown]
# ### Get the weather stations name corresponding to selected region(s)

# %%

# %%
from shapely import wkb
from shapely.geometry import Point

# %%
shapes_df = spark.sql(f"""
SELECT name, wkb_geometry
FROM iceberg.geo.shapes
WHERE name IN {region_tuple_sql}
""").toPandas()


# Convert binary WKB to shapely geometry
shapes_df["geometry"] = shapes_df["wkb_geometry"].apply(lambda x: wkb.loads(bytes(x)))

stations_df = spark.sql("SELECT Name, lat, lon FROM weather_stations").toPandas()
stations_df = stations_df.dropna(subset=["lat", "lon"])

def is_in_any_region(lat, lon, geometries):
    point = Point(lon, lat)
    return any(poly.contains(point) for poly in geometries)

region_geometries = shapes_df["geometry"].tolist()
stations_df["in_region"] = stations_df.apply(
    lambda row: is_in_any_region(row["lat"], row["lon"], region_geometries), axis=1
)

filtered = stations_df[stations_df["in_region"]]
names_list = filtered["Name"].unique().tolist()

# %% [markdown]
# ---
# # 3 - SBB data preparation

# %% [markdown]
# ## 3.1 - Filter trips from SBB Istdaten

# %% [markdown]
# Create the DataFrame _istdaten_trips_df_ from the _iceberg.sbb.istdaten_ table.
#
# The table:
# - Only include the ids of _distinct_ trip that appear on at least 200 different days in _isdaten_ in _2024_
# - Onyl trip ids that serve stops in the selected region(s).
#   

# %%
path_stops = f"{hadoopFS}/user/com-490/group/{groupName}/sbb_stops_selected_regions/data"
stops_df = spark.read.parquet(path_stops)

# Rename the 'stop_id_cleaned' column to 'stop_id'
stops_df = stops_df.withColumnRenamed('stop_id_cleaned', 'stop_id')
stops_df.createOrReplaceTempView('stops_df')


# %%
# %%time
istdaten_trips_df = spark.sql(f"""
    SELECT trip_id
    FROM iceberg.sbb.istdaten
    WHERE year(operating_day) = 2024 AND bpuic in (select stop_id from stops_df)
    GROUP BY trip_id
    HAVING COUNT(DISTINCT operating_day) >= 200
""")

# %%
# %%time
istdaten_trips_df.createOrReplaceTempView('istdaten_trip_ids')

# %% [markdown]
# ## 3.2 - Transform the data
#
# Next, we use the _istdaten_trips_df_ table to create a Spark Dataframe _istdaten_df_ that contains a subset of _sbb.istdaten_ containing only trips that are listed into _istdaten_trips_df_.
#
# The table must:
# - Include the _istdaten_ details for the full year 2024 of all the trips that appear in _istdaten_trips_df_.
# - Not include _failed_ or _unplanned_ trips.
# - Include all stops in the selected region(s) and stops that are not listed in the selected region(s), but are connected via at least one trip to stops in the Lausanne area.

# %%
# %%time
istdaten_df = spark.sql(f"""
    SELECT operating_day, trip_id, bpuic, arr_time, arr_actual, dep_time, dep_actual
    FROM iceberg.sbb.istdaten
    WHERE year(operating_day) = 2024 AND trip_id in (select trip_id from istdaten_trip_ids)
    AND unplanned = false AND failed = false
""")

# %%
istdaten_df.printSchema()

# %% [markdown]
# ## 3.3 - Create journey dataframe
#
# We create a windows operator as seen before to work on _operating_day, trip_id_, _ordered_ by _arr_time_ (expected arrival times, and actual arrival times to break ties if expected arrival times are equal). Use the window to create the Spark DataFrame _trip_sequences_df_. In each window, compute:
# - _start_time_: the **first non-null** (ignore nulls) expected _dep_time_ in the window, with respect to the window's ordering.
# - _sequence_: the order of the _bpuic_ in the trip journey, according to the windows' ordering.
# - _arr_time_rel_: the interval _(arr_time - start_time)_, or NULL if _arr_time_ is NULL
# - _dep_time_rel_: the interval _(dep_time - start_time)_, or NULL if _dep_time_ is NULL
# - _arr_actual_rel_: the interval _(arr_actual - start_time)_, or NULL if _arr_actual_ is NULL
# - _dep_actual_rel_: the interval _(dep_actual - start_time)_, or NULL if _dep_actual_ is NULL

# %%
from pyspark.sql import Window
window = Window.partitionBy("operating_day", "trip_id") \
               .orderBy(
                   F.col("arr_time").asc(),
                   F.col("arr_actual").asc()
               )
start_time = F.first("dep_time", ignorenulls=True).over(window)

# %%
sequence = F.rank().over(window)

# %% [markdown]
# We compute relative arrival and departure times from the `start_time`, and construct the dataframe `trip_sequences_df` that includes:
# - absolute start time of the trip,
# - relative expected and actual times (arrival/departure),
# - ordered sequence of stops.

# %%
# Compute all relative times (arr_time - start_time, etc.)
arr_time_rel = (F.col("arr_time") - start_time).alias("arr_time_rel")
dep_time_rel = (F.col("dep_time") - start_time).alias("dep_time_rel")
arr_actual_rel = (F.col("arr_actual") - start_time).alias("arr_actual_rel")
dep_actual_rel = (F.col("dep_actual") - start_time).alias("dep_actual_rel")

# Now create trip_sequences_df
trip_sequences_df = (
    istdaten_df
    .withColumn("start_time", start_time)
    .withColumn("sequence", sequence)
    .withColumn("arr_time_rel", arr_time_rel)
    .withColumn("dep_time_rel", dep_time_rel)
    .withColumn("arr_actual_rel", arr_actual_rel)
    .withColumn("dep_actual_rel", dep_actual_rel)
    .select(
        "operating_day", 
        "trip_id", 
        "bpuic", 
        "start_time", 
        "sequence", 
        "arr_time_rel", 
        "dep_time_rel", 
        "arr_actual_rel", 
        "dep_actual_rel"
    )
)

# %%
trip_sequences_df.printSchema()

# %%
trip_sequences_df.createOrReplaceTempView('trip_sequences_df')

# %% [markdown]
# ---
# # 4 - Delay model
#

# %%
from pyspark.ml.classification import LogisticRegression
from pyspark.ml import Pipeline
from pyspark.ml.feature import StandardScaler
from pyspark.ml.tuning import CrossValidator, ParamGridBuilder
from pyspark.ml.evaluation import MulticlassClassificationEvaluator
from pyspark.sql.functions import sum as spark_sum
from pyspark.ml.feature import VectorAssembler
import matplotlib.pyplot as plt

# %% [markdown]
# ## 4.1 - Feature engineering
#
# Steps for preparing the training set : 
#
# 1. **Delay labeling** : We first compute both arrival and departure delays from the relative time columns. Early arrivals are ignored, since the focus is on late arrivals which have operational impact (negative arrival delays set to 0). Then, a binary label is created: label = 1 if the arrival delay is at least 5 minutes (300 seconds), otherwise label = 0.
#
# 2. **Weather data integration** : We include additonal data source to enrich our the dataset using weather data. The feature added will be computed from the precipitation (precip_hourly) column of the weather data. The fetaure rain is 0 or 1, depending on wether precip_hopurly is > 0 or not.
#
# Weather data is matched with our labelled dataframe by date and hour.
#
# 4. **Time-based features** : We extract the following features from the operating day:
# - day_of_week
# - month
#
# 4. **Historical delay aggregation** : We compute historical trends in delay to capture temporal and spatial trends of delays and to serve as additional predictors:
# - avg_delay_hour: Average delay by hour of day.
# - avg_delay_bpuic: Average delay per stop (bpuic).
#
# To confirm the relevance of these features, we visualized both the hourly average delay and the per-station average delay. These plots clearly show that average delays vary by time of day and location, justifying their inclusion in our model.
# These 2 datafgrames are saved in the hdfs shared folder, as they will need to be accessed during the routing algorithm, when building the path vector fratures.
#
# 5. **Feature Selection**: We explicitly define the list of important features to include in the final model:
# ["rain", "hour", "day_of_week", "avg_delay_7d", "avg_delay_hour", "avg_delay_bpuic"].
#
# 6. **Missing values:** : For each selected feature, we calculate the number and percentage of missing (null) values in the dataset. The only feature that had nan values was 'rain'. For lausanne region, it had very low percentages (~5%). Because the proportion is minimal, we choose to drop the rows that contain missing values for that features.
#    
# 7. **Class balance** : We analyze the distribution of the target variable label, and the results show a strong class imbalance:
# - About 97.5% of the samples belong to class 0 (no delay or small delay),
# - Only 2.5% of the samples are labeled 1 (significant delay).
#
# This will be handled during modeling.
#
# 8. **Assemble feature vector**: we use VectorAssembler to combine all selected features into a single features vector column, which is the expected format for training ML models in Spark.
# The final modeling dataframe contains two columns: features and label, ready for training.

# %%
# 1 Delay labelling

delays_df = trip_sequences_df.select(
    "operating_day",
    "trip_id",
    "bpuic",
    "sequence",
    "start_time",
    #(F.col("arr_actual_rel").cast("long") - F.col("arr_time_rel").cast("long")).alias("arrival_delay"),
    F.when(
        (F.col("arr_actual_rel").cast("long") - F.col("arr_time_rel").cast("long")) < 0,
        0
    ).otherwise(
        F.col("arr_actual_rel").cast("long") - F.col("arr_time_rel").cast("long")
    ).alias("arrival_delay"),
    
    (F.col("dep_actual_rel").cast("long") - F.col("dep_time_rel").cast("long")).alias("departure_delay")
).filter(F.col("arrival_delay").isNotNull())


labeled_df = delays_df.withColumn(
    "label",
    F.when(F.col("arrival_delay") >= 300, 1).otherwise(0)
).withColumn("hour", F.hour("start_time"))

# %%
# 2. Add weather data
weather_features = weather_df.filter(F.col("site").isin(names_list)).select(
    F.date_trunc("day", "observation_time_tz").alias("weather_date"),
    F.hour("observation_time_tz").alias("weather_hour"),
    (F.col("precip_hourly") > 0).cast("int").alias("rain")
)

feature_df = labeled_df.join(
    weather_features,
    (F.col("operating_day") == F.col("weather_date")) & (F.col("hour") == F.col("weather_hour")),
    "left"
).drop("weather_date", "weather_hour")

# %%
# 3. Extract time-based features 
feature_df = feature_df.withColumn("day_of_week", F.dayofweek("operating_day")) \
    .withColumn("month", F.month("operating_day")) \
    .withColumn("is_weekend", F.when(F.col("day_of_week").isin(1, 7), 1).otherwise(0))

# %%
# 4.b Historical delay aggregates : averaged by hour
avg_delay_by_hour = labeled_df.groupBy("hour").agg(
    F.avg("arrival_delay").alias("avg_delay_hour")
)
# Save the df to a csv file (for re use in th emain file)
avg_delay_by_hour.write.csv(f"{hadoopFS}/user/com-490/group/{groupName}/avg_delay_by_hour.csv", header=True, mode="overwrite")


# Visualize the results
avg_delay_by_hour_pd = avg_delay_by_hour.orderBy("hour").toPandas()
plt.figure(figsize=(10, 5))
plt.bar(avg_delay_by_hour_pd["hour"], avg_delay_by_hour_pd["avg_delay_hour"])
plt.xlabel("Hour of day")
plt.ylabel("Average delay (seconds)")
plt.title("Average delay by hour")
plt.grid(True)
plt.show()

# %%
# 4.c Historical delay aggregates :averaged by station

avg_delay_by_bpuic = labeled_df.groupBy("bpuic").agg(
    F.avg("arrival_delay").alias("avg_delay_bpuic")
)
# Save the df to a csv file (for re use in th emain file)
avg_delay_by_bpuic.write.csv(f"{hadoopFS}/user/com-490/group/{groupName}/avg_delay_by_bpuic.csv", header=True, mode="overwrite")

# Visualize results
avg_delay_by_bpuic_pd = avg_delay_by_bpuic.orderBy("bpuic").toPandas()
plt.figure(figsize=(10, 5))
plt.bar(avg_delay_by_bpuic_pd["bpuic"].astype(str), avg_delay_by_bpuic_pd["avg_delay_bpuic"])
plt.xlabel("Station (bpuic)")
plt.ylabel("Average delay (seconds)")
plt.title("Average delay by station (bpuic)")
plt.xticks([], []) # too many stations, not readable on the graph axis
plt.show()

# %%
# 4.d Add these two to the feature_df

# Join by hour
feature_df = feature_df.join(avg_delay_by_hour, on="hour", how="left")
# Join by bpuic
feature_df = feature_df.join(avg_delay_by_bpuic, on="bpuic", how="left")

# %%
# 5. Final feature columns
feature_columns = ["rain", "hour", "day_of_week", "avg_delay_hour", "avg_delay_bpuic"]

# %%
feature_df = feature_df.na.drop(subset=feature_columns)

# %%
# 8. Assemble features
assembler = VectorAssembler(inputCols=feature_columns, outputCol="features", handleInvalid="skip")
model_df = assembler.transform(feature_df).select("features", "label").na.drop()

# %% [markdown]
# ## 4.2 Model building
#
# To address the issue of class imabalancen we proceed by:
#
# - Introducing class weights to penalize misclassification of rare delayed events.
# - Scaling features to ensure fair model convergence.
# - Using hyperparameter tuning (via a grid search over regularization parameters).
# - Applying cross-validation (3-fold CV) to improve generalizability and avoid overfitting.
#
# These adjustments aim to create a more balanced and effective classifier.
#

# %%
from pyspark.ml.evaluation import BinaryClassificationEvaluator, MulticlassClassificationEvaluator
from datetime import datetime

# Add class weights
model_df = model_df.withColumn(
    "class_weights",
    F.when(F.col("label") == 1, 20.0).otherwise(1.0)
)

train_df, test_df = model_df.randomSplit([0.8, 0.2], seed=42)

scaler = StandardScaler(
    inputCol="features",
    outputCol="scaledFeatures",
    withMean=True,
    withStd=True
)

lr = LogisticRegression(
    featuresCol="scaledFeatures",
    labelCol="label",
    weightCol="class_weights"
)

pipeline = Pipeline(stages=[scaler, lr])

# Hyperparam grid
param_grid = ParamGridBuilder() \
    .addGrid(lr.regParam, [0.01, 0.1, 0.3]) \
    .addGrid(lr.elasticNetParam, [0.0, 0.5, 1.0]) \
    .build()

# CV
evaluator = MulticlassClassificationEvaluator(
    labelCol="label",
    predictionCol="prediction",
    metricName="f1"
)

crossval = CrossValidator(
    estimator=pipeline,
    estimatorParamMaps=param_grid,
    evaluator=evaluator,
    numFolds=3,
    seed=42
)

cv_model = crossval.fit(train_df)
best_model = cv_model.bestModel
predictions = best_model.transform(test_df)

print("Best Model Parameters:")
print(f"Regularization: {best_model.stages[-1].getRegParam()}")
print(f"ElasticNet: {best_model.stages[-1].getElasticNetParam()}")

# %%
# Save the trained model to HDFS
timestamp = datetime.now().strftime("%Y%m%d_%H%M%S")
#path = f"hdfs:///user/abdennad/best_model_{timestamp}"
path=f"{hadoopFS}/user/com-490/group/{groupName}/delay_model"
print(path)
best_model.write().overwrite().save(path)

# %% [markdown]
# ## 4.3 -  Performance evaluation

# %%
# Metrics

print("\nClass Distribution in Predictions:")
predictions.groupBy("label", "prediction").count().orderBy("label", "prediction").show()

evaluator_f1 = MulticlassClassificationEvaluator(
    labelCol="label", predictionCol="prediction", metricName="f1"
)
evaluator_precision = MulticlassClassificationEvaluator(
    labelCol="label", predictionCol="prediction", metricName="weightedPrecision"
)
evaluator_recall = MulticlassClassificationEvaluator(
    labelCol="label", predictionCol="prediction", metricName="weightedRecall"
)

print(f"\nOverall F1: {evaluator_f1.evaluate(predictions):.4f}")
print(f"Overall Precision: {evaluator_precision.evaluate(predictions):.4f}")
print(f"Overall Recall: {evaluator_recall.evaluate(predictions):.4f}")

# Per-class metrics
confusion_matrix = predictions.groupBy("label").pivot("prediction").count().na.fill(0)
confusion_matrix.show()

tp = confusion_matrix.first()[1]  # True positives for class 0
fn = confusion_matrix.first()[2]  # False negatives for class 0
fp = confusion_matrix.collect()[1][1]  # False positives for class 1

precision_class0 = tp / (tp + fp) if (tp + fp) != 0 else 0
recall_class0 = tp / (tp + fn) if (tp + fn) != 0 else 0
f1_class0 = 2 * (precision_class0 * recall_class0) / (precision_class0 + recall_class0) if (precision_class0 + recall_class0) != 0 else 0

print(f"\nClass 0 Metrics:")
print(f"Precision: {precision_class0:.4f}")
print(f"Recall: {recall_class0:.4f}")
print(f"F1: {f1_class0:.4f}")

# %%
spark.stop()

# %%
