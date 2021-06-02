//
// Created by coco on 02/06/2021.
//

#include "Sauvegarde&chargement.h"
#include "Jouer.h"
#include <stdio.h>
#include <stdlib.h>

void charger_partie(FILE *fichier, Grid grille) {
    char ligne[100];
    int l, h, taille;
    int size = grille.hauteur * grille.largeur;


    for (l = 0; l < grille.largeur; l++) {
        for (h = 0; h < grille.hauteur; h++) {
            fgets(&grille.tableau[l][h], 10, fichier);
        }
    }
}

void ouverture_fichier(Grid grille, char prenom1[], char prenom2[], char ligne[], int player, int retrait, int nb_jetons, int size){
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

        init_grid(&grille, size);

        charger_partie(fichier,grille);
    }
    fclose(fichier);
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