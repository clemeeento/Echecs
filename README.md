
# Jeu d'Échecs avec IA (Minimax) et Interface Graphique SDL2

Ce projet est une implémentation d'un jeu d'échecs en C avec une intelligence artificielle (IA) basée sur l'algorithme Minimax. L'interface graphique a été développée à l'aide de la bibliothèque SDL2. Ce projet a été réalisé dans le cadre du cours **IA & Jeux**.

## Fonctionnalités

- **Jeu contre l'IA uniquement** : Vous jouez contre une IA qui utilise l'algorithme Minimax.
- **IA basée sur Minimax** : L'IA évalue les coups en simulant plusieurs mouvements à l'avance grâce à l'algorithme Minimax.
- **Interface graphique avec SDL2** : Le jeu utilise la bibliothèque SDL2 pour afficher l'échiquier et gérer les déplacements des pièces à l'aide de la souris.
- **Gestion des règles des échecs** : Le jeu implémente les règles de base des échecs, mais ne prend pas en charge certaines règles comme la **prise en passant** et le **roque**.

## Prérequis

Avant de compiler et exécuter ce projet, vous devez installer les dépendances suivantes :

- **GCC** (ou tout autre compilateur C compatible)
- **SDL2** et **SDL2_image** pour la partie graphique

### Installation des dépendances (Linux)

Sous Linux, vous pouvez installer SDL2 en utilisant la commande suivante :

```bash
sudo apt-get install libsdl2-dev libsdl2-image-dev
```

## Compilation

Pour compiler le projet, vous pouvez simplement utiliser `make` :

```bash
make
```

Cela générera l'exécutable `Echecs`.

## Exécution

Une fois la compilation terminée, vous pouvez exécuter le jeu avec la commande :

```bash
./Echecs
```

## Détails techniques

### IA Minimax

L'algorithme Minimax simule plusieurs coups à l'avance pour évaluer les meilleures options. Contrairement à certaines versions de cet algorithme, cette implémentation n'inclut pas d'élagage alpha-bêta, ce qui signifie que toutes les branches de l'arbre de jeu sont explorées.

### Interface graphique SDL2

L'interface graphique du jeu a été réalisée avec SDL2, qui gère l'affichage de l'échiquier, les mouvements des pièces, et les événements liés à la souris. Le fichier `graphique.c` est responsable de la gestion des événements et de l'affichage visuel.

## Structure du projet

- `deplacement.c` et `deplacement.h` : Gère les déplacements des pièces sur l'échiquier.
- `echecs.c` et `echiquier.c` : Implémente les règles du jeu et la gestion de l'état du jeu (positions des pièces).
- `graphique.c` et `graphique.h` : Interface graphique basée sur SDL2.
- `minmax.c` et `minmax.h` : Implémente l'algorithme Minimax pour l'IA.
- `liste.c` et `liste.h` : Utilitaires pour la gestion des listes de mouvements dans le jeu.
- `Makefile` : Fichier pour automatiser la compilation du projet.

## Contributeurs
* **BOUTELDJA Wassim**
* **FURNON Clément**
