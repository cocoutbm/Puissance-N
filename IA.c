//
// Created by coco on 02/06/2021.
//

#include "IA.h"
#include "Jouer.h"
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int computer(Grid grille, int size, int retrait_joueur)
{
    int c_ordi = 0;
    int c_joueur;
    int retrait_ordi = -1;
    int nb_coup_non_perdant = 0;
    int j = 0;
    int winner_ordi = -1, winner_joueur;
    int coup_non_perdant[grille.largeur];

    srand(time(0));

    do
    {
        // On boucle sur les colonnes de la grille (indice c_ordi) pour simuler de coup de l'ordinateur
        if (c_ordi != retrait_joueur - 1) {
            // On n'est pas dans la colonne de l'éventuel retrait du joueur donc on peut traiter
            if (add_token(grille, c_ordi, 'X', true) == 1) {
                // On simule j'ajout d'un jeton dans la colonne qui n'est pas pleine
                winner_ordi = check_winner(grille, size);

                if (winner_ordi != 1) {
                    // Pas de coup gagnant pour l'ordinateur on simule maintenant le jeu du joueur
                    // a partir du coup que vient de jouer l'ordinateur
                    c_joueur = 0;
                    winner_joueur = -1;
                    do {
                        // On simule l'ajout d'un jeton pour le joueur dans chaque case pour
                        // rechercher si le joueur a un coup gagnant
                        if (add_token(grille, c_joueur, 'O', true) == 1) {
                            winner_joueur = check_winner(grille, size);
                            remove_token(grille, c_joueur, true); // Retrait du jeton simulé du joeur
                        }
                        c_joueur++;
                    } while (winner_joueur != 0 && c_joueur < grille.largeur);
                    if (winner_joueur != 0) {
                        // Pas de coup gagnant pour le joueur on note donc la case de l'ordinateur comme
                        // case jouable
                        coup_non_perdant[j++] = c_ordi;
                        nb_coup_non_perdant++;
                    }
                    remove_token(grille, c_ordi, true); // retrait du jeton simulé par l'ordinateur
                }
            }
        }
        c_ordi++;
    } while(winner_ordi != 1 && c_ordi < grille.largeur);
    // On sort si l'ordinateur a un coup gagnant ou qu'on a parcouru la grille

    if (winner_ordi != 1){
        // L'ordinateur n'a pas de coup gagnant
        if (nb_coup_non_perdant == 0 || (nb_coup_non_perdant == 1 && coup_non_perdant[0] == retrait_joueur - 1)) {
            // Il n'y aucun coup non perdant ou il y en a un mais on ne peut pas jouer car il y a un retrait du joueur
            // Dans ce cas on essaye de voir si en retirant un jeton, il y un coup non perdant qui sera joué
            // dans ce cas dans la fonction computer_remmove. Si cette fonction retourne 0 c'est qu'il n'y a
            // aucun coup non perdant
            retrait_ordi = computer_remove(grille, size);
            if(retrait_ordi == -1){
                // Dans ce cas on a perdu dans tout les cas donc on joue au hasard
                do {
                    c_ordi = rand() % grille.largeur;
                } while (c_ordi == retrait_joueur - 1);
                add_token(grille, c_ordi, 'X', false);
            }
        } else {
            // Il y a des coups non perdants, on joue dans au hasard un de ces coups
            // A condition qu'il soit != de la colonne de retrait du joueur s'il y en a une
            do {
                c_ordi = rand() % nb_coup_non_perdant;
            } while (coup_non_perdant[c_ordi] == retrait_joueur - 1);
            add_token(grille, coup_non_perdant[c_ordi], 'X', false);
        }
    }

    return retrait_ordi;
}

int computer_remove(Grid grille, int size) {
    int c_ordi = 0;
    int c_joueur;
    int retrait = -1;
    int winner_joueur;
    char jeton_sup;

    do {
        // On boucle sur les colonnes de la grille (indice c_ordi) pour simuler le coup de l'ordinateur
        winner_joueur = 0;
        jeton_sup = remove_token(grille, c_ordi, true);
        if ( jeton_sup != 'N' ) {
            // On simule le retrait du jeton de la colonne qui n'est pas vide
            c_joueur = 0;
            winner_joueur = -1;
            do {
                // On simule l'ajout d'un jeton pour le joueur dans chaque case pour
                // rechercher si le joueur a un coup gagnant
                if (add_token(grille, c_joueur, 'O', true) == 1) {
                    // On simule l'ajout du jeton du joueur en colonne c_joueur
                    winner_joueur = check_winner(grille, size);
                    remove_token(grille, c_joueur, true); // retrait du jeton
                }
                c_joueur++;
            } while (winner_joueur != 0 && c_joueur < grille.largeur);
            if (winner_joueur == 0) {
                // Le joueur a un coup gagnant, donc ce n'est pas une bonne combinaison
                // on remet le jeton que l'ordinateur à enlevé et on continue
                // Si pas de coup gagnant pour le joueur c'est une bonne combinaison
                // on laisse comme ça et on sort de la boucle
                add_token(grille, c_ordi, jeton_sup, true);
            }
        }
        c_ordi++;
    } while (winner_joueur == 0 && c_ordi < grille.largeur);

    if (winner_joueur != 0) {
        // On a trouvé un retrait qui amène à un coup non perdant donc on reste comme ça
        retrait = c_ordi;
    }

    return retrait;
}
