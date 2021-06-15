//
// Created by coco on 30/05/2021.
//

#ifndef IFB_PROJET_JOUER_H
#define IFB_PROJET_JOUER_H

#include <stdbool.h>
#include "Grille.h"

/**
 * ajouter un jeton de la grille
 * @param grille
 * @param c la colonne choisie par le joueur
 * @param jetons le type de jetons (X ou O)
 * @param test_ordi savoir si l'ordinateur effectue un test
 * @return si l'insertion est possible (return 1) ou non (return 0)
 */
int add_token(Grid grille, int c, char jetons, bool test_ordi);

/**
 * Vérifie si un des deux joueurs à gagné
 * @param grille
 * @param alignement_gagnant
 * @return 0 si joueur1 gagne, 1 si joueur2 gagne, -1 si aucun n'a gagné
 */
int check_winner(Grid grille, int alignement_gagant);

/**
 * Faire jouer les joueurs chacun leur tour
 * @param grille la grille
 * @param jeton le type de jeton
 * @param player le type d'avdversaire (joueur/joueur) ou (joueur/ordinateur)
 * @param prenom1 le premier prénom
 * @param prenom2 le deuxième prénom
 * @param c  la colonne
 * @param size l'alignement gagnant
 * @param winner le gagnant
 */
void play(Grid grille, char jeton, int player, char prenom1[], char prenom2[], int c, int size, int nb_jetons, int retrait);

/**
 * supprimer un jeton de la grille
 * @param grille
 * @param c la colonne choisie par le joueur
 * @param test_ordi savoir si l'ordinateur effectue un test
 * @return le jeton supprimé ou N si on ne peut pas retirer de jeton
 */
char remove_token(Grid grille, int c, bool test_ordi);

/**
 * Vérification de la saisie (si c'est un entier ou non)
 * @return 0 pour un entier compris entre 0 et 9 et -2 pour le reste
 */
int saisie_int();

#endif //IFB_PROJET_JOUER_H

