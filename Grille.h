//
// Created by coco on 02/06/2021.
//

#ifndef IFB_PROJET_GRILLE_H
#define IFB_PROJET_GRILLE_H

/**
 * Caractérise la grille
 */
typedef struct {
    int largeur;
    int hauteur;
    char **tableau;
}Grid;

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

#endif //IFB_PROJET_GRILLE_H
