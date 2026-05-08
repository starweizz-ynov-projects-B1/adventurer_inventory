#include <stdio.h>
#include <windows.h>

#include "inventory.h"

int main(void) {
    SetConsoleOutputCP(65001);
    int opt;

    while (1) {
        fflush(stdout);
        printf("\n===== INVENTAIRE DE L'AVENTURIER =====\n\n");
        printf("1. Initialiser l'inventaire\n");
        printf("2. Ajouter un objet\n");
        printf("3. Afficher l'inventaire\n");
        printf("4. Modifier le poids d'un objet\n");
        printf("5. Supprimer le dernier object\n");
        printf("6. Afficher le pois total\n");
        printf("7. Afficher l'objet le plus lourd\n");
        printf("8. Afficher le poids moyen\n");
        printf("--------------------------------\n");
        printf("0. Réinitialiser l'inventaire\n");
        printf("-1. Quitter\n\n");
        printf("Entrez votre choix : ");

        scanf("%d", &opt);

        switch (opt) {
            case 1:
                inventory_init();
                break;
            case 2:
                add_item_to_inventory();
                break;
            case 3:
                display_inventory();
                break;
            case 4:
                update_item_in_inventory();
                break;
            case 5:
                remove_last_item_from_inventory();
                break;
            case 6:
                display_total_weight_of_inventory();
                break;
            case 7:
                display_heaviest_item_in_inventory();
                break;
            case 8:
                display_average_weight_of_inventory();
                break;
            case 0:
                reset_inventory();
                break;
            case -1:
                printf("\nFermeture de l'inventaire...\n");
                close_inventory();
                printf("\nInventaire fermé, mémoire libérée !\n");
                printf("\n===============================\n");
                printf("Vous fermez le jeu, au revoir !");
                printf("\n===============================\n");
                return 0;
            default:
                printf("Choix invalide !\n");
                break;
        }

        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
        printf("\nAppuyez sur Entrée pour continuer...");
        getchar();
    }
}
