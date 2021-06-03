//
// Created by coco on 02/06/2021.
//

#include "Sauvegarde&chargement.h"
#include "Jouer.h"
#include <stdio.h>
#include <stdlib.h>

void charger_partie(FILE *fichier, Grid grille) {
    int l, h;

    for (l = 0; l < grille.largeur; l++) {
        for (h = 0; h < grille.hauteur; h++) {
            fgets(&grille.tableau[l][h], 10, fichier);
        }
    }
}


void save (Grid grille, int nb_jetons, char prenom1[], char prenom2[],int player, int retrait){
    int l = 0 , h = 0;
    int size = grille.hauteur*grille.largeur;
    FILE* fichier = fopen("fichier.txt", "w");
    if(fichier != NULL){
        fprintf(fichier, "%s\n", prenom1);
        fprintf(fichier, "%s\n", prenom2);
        fprintf(fichier, "%d\n", player);
        fprintf(fichier, "%d\n", retrait);
        fprintf(fichier, "%d\n",nb_jetons);
        fprintf(fichier, "%d\n",grille.hauteur - 2);
        for(l=0;l<grille.largeur;l++){
            for(h=0;h<grille.hauteur;h++){
                fprintf(fichier, "%c\n",grille.tableau[l][h]);
            }
        }
    }
    fclose(fichier);
}
