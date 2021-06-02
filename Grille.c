//
// Created by coco on 02/06/2021.
//

#include "Grille.h"
#include <stdio.h>
#include "windows.h"
#include "Demarrage_partie.h"

void init_grid(Grid *grille, int alignement_gagnant)
{
    int l; // ligne
    int c; // colone
    grille->largeur = alignement_gagnant + 2;
    grille->hauteur = alignement_gagnant + 2;
    grille->tableau = malloc(sizeof(char *) * grille->hauteur);

    // Initialisation de la grille avec des '_'
    for(l = 0; l < grille->hauteur; l++)
    {
        grille->tableau[l] = malloc(sizeof(char) * grille->largeur);
        for(c = 0; c < grille->largeur; c++)
        {
            grille->tableau[l][c] = '_';
        }
    }
}

void show_grid(Grid grille)
{
    int l; // ligne
    int c; // colone

    // Affichage de la grille initialisée
    for(l = grille.hauteur - 1; l >= 0; l--){
        for(c = 0; c < grille.hauteur; c++){
            // Passe les jetons 'O' en jaune
            if (grille.tableau[l][c] == 'O'){
                Color(14,0);
                printf("%c  ",grille.tableau[l][c]);
                Color(15,0);
            }
                // Passe les jetons 'X' en rouge
            else if(grille.tableau[l][c] == 'X'){
                Color(4,0);
                printf("%c  ",grille.tableau[l][c]);
                Color(15,0);
            }
                // Les jetons '_' restent blanc
            else if (grille.tableau[l][c] == '_'){
                printf("%c  ",grille.tableau[l][c]);
            }
        }
        printf("\n");
    }
}