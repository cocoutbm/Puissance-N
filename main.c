#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "PuissanceN.h"


int main() {


    Grid grille;
    int winner = 0;
    char start;
    int player;
    int size;
    char jeton = 0;
    int c = 0;


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

    printf("\n");

    play(grille, jeton, c, size, winner);




    return 0;
}
