//
// Created by coco on 30/05/2021.
//

#include "Jouer.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include "IA.h"
#include "Demarrage_partie.h"
#include "Sauvegarde&chargement.h"

int add_token(Grid grille, int c, char jetons, bool test_ordi){
    int l=0;
    int insertion = 0;

    // boucle afin de trouver la premiere case vide de la colonne
    while(l < grille.hauteur && grille.tableau [l][c] != '_'){
        l++;
    }
    // Remplacement de la case vide par le jeton du joueur
    if(l < grille.hauteur){
        grille.tableau[l][c] = jetons;
        insertion = 1;
    }
    else{
        insertion = 0;
        if (test_ordi == false) {
            printf("ERREUR, colonne pleine \n");
        }
    }

    return insertion;
}

int check_winner(Grid grille, int alignement_gagant)
{
    int gagnant;
    bool alignement_en_cours;
    int l; // ligne
    int c = 0;  // colone
    int indice_c, indice_l;
    int jetons_alignes = 1;

    // Parcours de la grille horizonatlement tant qu'il n'y a pas de gagnant et que nous somme pas au bout de la grille
    do {

        l = 0;
        // Parcours de la grille verticalement tant qu'il n'y a pas de gagnant, que nous somme pas au bout de la grille
        while (jetons_alignes != alignement_gagant && l < grille.hauteur && grille.tableau[l][c] != '_'){

            indice_c = c;
            indice_l = l;
            alignement_en_cours = true;

            // Vérification d'un éventuel alignement gagnant horizontalement
            while (alignement_en_cours == true && jetons_alignes != alignement_gagant && c <= (grille.largeur - alignement_gagant)){
                if(grille.tableau[l][c] != '_' && (grille.tableau[l][c] == grille.tableau[l][indice_c + 1])) {
                    alignement_en_cours = true;
                    jetons_alignes++;
                    indice_c++;

                } else {
                    jetons_alignes = 1;
                    alignement_en_cours = false;
                }
            }

            if (jetons_alignes != alignement_gagant)
            {
                indice_c = c;
                indice_l = l;
                alignement_en_cours = true;
                // Vérification d'un éventuel alignement gagnant diagonnale droite
                while (alignement_en_cours == true && jetons_alignes != alignement_gagant && c <= grille.largeur - alignement_gagant && l <= grille.hauteur - alignement_gagant) {
                    if(grille.tableau[l][c] != '_' && grille.tableau[l][c] == grille.tableau[indice_l + 1][indice_c + 1]){
                        jetons_alignes++;
                        indice_c++;
                        indice_l++;
                        alignement_en_cours = true;

                    } else {
                        jetons_alignes = 1;
                        alignement_en_cours = false;
                    }
                }
            }

            if (jetons_alignes != alignement_gagant) {
                indice_c = c;
                indice_l = l;
                alignement_en_cours = true;
                // Vérification d'un éventuel alignement gagnant verticalement
                while (alignement_en_cours == true && jetons_alignes != alignement_gagant && l <= grille.hauteur - alignement_gagant) {
                    if (grille.tableau[l][c] != '_' && grille.tableau[l][c] == grille.tableau[indice_l + 1][c]) {
                        indice_l++;
                        jetons_alignes++;
                        alignement_en_cours = true;

                    } else {
                        jetons_alignes = 1;
                        alignement_en_cours = false;
                    }
                }
            }

            if (jetons_alignes != alignement_gagant){
                indice_c = c;
                indice_l = l;
                alignement_en_cours = true;
                // Vérification d'un éventuel alignement gagnant diagonale gauche
                while (alignement_en_cours == true && jetons_alignes != alignement_gagant && l <= grille.hauteur - alignement_gagant && c >= alignement_gagant - 1) {
                    if (grille.tableau[l][c] != '_' && grille.tableau[l][c] == grille.tableau[indice_l + 1][indice_c - 1]){
                        indice_l++;
                        indice_c--;
                        jetons_alignes++;
                        alignement_en_cours = true;

                    } else {
                        jetons_alignes = 1;
                        alignement_en_cours = false;
                    }
                }
            }

            l++;

        } // Fin de parcours des lignes

        c++;

    } while (jetons_alignes != alignement_gagant && c < grille.largeur); // Fin de parcours des colognes


    // Annonce du gagnant
    if(jetons_alignes == alignement_gagant && grille.tableau[l - 1][c - 1] == 'O'){
        gagnant = 0;
    } else if(jetons_alignes == alignement_gagant && grille.tableau[l - 1][c - 1] == 'X'){
        gagnant = 1;
    } else {
        gagnant = -1;
    }

    return gagnant;
}

