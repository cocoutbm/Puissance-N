//
// Created by coco on 06/05/2021.
//

#include "puissanceN.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

char demarrage(){
    char lettre;

    // demenade et aquisition de l'action souhaitée par l'utilisateur
    printf("*   Entrez N pour une nouvelle partie : \n"
           "*   Entrer C pour charger une partie : \n*   Entrer Q pour quitter le jeu : \n");
    lettre = getchar();

    // mise en majuscule de la lettre entrée par l'utilisateur
    lettre=toupper(lettre);

    // contrôle de l'aquisition avce message d'erreur
    while(lettre !='N' && lettre !='C' && lettre !='Q'){
        printf("Saisie invalide \n");
        printf("*   Entrez N pour une nouvelle partie \n"
               "*   Entrer C pour charger une partie \n*   Entrer Q pour quitter le jeu\n");
        lettre = getchar();
        lettre=toupper(lettre);
    }
    return (lettre);
}

int demarrage_nouvelle_partie(){
    int adversaire;

    // contrôle sans message d'erreur de l'entrée du joueur
    do{
        printf("*   Jouer a deux => Rentrer 0 : \n*   Jouer contre l'ordinateur => Rentrer 1 : \n");
        scanf("%d",&adversaire);
    }while(adversaire != 0 && adversaire != 1);
    if (adversaire == 0){
        printf("    Le joueur 1 a la couleur jaune (jetons O) et le joueur 2 a la couleur rouge (jetons X) \n\n");
    }
    else{
        printf("    Le joueur a la couleur jaune (jetons O) et l'ordinateur a la couleur rouge (jetons X) \n\n");
    }
    return (adversaire);
}


int taille(){
    int alignement_gagnant;
    printf("*   Quel nombre de jetons voulez vous aligner pour gagner ?\n");
    scanf("%d",&alignement_gagnant);
    printf("\n  la taille du tableau est donc de %d par %d\n\n",alignement_gagnant + 2,alignement_gagnant + 2);
    return alignement_gagnant;
}

void init_grid(Grid *grille, int alignement_gagnant)
{
    int l; // ligne
    int c; // colone
    grille->largeur = alignement_gagnant + 2;
    grille->hauteur = alignement_gagnant + 2;
    grille->tableau = malloc(sizeof(char *) * grille->hauteur);

    // Initialisation de la grille avec des '_'
    for(l = 0; l < grille->hauteur; l++)
    {
        grille->tableau[l] = malloc(sizeof(char) * grille->largeur);
        for(c = 0; c < grille->largeur; c++)
        {
            grille->tableau[l][c] = '_';
        }
    }
}

void show_grid(Grid grille)
{
    int l; // ligne
    int c; // colone

    // Affichage de la grille initialisée
    for(l = grille.hauteur - 1; l >= 0; l--){
        for(c = 0; c < grille.hauteur; c++){
            printf("%c  ",grille.tableau[l][c]);
        }
        printf("\n");
    }
}

int add_token(Grid grille, int c, char jetons){
    int l=0;
    int insertion = 0;

    // boucle afin de trouver la premiere case vide de la colonne
    while(grille.tableau [l][c] != '_' && l < grille.hauteur){
        l++;
    }
    // Remplacement de la case vide par le jeton du joueur
    if(l < grille.hauteur){
        grille.tableau[l][c] = jetons;
        insertion = 1;
    }
    else{
        insertion = 0;
        printf("ERREUR, colonne pleine");
    }

    return insertion;
}

int remove_token(Grid grille, int c, int size){
    int l = size;
    int suppression = 0;

    // boucle afin de trouver la premiere case pleine de la colonne
    while(l >= 0 && grille.tableau [l][c] == '_'){
        l--;
    }
    // Remplacement de la case pleine par une case vide
    if(l >= 0){
        grille.tableau[l][c] = '_';
        suppression = 1;
    }
    else{
        suppression = 0;
        printf("ERREUR, colonne vide \n");
    }

    return suppression;
}

