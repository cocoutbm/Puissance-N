#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "PuissanceN.h"


int main() {

    Grid grille;
    int winner;
    char start;
    int player;
    int size;
    int ajout_jeton;
    int colonne;
    char jeton;
    int enleve_jeton;

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

    // Ajout d'un jeton 'O' ou 'X'
    ajout_jeton = add_token(grille, colonne,  jeton);

    enleve_jeton = remove_token(grille, colonne);



//    winner = check_winner(grille, size);

//    printf("\n");
//
//    printf("%d", winner);

    return 0;
}
