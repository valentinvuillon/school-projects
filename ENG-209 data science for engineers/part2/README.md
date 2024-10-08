# ENG 209
# Data science pour ingénieurs avec Python
# 2ième partie

## Introduction

Ce projet RENKU combine les technologies presentées dans les Lectures 6 et 7 
du cours de Data science pour les ingénieurs avec Python.

C'est un dépôt git avec des fonctions supplémentaires.
Vous découvrirez que ce projet contient déjà les répértoires
`data` et `notebooks` ansi qu'un `Dockerfile` que vous pouvez utiliser pour
configurer votre environement.

Les étudiants sont invités à créer une copie de ce projet, qu'ils utiliseront
jusqu'à la fin de ce cours.

## Comment utiliser ce projet

La façon la plus simple de démarrer votre projet est de vous rendre directement sur renkulab.io.
Il suffit de cliquer sur l'onglet "Environnement" et de démarrer une nouvelle session.
Un environnement interactif s'ouvrira alors directement dans votre navigateur.

Pour travailler avec le projet n'importe où en dehors de la plateforme Renku,
cliquez sur l'onglet "Réglages" où vous trouverez l'URL du dépôt git -
utilisez "git" avec cette URL pour cloner le projet sur la machine de votre choix.

### Ajouter des paquets dans l'environement intéractif

Au départ, nous installons un ensemble très réduit de paquets pour que les images restent petites.
Cependant, vous pouvez ajouter des paquets python et conda dans `requirements.txt` et
l'environnement.yml qui sont à votre disposition dans le projet. Si vous avez besoin de
plus de contrôle de votre environnement, veuillez consulter [the documentation](https://renku.readthedocs.io/en/latest/user/advanced_interfaces.html#dockerfile-modifications).

## Configuration de projet

Project options can be found in `.renku/renku.ini`. In this
project there is currently only one option, which specifies
the default type of environment to open, in this case `/lab` for
JupyterLab. You may also choose `/tree` to get to the "classic" Jupyter
interface.

Les options du projet peuvent être trouvées dans `.renku/renku.ini`. Dans ce projet
il n'y a actuellement qu'une seule option, qui précise
le type d'environnement à ouvrir par défaut, dans ce cas "/lab" pour
JupyterLab. Vous pouvez également choisir `/tree` pour accéder à l'interface Jupyter "classique.

