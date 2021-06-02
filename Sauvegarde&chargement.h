//
// Created by coco on 02/06/2021.
//

#ifndef IFB_PROJET_SAUVEGARDE_CHARGEMENT_H
#define IFB_PROJET_SAUVEGARDE_CHARGEMENT_H
#include <stdio.h>
#include "Grille.h"

/**
 * Charge la partie enregistrée
 * @param fichier le fichier d'enregistrement
 * @param grille la grille
 */
void charger_partie(FILE *fichier, Grid grille);

/**
 * Ouvrir le fichier et écrire dedans la partie sauvegardée
 * @param grille la grille
 * @param prenom1 le prénom du premier joueur
 * @param prenom2 le prénom du deuxième joueur
 * @param ligne
 * @param player le type d'adversaire ('0' => 1 vs 1 et '1' => 1 vs ordinateur)
 * @param retrait l'indice de la colonne de retrait
 * @param nb_jetons le nombre de jetons jouées
 * @param size l'alignement gagnant
 */
void ouverture_fichier(Grid grille, char prenom1[], char prenom2[], char ligne[], int player, int retrait, int nb_jetons, int size);

/**
 * Faire jouer l'ordinateur
 * @param grille la grille
 * @param size l'alignement gagnant
 * @param retrait le numéro de colonne où le joueur précédent à enlevé un jeton
 */

void save (Grid grille, int nb_jetons, char prenom1[], char prenom2[],int player, int retrait);

#endif //IFB_PROJET_SAUVEGARDE_CHARGEMENT_H
