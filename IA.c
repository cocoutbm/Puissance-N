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
        if (add_token(grille, c_ordi, 'X', true) == 1) {
            winner_ordi = check_winner(grille, size);

            if (winner_ordi != 1) {
                c_joueur = 0;
                winner_joueur = -1;
                do {
                    if (add_token(grille, c_joueur, 'O', true) == 1) {
                        winner_joueur = check_winner(grille, size);
                        remove_token(grille, c_joueur, true);
                    }
                    c_joueur++;
                } while (winner_joueur != 0 && c_joueur < grille.largeur);
                if (winner_joueur != 0) {
                    coup_non_perdant[j++] = c_ordi;
                    nb_coup_non_perdant++;
                }
                remove_token(grille, c_ordi, true);
            }
        }
        c_ordi++;
    } while(winner_ordi != 1 && c_ordi < grille.largeur);

    if (winner_ordi != 1){
        // L'ordinateur n'a pas de coup gagnant
        if (nb_coup_non_perdant == 0 || (nb_coup_non_perdant == 1 && retrait_joueur != -1)) {
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


    do {
        winner_joueur = 0;
        if (remove_token(grille, c_ordi, true) == 1) {
            c_joueur = 0;
            winner_joueur = -1;
            do {
                if (add_token(grille, c_joueur, 'O', true) == 1) {
                    winner_joueur = check_winner(grille, size);
                    remove_token(grille, c_joueur, true);
                }
                c_joueur++;
            } while (winner_joueur != 0 && c_joueur < grille.largeur);
            if (winner_joueur == 0) {
                add_token(grille, c_ordi, 'X', true);
            }
        }
        c_ordi++;
    } while (winner_joueur == 0 && c_ordi < grille.largeur);

    if (winner_joueur != 0) {
        retrait = c_ordi;
    }

    return retrait;
}