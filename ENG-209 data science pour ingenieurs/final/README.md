----
# Data Science pour Ingénieur.e.s avec Python
## EPFL ENG 209, Automne 2020

Projet d'Examen Final, due 11.12.2020 23:59:59 CET

----
## 1. Introduction

Dans ce notebook vous allez étudier les données historiques d'émission CO2 globale, téléchargées de [Our World in Data](https://ourworldindata.org/co2-emissions#co2-emissions-by-region).

Cet examen final va vous permettre de démontrer vos acquis dans les étapes suivantes de la data science:
- Préparation et exploration de la donnée avec pandas
- Apprentissage et évaluation de modèles
- Méthodes de visualisation


## 2. Feuille de vol

1. Formez les binômes
    - Contactez olivier.verscheure@epfl.ch ou eric.bouillet@epfl.ch si vous préférez travailler seul.e    
2. Faites un fork de ce projet et configurez votre projet **0.5/6 pt**
    - Un seul projet par binôme
    - La visibilité de votre projet doit être _Private_.
    - Invitez votre binôme, ainsi que eric.bouillet@epfl.ch, et olivier.verscheure@epfl.ch sous le rôle de _Maintainer_
3. Répondez aux questions du [notebooks/final.ipynb](./notebooks/final.ipynb) **5/6 pt**
4. Sauvez régulièrement votre progrès **0.5/6 pt**
    - Assurez vous que le notebook s'exécute séquentiellement, de bout en bout
    - Sauvez votre progrès sur le dépôt git distant avec les commandes appropriées
    - Sauvez uniquement les réponses code et markdown du notebook, **sans** les résultats de l'exécution du code (faire un _Clear All Outputs_ avant chaque sauvegarde)
5. Première sauvegarde avant le _4.12.2020 23:59:59_
    - C'est uniquement pour vérifier 2 et 4
    - Cela peut être un _hello world_ notebook
6. Sauvegarde finale avant _11.12.2020 23:59:59_ CET (-0.5pt par 12h de retard)
7. Examen oral le _14.12.2020_
    - Oral de 5min, comprenant 1 à 2 questions par binôme
    - Les heures de passage seront organisées via Doodle

## 3. Utilisation de ce projet

### 3.1 Configuration des droits d'accès

Visitez la page principale de votre projet, et cliquer sur `Gitlab view` en haut à droite.
Les paramètres de configuration du dépot gitlab peuvent être modifiés à partir du panneau de gauche de la vue Gitlab.

* La visibilité du projet peut être ajustée sous la section `Settings/general`

* Les droits d'accès peuvent être octroyés sous la section `Settings/members`.

### 3.2 Comment ajouter des paquets pythons dans l'environnement intéractif

Ce projet est configuré avec un ensemble minimal de paquets pythons.
Vous pouvez ajouter des paquets pythons et condas dans les fichiers `requirements.txt` et `environment.yml`.
Une nouvelle image sera automatiquement créée avec les paquets au prochain démarage de votre environnement.

Si vous avez besoin de plus contrôle sur la configuration de votre environnement, veuillez consulter
[la documentation](https://renku.readthedocs.io/en/latest/user/advanced_interfaces.html#dockerfile-modifications).

### 3.3 Configuration

Les préférences de configuration de ce projet peuvent se trouver dans `.renku/renku.ini`.
La seule option disponible est pour l'instant le choix de l'environnement à ouvrire par défaut
au démarrage, qui peut être `/lab` pour JupyterLab, ou `/tree` pour l'interface Jupyter classique ou `/rstudio` si
vous utilisez le Docker R.

## 4. Références

1. Our World in Data, https://ourworldindata.org/
2. Natural Earth Data, https://www.naturalearthdata.com/


