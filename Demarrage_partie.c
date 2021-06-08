//
// Created by coco on 02/06/2021.
//

#include "Demarrage_partie.h"
#include "Jouer.h"
#include <stdio.h>
#include <ctype.h>
#include "windows.h"

void Color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}

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
    char jeton1 = 'O';
    char jeton2 = 'X';

    // contrôle sans message d'erreur de l'entrée du joueur
    do{
        printf("*   Jouer a deux => Rentrer 0 : \n*   Jouer contre l'ordinateur en mode difficile => Rentrer 1 : \n*   Jouer contre l'ordianateur en mode facile => Rentrer 2 : \n");
        adversaire = saisie_int();
    }while(adversaire != 0 && adversaire != 1 && adversaire != 2);
    if (adversaire == 0){   // adversaire == 1
        // Demande du nom du premier joueur
        printf("*   Quel est le nom du premier joueur 1 ?\n");
        fflush(stdin);
        gets(prenom1);
        printf("\n");
        // Demande du nom du deuxième joueur
        printf("*   Quel est le nom du premier joueur 2 ?\n");
        fflush(stdin);
        gets(prenom2);
        printf("\n");
        Color(14,0);
        printf("    %s ", prenom1);
        Color(15,0);
        printf("a les jetons");
        Color(14,0);
        printf(" %c ", jeton1);
        Color(15,0);
        printf("et ");
        Color(4,0);
        printf("%s ", prenom2);
        Color(15,0);
        printf("a les jetons ");
        Color(4,0);
        printf(" %c \n\n", jeton2);
        Color(15,0);
        fflush(stdin);
    }
    else if(adversaire == 1){   // adversaire == 1
        // Demande du nom du joueur
        printf("Quel est le nom du joueur ?\n");
        fflush(stdin);
        gets(prenom1);
        Color(14,0);
        printf("    %s ", prenom1);
        Color(15,0);
        printf("a les jetons");
        Color(14,0);
        printf(" %c ", jeton1);
        Color(15,0);
        printf("et ");
        Color(4,0);
        printf("l'ordinateur");
        Color(15,0);
        printf(" a les jetons");
        Color(4,0);
        printf(" %c \n\n", jeton2);
        Color(15,0);
    }
    else if(adversaire == 2){   // adversaire == 1
        // Demande du nom du joueur
        printf("Quel est le nom du joueur ?\n");
        fflush(stdin);
        gets(prenom1);
        Color(14,0);
        printf("    %s ", prenom1);
        Color(15,0);
        printf("a les jetons");
        Color(14,0);
        printf(" %c ", jeton1);
        Color(15,0);
        printf("et ");
        Color(4,0);
        printf("l'ordinateur");
        Color(15,0);
        printf(" a les jetons");
        Color(4,0);
        printf(" %c \n\n", jeton2);
        Color(15,0);
    }
    return (adversaire);
}

int taille() {
    int alignement_gagnant = 0;

    // Contrôle si la saisie de l'alignement gagnant est bien comprise entre 3 et 8
    do {
        printf("*   Quel nombre de jetons voulez vous aligner pour gagner ?\n");
        printf("*   Rentrer un nombre entre 3 et 8 ?\n");
        alignement_gagnant = saisie_int();
    } while (alignement_gagnant < 3 || alignement_gagnant > 8);

    // Affichage de la taille de la grille
    printf("\n  la taille du tableau est donc de %d par %d\n\n", alignement_gagnant + 2, alignement_gagnant + 2);

    return alignement_gagnant;
}