void play(Grid grille, char jeton, int player, char prenom1[], char prenom2[], int c, int size, int nb_jetons, int retrait)
{
    int winner;
    bool ordi;
    char choix;
    char choix_ordi;


    // Boucle qui fait jouer les joueurs chacun leur tour
    do {
        // Connaître le joueur qui doit jouer
        // Quand nb_jetons est pair alors c'est au joueur 1 de jouer
        // Quand nb_jetons est impair alors c'est au joueur 2 de jouer si player == 0 ou à l'ordi quand player == 1
        if (nb_jetons % 2 == 0) {
            ordi = false;
            jeton = 'O';
            printf("+   C'est a %s de jouer\n", prenom1);
        } else if (nb_jetons % 2 != 0) {
            if (player == 0) {
                ordi = false;
                jeton = 'X';
                printf("+   C'est a %s de jouer\n", prenom2);
            } else {
                // Faire jouer l'ordi ou quitter la partie + contrôle
                do {
                    printf("Rentrer O pour faire jouer l'ordinateur ou Q pour quitter: \n");
                    scanf(" %c", &choix_ordi);
                    choix_ordi = toupper(choix_ordi);
                } while (choix_ordi != 'O' && choix_ordi != 'Q');

                ordi = true;
                if (choix_ordi == 'O') {
                    printf("+   C'est a l'ordinateur de jouer \n");
                    retrait = computer(grille, size, retrait);
                    if (retrait == -1) {
                        // L'ordinateur a ajouté un jeton
                        nb_jetons++;
                    } else {
                        // l'odinateur à retiré un jeton
                        nb_jetons--;
                    }
                }

            }
        }

        if (ordi == false)
        {
            // Demande à l'utilisateur le choix qu'il souhaite faire
            if(nb_jetons < 2){
                do {
                    printf("    -   Rentrer A si vous vouler ajouter un jeton ou Q si vous voulez quitter: \n");
                    scanf(" %c", &choix);
                    choix = toupper(choix);
                } while (choix != 'A' && choix != 'Q');
            } else {
                do {
                    printf("    -   Rentrer A si vous vouler ajouter un jeton et R si vous voulez retirer un jeton ou Q si\n"
                           "vous voulez quitter et sauvegarder : \n");
                    scanf(" %c", &choix);
                    choix = toupper(choix);
                } while (choix != 'A' && choix != 'R' && choix != 'Q');
            }

            // En fonction du choix fait, lancer la bonne fonction (add_token ou remove_token)
            if(choix == 'R')
            {
                if(nb_jetons != 0) {
                    do {
                        printf("        /   Dans quelle colonne voulez vous retirer un jeton ?\n");
                        c = saisie_int();
                    } while (c <= 0 || c > grille.largeur);
                    retrait = c;
                    if (remove_token(grille, c - 1, false)) {
                        nb_jetons--;
                    }
                }
                else{
                    printf("    .   ERREUR, grille vide\n");
                }
            } else if (choix == 'A'){
                // vérifie que la saisie de la colonne est bien valide (un entier compris entre ]0, grille.hauteur]
                do {
                    printf("        /   Dans quelle colonne voulez vous ajouter un jeton ?\n");
                    c = saisie_int();
                    if (c == retrait){
                        printf(".   Vous ne pouver pas jouer dans cette colonne "
                               "car le joueur precedent a retirer un jeton \n");
                    }
                } while (c == retrait || c <= 0 || c > grille.largeur);

                if (add_token(grille, c-1, jeton, false)) {
                    // On a pu ajouter un jeton, sinon on ne fait rien et on reboucle sur le joueur en cours
                    nb_jetons++;
                    retrait = -1;
                }
            }
        }

        show_grid(grille);
        winner = check_winner(grille,size);

        printf("\n");

    } while(winner == -1 && nb_jetons < (grille.largeur * grille.hauteur) && choix != 'Q' && choix_ordi != 'Q');


    if(choix == 'Q' || choix_ordi == 'Q'){
        save(grille, nb_jetons, prenom1, prenom2,player,retrait);
    }

    if (winner == 0){
        Color(14, 0);
        printf("=== Le joueur 1 a gagne ===");
        Color(15, 0);
    } else if (winner == 1) {
        if (player == 0){
            Color(4, 0);
            printf("=== Le joueur 2 a gagne ===");
            Color(15, 0);
        } else {
            Color(4, 0);
            printf("=== L'ordinateur a gagne ===");
            Color(15, 0);
        }
    } else {
        printf("=== Match nul ===");
    }
}

int remove_token(Grid grille, int c, bool test_ordi)
{
    int l = grille.hauteur -1; // j'ai modifié
    int suppression = 0;

    // boucle afin de trouver la premiere case pleine de la colonne
    while(l >= 0 && grille.tableau[l][c] == '_'){
        l--;
    }
    // Remplacement de la case pleine par une case vide
    if(l >= 0){
        grille.tableau[l][c] = '_';
        suppression = 1;
    }
    else{
        suppression = 0;
        // Ne pas afficher le message quand l'ordi fait un test
        if (test_ordi == false) {
            printf("ERREUR, colonne vide \n");
        }
    }

    return suppression;
}

int saisie_int() {

    int i = 0;
    int entier = -1;
    char saisie[10];
    bool is_integer = false;

    // mise en chaine de caractères de ma saisie
    scanf("%s", saisie);
    fflush(stdin);

    // Vérifie si mon caractère est compris entre '0' et '9'
    while (saisie[i] != '\0' && saisie[i] >= '0' && saisie[i] <= '9') {
        i++;
        is_integer = true;
    }
    // Si le caractère est un entier alors on le convertit en entier
    // Sinon on retourne -2
    if (saisie[i] == '\0' && is_integer == true) {
        entier = atoi(saisie);
    } else {
        entier = -2;
    }

    return entier;
}
