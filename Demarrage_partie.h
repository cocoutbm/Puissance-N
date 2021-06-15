//
// Created by coco on 02/06/2021.
//

#ifndef IFB_PROJET_DEMARRAGE_PARTIE_H
#define IFB_PROJET_DEMARRAGE_PARTIE_H

#include <stdio.h>
#include <stdlib.h>
#include "windows.h"
#include "Grille.h"


/**
 * permet la mis en couleur des caractères du tableau
 * @param couleurDuTexte la couleur du texte
 * @param couleurDeFond  la couleur du fond
 */
void Color(int couleurDuTexte,int couleurDeFond);

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

#endif //IFB_PROJET_DEMARRAGE_PARTIE_H
