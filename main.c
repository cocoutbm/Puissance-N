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

            // Ouverture du fichier
            ouverture_fichier(grille, prenom1, prenom2, ligne, player, retrait, nb_jetons, size);

            show_grid(grille);
            printf("\n\n");
            play(grille, jeton, player, prenom1, prenom2, c, size, nb_jetons, retrait);
            break;
        case 'Q': printf("\n=============FIN DE LA PARTIE============= \n");
            break;
    }
    return 0;
}
