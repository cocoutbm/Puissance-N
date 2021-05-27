#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "puissance N.h"


int main() {


    Grid grille;
    int winner = 0;
    char start;
    int size;
    char jeton = 0;
    int c = 0;
    char ligne[100]={0};
    int nb_jetons;
    char prenom1[100],prenom2[100];


    printf("\n=============PUISSANCE N============= \n\n");

    //Démarrage du jeu
    start = demarrage();

    switch (start) {
        case 'N': printf("\n=============NOUVELLE PARTIE============= \n\n");
            //Choix de l'adversaire
            demarrage_nouvelle_partie(prenom1, prenom2);

            //Choix du nombre de jetons à aligner et définition de la taille de la grille
            size = taille();

            //Initialisation de la grille avec des '_'
            init_grid(&grille, size);

            //Affichage de la grille initialisée
            show_grid(grille);

            printf("\n");

            play(grille, jeton, c, size, winner,0, prenom1,prenom2);
            break;
        case 'C': printf("\n=============PARTIE EN COURS============= \n\n");

            FILE* fichier = fopen("fichier.txt", "r");
            fgets(ligne, 100, fichier);
            nb_jetons =atoi(ligne);
            fgets(ligne, 100, fichier);
            size = atoi(ligne);
            init_grid(&grille, size-2);
            if(fichier != NULL) {
                charger_partie(fichier,grille);
            }
            fclose(fichier);
            printf("\n");
            show_grid(grille);
            play(grille, jeton, c, size, winner,nb_jetons, prenom1 , prenom2);
            break;
        case 'Q': printf("\n=============FIN DU JEU============= \n\n");
    }






    return 0;
}
//nom joueur
//message erreur
//fichier
//rapport
//IA
