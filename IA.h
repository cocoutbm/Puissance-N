//
// Created by coco on 02/06/2021.
//

#ifndef IFB_PROJET_IA_H
#define IFB_PROJET_IA_H
#include "Grille.h"

/**
 * Fait jouer l'ordinateur quand c'est à son tour
 * @param grille la grille
 * @param size l'alignement gagant
 * @param retrait l'indice de la colonne de retrait
 * @return
 */
int computer(Grid grille, int size, int retrait);

/**
 * Faire choisir à l'ordinateur de retirer un jetons
 * @param grille  la grille
 * @param size l'alignement gagnant
 */
int computer_remove(Grid grille, int size);

#endif //IFB_PROJET_IA_H
