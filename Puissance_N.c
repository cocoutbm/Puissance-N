//
// Created by coco on 30/05/2021.
//

#include "Puissance_N.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>
#include "windows.h"

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
        fflush(stdin);
        lettre = getchar();
        lettre=toupper(lettre);
    }
    return (lettre);
}

int demarrage_nouvelle_partie(char prenom1[], char prenom2[]){
    int adversaire;

    // contrôle sans message d'erreur de l'entrée du joueur
    do{
        printf("*   Jouer a deux => Rentrer 0 : \n*   Jouer contre l'ordinateur => Rentrer 1 : \n");
        scanf("%d",&adversaire);
        fflush(stdin);
    }while(adversaire != 0 && adversaire != 1);
    if (adversaire == 0){
        printf("*   Quel est le nom du premier joueur 1 ?\n");
        fflush(stdin);
        gets(prenom1);
        printf("\n");
        printf("*   Quel est le nom du premier joueur 2 ?\n");
        fflush(stdin);
        gets(prenom2);
        printf("\n");
        printf("    %s a les jetons O et %s a les jetons X\n\n", prenom1, prenom2);
        fflush(stdin);
    }
    else{
        printf("Quel est le nom du premier joueur 1 ?\n");
        fflush(stdin);
        gets(prenom1);
        printf("%s a les jetons O et l'ordinateur a les jetons X \n\n",prenom1);
    }
    return (adversaire);
}


int taille(){
    int alignement_gagnant = 0;

    do {
        printf("*   Quel nombre de jetons voulez vous aligner pour gagner ?\n");
        printf("*   Rentrer un nombre entre 3 et 8 ?\n");
        scanf("%d", &alignement_gagnant);
        fflush(stdin);
    } while (alignement_gagnant < 3 || alignement_gagnant > 8);

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
            if (grille.tableau[l][c] == 'O'){
                Color(14,0);
                printf("%c  ",grille.tableau[l][c]);
                Color(15,0);
            }
            else if(grille.tableau[l][c] == 'X'){
                Color(4,0);
                printf("%c  ",grille.tableau[l][c]);
                Color(15,0);
            }
            else if (grille.tableau[l][c] == '_'){
                Color(15,0);
                printf("%c  ",grille.tableau[l][c]);
                Color(15,0);
            }

        }
        printf("\n");
    }
}

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
        if (test_ordi == false) {
            printf("ERREUR, colonne vide \n");
        }
    }

    return suppression;
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
<<<<<<< HEAD
    char choix_ordi;
=======
>>>>>>> origin/projet


    // Boucle qui fait jouer les joueurs chacun leur tour
    do {
        // Connaître le joueur qui doit jouer
        // Quand nb_jetons est pair alors c'est au joueur 1 de jouer
        // Quand nb_jetons est impair alors c'est au joueur 2 de jouer
        if (nb_jetons % 2 == 0) {
            ordi = false;
            jeton = 'O';
            printf("+   C'est a %s de jouer \n", prenom1);
        } else if (nb_jetons % 2 != 0) {
            if (player == 0) {
                ordi = false;
                jeton = 'X';
                printf("+   C'est a %s de jouer \n", prenom2);
            } else {
                do {
                    printf("Rentrer O pour faire jouer l'ordinateur ou Q pour quitter: \n");
                    scanf(" %c", &choix_ordi);
                    choix_ordi = toupper(choix_ordi);
                } while (choix_ordi != 'O' && choix_ordi != 'Q');

                ordi = true;
                if (choix_ordi == 'O') {
                    printf("+   C'est a l'ordinateur de jouer \n");
                    retrait = computer(grille, size, retrait);
                    nb_jetons++;
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
                if(nb_jetons != 0){
                    do {
                        printf("        /   Dans quelle colonne voulez vous retirer un jeton ?\n");
                        scanf("%d", &c);
                        fflush(stdin);
                    } while (c <= 0 || c > grille.largeur);
                    retrait = c;
                    remove_token(grille, c - 1, false);
                    nb_jetons--;
                }
                else{
                    printf("    .   ERREUR, grille vide\n");
                }
            } else if (choix == 'A'){
                do {
                    printf("        /   Dans quelle colonne voulez vous ajouter un jeton ?\n");
                    scanf("%d", &c);
                    fflush(stdin);
                } while (c <= 0 || c > grille.largeur);
                while (c == retrait){
                    printf("    .   Vous ne pouver pas jouer dans cette colonne "
                           "car le joueur precedent a retirer un jeton \n");
                    printf("        /   Dans quelle colonne voulez vous ajouter un jeton ?\n");
                    scanf("%d", &c);
                    fflush(stdin);
                }
                add_token(grille, c-1, jeton, false);
                nb_jetons++;
                retrait = -1;
            }
        }

        show_grid(grille);
        winner = check_winner(grille,size);

        printf("\n");

    } while(winner == -1 && nb_jetons < (grille.largeur * grille.hauteur) && choix != 'Q' && choix_ordi != 'Q');

<<<<<<< HEAD
    if(choix == 'Q' || choix_ordi == 'Q'){
=======
    if(choix == 'Q'){
>>>>>>> origin/projet
        save(grille, nb_jetons, prenom1, prenom2,player,retrait);
    }

    if (winner == 0){
        printf("=== Le joueur 1 a gagne ===");
    } else if (winner == 1) {
        if (player == 0){
            printf("=== Le joueur 2 a gagne ===");
        } else {
            printf("=== L'ordinateur a gagne ===");
        }
    } else {
        printf("=== Match nul ===");
    }
}

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


void save (Grid grille, int nb_jetons, char prenom1[], char prenom2[],int player, int retrait){
    int l = 0 , h = 0;
    int size = grille.hauteur*grille.largeur;
    FILE* fichier = fopen("fichier.txt", "w");
    if(fichier != NULL){
        fprintf(fichier, "%s\n", prenom1);
        fprintf(fichier, "%s\n", prenom2);
        fprintf(fichier, "%d\n", player);
        fprintf(fichier, "%d\n", retrait);
        fprintf(fichier, "%d\n",nb_jetons);
        fprintf(fichier, "%d\n",grille.hauteur - 2);
        for(l=0;l<grille.largeur;l++){
            for(h=0;h<grille.hauteur;h++){
                fprintf(fichier, "%c\n",grille.tableau[l][h]);
            }
        }
    }
    fclose(fichier);
}


void charger_partie(FILE *fichier, Grid grille) {
    char ligne[100];
    int l, h, taille;
    int size = grille.hauteur * grille.largeur;


    for (l = 0; l < grille.largeur; l++) {
        for (h = 0; h < grille.hauteur; h++) {
            fgets(&grille.tableau[l][h], 10, fichier);
        }
    }
}


void Color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}
