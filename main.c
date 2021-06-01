#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "Puissance_N.h"

int main() {


    Grid grille;
    int winner = 0;
    char start;
    int player=0;
    char prenom1[100];
    char prenom2[100];
    int size;
    char jeton = 0;
    int c = 0;
    char ligne[100]={0};
    int nb_jetons;
    int retrait = -1;

//    init_grid(&grille, 4);
//    grille.tableau[0][3]='O';
//    grille.tableau[0][4]='O';
//    grille.tableau[2][0]='X';
//    grille.tableau[3][0]='O';
//    grille.tableau[4][0]='O';
//    grille.tableau[0][1]='X';
//    grille.tableau[1][1]='X';
//    grille.tableau[2][1]='O';
//    grille.tableau[0][2]='X';
//    grille.tableau[1][2]='O';
//    grille.tableau[0][3]='O';
//    grille.tableau[3][4]='X';
//    grille.tableau[4][3]='X';

//    grille.tableau[2][4]='O';
//    grille.tableau[3][3]='X';
//    grille.tableau[3][4]='X';
//    grille.tableau[4][3]='X';

//    show_grid(grille);
//computer(grille,4,-1);
//printf("%d \n", check_winner(grille,4));
//show_grid(grille);

    printf("\n=============PUISSANCE N============= \n\n");

    //Démarrage du jeu
    start = demarrage();

    switch (start) {
        case 'N': printf("\n=============NOUVELLE PARTIE============= \n\n");
            //Choix de l'adversaire
            player = demarrage_nouvelle_partie(prenom1, prenom2);

            //Choix du nombre de jetons à aligner et définition de la taille de la grille
            size = taille();

            //Initialisation de la grille avec des '_'
            init_grid(&grille, size);

            //Affichage de la grille initialisée
            show_grid(grille);

            printf("\n");

            play(grille, jeton, player, prenom1, prenom2, c, size, 0, retrait);
            break;
        case 'C': printf("\n=============PARTIE EN COURS============= \n\n");

            FILE* fichier = fopen("fichier.txt", "r");
            if(fichier != NULL) {
                fgets(prenom1, 100, fichier);
                fgets(prenom2, 100, fichier);
                fgets(ligne, 100, fichier);
                player =atoi(ligne);
                fgets(ligne, 100, fichier);
                retrait =atoi(ligne);
                fgets(ligne, 100, fichier);
                nb_jetons =atoi(ligne);
                fgets(ligne, 100, fichier);
                size = atoi(ligne);

                init_grid(&grille, size);

                init_grid(&grille, size-2);

                charger_partie(fichier,grille);
            }
            fclose(fichier);
            printf("\n");
            show_grid(grille);
            play(grille, jeton, player, prenom1, prenom2, c, size, nb_jetons, retrait);
            break;
        case 'Q': printf("\n=============FIN DE LA PARTIE============= \n");
            break;
    }

    return 0;
}
//nom joueur
//message erreur
//fichier
//rapport
//IA