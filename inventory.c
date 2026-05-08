//
// Created by antonin on 07/05/2026.
//

#include "stdio.h"
#include "inventory.h"

#include <stdlib.h>

int inventory_size = 0;
float *inventory_items = NULL;

int check_empty_inventory() {
    if (inventory_size == 0) {
        printf("Votre inventaire est vide ! Vous ne pouvez pas faire cette action.\n");
        return 1;
    }
    return 0;
}

void inventory_init() {
    printf("Combien d'objets souhaitez-vous enregistrer ?\n");

    scanf("%d", &inventory_size);

    float *tmp;
    if (inventory_items == NULL) {
        tmp = malloc(sizeof(float) * inventory_size);
    } else {
        tmp = realloc(inventory_items, sizeof(float) * inventory_size);
    }

    if (tmp == NULL) {
        free(inventory_items);
        inventory_items = NULL;
        return;
    }

    inventory_items = tmp;

    printf("Impeccable, %d objets à enregistrer ! Indiquez le poids de chaque objet :\n\n", inventory_size);

    for (int i = 0; i < inventory_size; i++) {
        printf("Objet numero %d :", i+1);

        float tmpItem;

        scanf("%f", &tmpItem);

        if (tmpItem < 0) {
            printf("Poids invalide. Veuillez entrer un poids positif.\n");
            return;
        }

        inventory_items[i] = tmpItem;
    }
}

void add_item_to_inventory() {
    printf("Quel est le poids de l'objet que vous voulez ajouter ?\n");

    inventory_items = realloc(inventory_items, sizeof(float) * (inventory_size + 1));

    float tmpItem;
    scanf("%f", &tmpItem);

    if (tmpItem < 0) {
        printf("Poids invalide. Veuillez entrer un poids positif.\n");
        return;
    }

    inventory_items[inventory_size] = tmpItem;

    inventory_size++;

    printf("Objet ajouté avec succès !\n");
}

void display_inventory() {
    if (inventory_size == 0) {
        printf("Votre inventaire est vide. Initialisez-le ou ajoutez un objet.\n");
        return;
    }
    printf("Vous avez %d objet(s) dans votre inventaire :\n\n", inventory_size);
    for (int i = 0; i < inventory_size; i++) {
        printf("Objet %d : %.2f kg\n", i + 1, inventory_items[i]);
    }
}

void update_item_in_inventory() {
    int index;

    printf("Quel objet modifier ? :");

    scanf("%d", &index);

    if (index < 1 || index > inventory_size) {
        printf("Index invalide. Veuillez entrer un index entre 1 et %d.\n", inventory_size);
        return;
    }

    printf("Quel est le nouveau poids ? :");

    scanf("%f", &inventory_items[index - 1]);
}

void remove_last_item_from_inventory() {
    if (check_empty_inventory() == 1) return;

    inventory_size--;
    inventory_items = realloc(inventory_items, sizeof(float) * inventory_size);

    printf("Dernier objet supprimé. Il reste %d objet(s) dans l'inventaire.\n", inventory_size);
}

void display_total_weight_of_inventory() {
    float total = 0;

    for (int i = 0; i < inventory_size; i++) {
        total += inventory_items[i];
    }

    printf("Le poids total de votre inventaire est de %.2f kg.\n", total);
}

void display_heaviest_item_in_inventory() {
    if (check_empty_inventory() == 1) return;

    float heaviest = inventory_items[0];

    int heaviest_index = 0;
    for (int i = 0; i < inventory_size; i++) {
        if (inventory_items[i] > heaviest) {
            heaviest = inventory_items[i];
            heaviest_index = i;
        }
    }

    printf("L'objet le plus lourd est l'objet numéro %d qui pèse %.2f kg.\n", heaviest_index + 1, heaviest);
}

void display_average_weight_of_inventory() {
    if (check_empty_inventory() == 1) return;

    float total = 0;
    for (int i = 0; i < inventory_size; i++) {
        total += inventory_items[i];
    }
    printf("Le poids moyen de votre inventaire est de %.2f kg.\n", total / inventory_size);
}

void reset_inventory() {
    inventory_size = 0;
    free(inventory_items);
    inventory_items = NULL;

    printf("Réinitialisation de l'inventaire fait avec succès !");
}

void close_inventory() {
    free(inventory_items);
}