//
// Created by coco on 02/06/2021.
//

#include "Sauvegarde&chargement.h"
#include <stdio.h>
#include <stdlib.h>


void load(FILE *fichier, Grid *grille, char prenom1[100], char prenom2[100], int *player, int *retrait, int *nb_jetons, int *size) {
    int l, h;
    char ligne[100]={0};
    //Ouverture du fichier
    fgets(prenom1, 100, fichier);
    fgets(prenom2, 100, fichier);
    fgets(ligne, 100, fichier);
    *player =atoi(ligne);
    fgets(ligne, 100, fichier);
    *retrait =atoi(ligne);
    fgets(ligne, 100, fichier);
    *nb_jetons =atoi(ligne);
    fgets(ligne, 100, fichier);
    *size = atoi(ligne);

    init_grid(grille, *size);
    for (l = 0; l < grille->largeur; l++) {
        for (h = 0; h < grille->hauteur; h++) {
            fgets(&grille->tableau[l][h], 10, fichier);
        }
    }

}


void save (Grid grille, int nb_jetons, char prenom1[], char prenom2[],int player, int retrait){
    int l = 0 , h = 0;
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
