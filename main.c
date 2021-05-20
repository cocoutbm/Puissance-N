#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "puissance N.h"


int main() {

    // salut la team

    Grid grille;
    int winner;
    char start;
    int player;
    int size;
    char jeton;
    int nb_jetons=0;
    int choix;
    int c;


    printf("\n=============PUISSANCE N============= \n\n");

    //Démarrage du jeu
    start = demarrage();

    switch (start) {
        case 'N': printf("\n=============NOUVELLE PARTIE============= \n\n");
            break;

    }

    //Choix de l'adversaire
    player = demarrage_nouvelle_partie();

    //Choix du nombre de jetons à aligner et définition de la taille de la grille
    size = taille();

    //Initialisation de la grille avec des '_'
    init_grid(&grille, size);

    //Affichage de la grille initialisée
    show_grid(grille);

    winner = check_winner(grille, size);


do{
    if(nb_jetons % 2 == 0)
    {
        jeton = 'O';

        printf("C'est au joueur 1 de jouer \n");

        printf("Rentrer 0 si vous vouler ajouter un jeton et 1 si vous voulez retirer un jeton : \n");
        scanf("%d", &choix);

        if(choix == 1)
        {
            if(nb_jetons != 0){
                printf("Dans quelle colonne voulez vous enlever un jeton ?\n");
                scanf("%d",&c);
                remove_token(grille, c-1, size+2);
                nb_jetons--;
            }
            else{
                printf("ERREUR, grille vide\n");
            }
        } else {
            printf("Dans quelle colonne voulez vous ajouter un jeton ?\n");
            scanf("%d",&c);
            add_token(grille, c-1, jeton);
            nb_jetons++;
        }
        show_grid(grille);

    } else {

        jeton = 'X';

        printf("C'est au joueur 2 de jouer \n");

        printf("Rentrer 0 si vous vouler ajouter un jeton et 1 si vous voulez retirer un jeton : \n");
        scanf("%d", &choix);

        if(choix == 1)
        {
            if(nb_jetons != 0){
                printf("Dans quelle colonne voulez vous enlever un jeton ?\n");
                scanf("%d",&c);
                remove_token(grille, c-1, size+2);
                nb_jetons--;
            }
            else{
                printf("ERREUR, grille vide\n");
            }
        } else {
            printf("Dans quelle colonne voulez vous ajouter un jeton ?\n");
            scanf("%d",&c);
            add_token(grille, c-1, jeton);
            nb_jetons++;
        }
        show_grid(grille);
    }

} while(winner == -1 && nb_jetons != grille.largeur * grille.hauteur);

    return 0;
}
