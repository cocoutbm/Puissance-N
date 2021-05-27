//
// Created by coco on 06/05/2021.
//
#include "stdio.h"

#ifndef TEST_PROJET_PUISSANCEN_H
#define TEST_PROJET_PUISSANCEN_H

/**
 * Caractérise la grille
 */
typedef struct {
    int largeur;
    int hauteur;
    char **tableau;
}Grid;

/**
 * aquisition de l'action de démarrage
 * @return une lettre correspondant à l'action choisis par l'utilisateur
 */
char demarrage();

/**
 * demande a l'utilisateur le type d'adversaire
 * @return 0 ou 1 en fonction de l'adversaire (ordinateur ou joueur 2)
 */
int demarrage_nouvelle_partie();


/**
 * demande le nombre de jetons alignés pour gagner
 * @param adversaire le type d'adversaire
 * @return le nombre de jetons alignés pour gagner
 */
int taille();

/**
 * Initialise la grille avec des "_" sur chaque case
 * @param grille
 */
void init_grid(Grid *grille, int alignement_gagnant);

/**
 * Affiche la grille
 * @param grille
 */
void show_grid(Grid grille);

/**
 * ajouter un jeton de la grille
 * @param grille
 * @param c la colonne choisie par le joueur
 * @param jetons le type de jetons (X ou O)
 * @return si l'insertion est possible
 */
int add_token(Grid grille, int c, char jetons);

/**
 * supprimer un jeton de la grille
 * @param grille
 * @param c la colonne choisie par le joueur
 * @return si la suppression est possible
 */
int remove_token(Grid grille, int c, int size);

/**
 * Vérifie si un des deux joueurs à gagné
 * @param grille
 * @return 0 si joueur1 gagne, 1 si joueur2 gagne, -1 si aucun n'a gagné
 */
int check_winner(Grid grille, int alignement_gagnant);

/**
 * Faire jouer les joueurs chacun leur tour
 * @param grille la grille
 * @param jeton le type de jeton
 * @param c  la colonne
 * @param size
 * @param winner le gagnant
 */
void play(Grid grille, char jeton, int c, int size, int winner, int nb_jetons);


void save (Grid grille, int nb_jetons);

void charger_partie(FILE *fichier, Grid grille);

void IA(Grid grille, int winner, int size, char jetons);



#endif //TEST_PROJET_PUISSANCEN_H
