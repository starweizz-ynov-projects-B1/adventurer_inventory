# TP Noté : Inventaire d'aventurier

Application console en C permettant à un aventurier de gérer le poids des objets de son inventaire via un tableau dynamique.

## Fonctionnalités

| Option | Description |
|--------|-------------|
| 1 | Initialiser l'inventaire (malloc) |
| 2 | Ajouter un objet (realloc) |
| 3 | Afficher l'inventaire |
| 4 | Modifier le poids d'un objet |
| 5 | Supprimer le dernier objet (realloc) |
| 6 | Afficher le poids total |
| 7 | Afficher l'objet le plus lourd |
| 8 | Afficher le poids moyen *(bonus)* |
| 0 | Réinitialiser l'inventaire *(bonus)* |
| -1 | Quitter et libérer la mémoire (free) |

## Structure

```
main.c          — boucle principale et menu
inventory.c     — implémentation des fonctions
inventory.h     — déclarations des fonctions
```

## Gestion des erreurs

- Inventaire vide : message d'avertissement affiché
- Index invalide : vérification avant modification
- Poids négatif : refusé à la saisie *(bonus)*

PS : Le README.md a été réalisé avec l'IA, le projet en lui-même, non.