int check_winner(Grid grille, int alignement_gagant)
{
    int gagnant;
    bool alignement = false;
    int l; // ligne
    int c = 0;  // colone
    int indice_c, indice_l;
    int jetons_alignes = 1;

    // Parcours de la grille horizonatlement tant qu'il n'y a pas de gagnant et que nous somme pas au bout de la grille
    do {

        l = 0;
        // Parcours de la grille verticalement tant qu'il n'y a pas de gagnant, que nous somme pas au bout de la grille
        while (alignement != true && l < grille.hauteur && grille.tableau[l][c] != '_'){

            indice_c = c;
            indice_l = l;

            // Vérification d'un éventuel alignement gagnant horizontalement
            do{
                if(grille.tableau[l][c] != '_' && (grille.tableau[l][c] == grille.tableau[l][indice_c + 1])) {
                    alignement = true;
                    jetons_alignes++;
                    indice_c++;
                } else {
                    jetons_alignes = 1;
                    alignement = false;
                }
            } while (alignement != false && jetons_alignes != alignement_gagant && c < (grille.largeur - alignement_gagant));


            if (alignement == false)
            {
                // Vérification d'un éventuel alignement gagnant diagonnale droite
                do {
                    if(grille.tableau[l][c] != '_' && grille.tableau[l][c] == grille.tableau[indice_l + 1][indice_c + 1]){
                        jetons_alignes++;
                        indice_c++;
                        indice_l++;
                        alignement = true;
                    } else {
                        jetons_alignes = 1;
                        alignement = false;
                    }
                } while (alignement != false && jetons_alignes != alignement_gagant && c <= grille.largeur - alignement_gagant);
            }

            if (alignement == false) {
                // Vérification d'un éventuel alignement gagnant verticalement
                do {
                    if (grille.tableau[l][c] != '_' && grille.tableau[l][c] == grille.tableau[indice_l + 1][c]) {
                        indice_l++;
                        jetons_alignes++;
                        alignement = true;
                    } else {
                        jetons_alignes = 1;
                        alignement = false;
                    }
                } while (alignement != false && jetons_alignes != alignement_gagant && l < grille.hauteur - alignement_gagant);
            }

            if (alignement == false){
                // Vérification d'un éventuel alignement gagnant diagonale gauche
                do {
                    if (grille.tableau[l][c] != '_' && grille.tableau[l][c] == grille.tableau[indice_l + 1][indice_c - 1]){
                        indice_l++;
                        indice_c--;
                        jetons_alignes++;
                        alignement = true;
                    } else {
                        jetons_alignes = 1;
                        alignement = false;
                    }
                } while (alignement != false && jetons_alignes != alignement_gagant && l < grille.hauteur - alignement_gagant);
            }

            l++;

        } // Fin de parcours des lignes

        c++;

    } while (alignement != true && c < grille.largeur); // Fin de parcours des colognes

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

void play(Grid grille, char jeton, int c, int size, int winner)
{
    int nb_jetons = 0;
    char choix;
    int retrait;

    // Boucle qui fait jouer les joueurs chacun leur tour
    do{
        // Connaître le joueur qui doit jouer
        // Quand nb_jetons est pair alors c'est au joueur 1 de jouer
        // Quand nb_jetons est impair alors c'est au joueur 2 de jouer
        if(nb_jetons % 2 == 0) {
            jeton = 'O';
            printf("C'est au joueur 1 de jouer \n");
        } else {
            jeton = 'X';
            printf("C'est au joueur 2 de jouer \n");
        }

        // Demande à l'utilisateur le choix qu'il souhaite faire
        if(nb_jetons < 2){
            do {
                printf("Rentrer A si vous vouler ajouter un jeton : \n");
                scanf(" %c", &choix);
                choix = toupper(choix);
            } while (choix != 'A');
        } else {
            do {
                printf("Rentrer A si vous vouler ajouter un jeton et R si vous voulez retirer un jeton : \n");
                scanf(" %c", &choix);
                choix = toupper(choix);
            } while (choix != 'A' && choix != 'R');
        }

        // En fonction du choix fait, lancer la bonne fonction (add_token ou remove_token)
        if(choix == 'R')
        {
            if(nb_jetons != 0){
                do {
                    printf("Dans quelle colonne voulez vous retirer un jeton ?\n");
                    scanf("%d", &c);
                } while (c <= 0 || c > grille.largeur);
                retrait = c;
                remove_token(grille, retrait-1, size+1);
                nb_jetons--;
            }
            else{
                printf("ERREUR, grille vide\n");
            }
        } else if (choix == 'A'){
            printf("Dans quelle colonne voulez vous ajouter un jeton ?\n");
            scanf("%d", &c);
            while (c <= 0 || c > grille.largeur || c == retrait){
                printf("Vous ne pouver pas jouer dans cette colonne "
                       "car le joueur precedent a retirer un jeton");
                printf("Dans quelle colonne voulez vous ajouter un jeton ?\n");
                scanf("%d", &c);
            }
            add_token(grille, c-1, jeton);
            nb_jetons++;
            retrait = 0;
        }

        show_grid(grille);
        winner = check_winner(grille,size);

        printf("\n");

    } while(winner == -1 && nb_jetons < (grille.largeur * grille.hauteur));

    if (winner == 0){
        printf("Le joeur 1 a gagne");
    } else if (winner == 1) {
        printf("Le joeur 2 a gagne");
    } else {
        printf("Match nul");
    }
}

//void IA(Grid grille, int winner, int size, char jetons)
//{
//    int c;
//
//    jetons = 'X';
//
//    while (winner = -1 && c < grille.largeur)
//    {
//        remove_token(grille, c, size +2);
//        add_token(grille, c, jetons);
//        check_winner(grille, size);
//    }
//
//    jetons = 'O';
//
//    while (winner = -1 && c < grille.largeur)
//    {
//        remove_token(grille, c, size +2);
//        add_token(grille, c, jetons);
//        check_winner(grille, size);
//    }
//
//}
