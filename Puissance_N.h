//
// Created by coco on 30/05/2021.
//

#ifndef IFB_PROJET_PUISSANCE_N_H
#define IFB_PROJET_PUISSANCE_N_H

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "windows.h"

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
 * @param prenom1 le premier prénom
 * @param prenom2 le deuxième prénom
 * @return 0 ou 1 en fonction de l'adversaire (ordinateur ou joueur 2)
 */
int demarrage_nouvelle_partie(char prenom1[], char prenom2[]);


/**
 * demande le nombre de jetons alignés pour gagner
 * @return le nombre de jetons à alignés pour gagner
 */
int taille();

/**
 * Initialise la grille avec des "_" sur chaque case
 * @param grille
 * @param alignement_gagnant
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
 * @param test_ordi savoir si l'ordinateur effectue un test
 * @return si l'insertion est possible (return 1) ou non (return 0)
 */
int add_token(Grid grille, int c, char jetons, bool test_ordi);

/**
 * supprimer un jeton de la grille
 * @param grille
 * @param c la colonne choisie par le joueur
 * @param test_ordi savoir si l'ordinateur effectue un test
 * @return si la suppression est possible (return 1) ou non (return 0)
 */
int remove_token(Grid grille, int c, bool test_ordi);

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
 * Faire jouer l'ordinateur
 * @param grille la grille
 * @param size l'alignement gagnant
 * @param retrait le numéro de colonne où le joueur précédent à enlevé un jeton
 */
int computer(Grid grille, int size, int retrait);

/**
 * Faire choisir à l'ordinateur de retirer un jetons
 * @param grille  la grille
 * @param size l'alignement gagnant
 * @param coup_non_perdant le tableau des indices de colonnes où l'ordinateur va pouvoir choisir pour retirer un jeton
 */
int computer_remove(Grid grille, int size);

/**
 * Enregistre la grille lors que les joueurs décident de quitter la partie
 * @param grille la grille
 * @param nb_jetons compteur des jetons joués
 * @param prenom1 le premier prénom
 * @param prenom2 le deuxième prénom
 */
void save (Grid grille, int nb_jetons, char prenom1[], char prenom2[],int player, int retrait);

/**
 * Charge la partie enregistrée
 * @param fichier le fichier d'enregistrement
 * @param grille la grille
 */
void charger_partie(FILE *fichier, Grid grille);

/**
 * permet la mis en couleur des caractères du tableau
 * @param couleurDuTexte la couleur du texte
 * @param couleurDeFond  la couleur du fond
 */
void Color(int couleurDuTexte,int couleurDeFond);

int saisie_int();

#endif //IFB_PROJET_PUISSANCE_N_H

