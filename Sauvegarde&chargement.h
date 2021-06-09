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
 * Faire jouer l'ordinateur
 * @param grille la grille
 * @param size l'alignement gagnant
 * @param retrait le numéro de colonne où le joueur précédent à enlevé un jeton
 */
void save (Grid grille, int nb_jetons, char prenom1[], char prenom2[],int player, int retrait);

#endif //IFB_PROJET_SAUVEGARDE_CHARGEMENT_H
