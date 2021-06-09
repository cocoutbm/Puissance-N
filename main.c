#include <stdio.h>
#include "Jouer.h"
#include "Demarrage_partie.h"
#include "Sauvegarde&chargement.h"

int main() {

    Grid grille;
    char start;
    int player=0;
    char prenom1[100];
    char prenom2[100];
    int size;
    char jeton = 0;
    int c = 0;
    char ligne[100]={0};
    int nb_jetons;
    int retrait = -1;


    printf("\n=============PUISSANCE N============= \n\n");
    //Démarrage du jeu
    start = demarrage();

    switch (start) {
        case 'N': printf("\n=============NOUVELLE PARTIE============= \n\n");
            //Choix de l'adversaire
            player = demarrage_nouvelle_partie(prenom1, prenom2);
            //Choix du nombre de jetons à aligner et définition de la taille de la grille
            size = taille();
            //Initialisation de la grille avec des '_'
            init_grid(&grille, size);
            //Affichage de la grille initialisée
            show_grid(grille);
            printf("\n");
            play(grille, jeton, player, prenom1, prenom2, c, size, 0, retrait);
            break;
        case 'C': printf("\n=============PARTIE EN COURS============= \n\n");
            // Ouverture du fichier
            FILE* fichier = fopen("fichier.txt", "r");
            if(fichier != NULL) {
                fgets(prenom1, 100, fichier);
                fgets(prenom2, 100, fichier);
                fgets(ligne, 100, fichier);
                player =atoi(ligne);
                fgets(ligne, 100, fichier);
                retrait =atoi(ligne);
                fgets(ligne, 100, fichier);
                nb_jetons =atoi(ligne);
                fgets(ligne, 100, fichier);
                size = atoi(ligne);

                init_grid(&grille, size);

                init_grid(&grille, size);

                charger_partie(fichier,grille);
            }
            fclose(fichier);
            show_grid(grille);
            printf("\n\n");
            play(grille, jeton, player, prenom1, prenom2, c, size, nb_jetons, retrait);
            break;
        case 'Q': printf("\n=============FIN DE LA PARTIE============= \n");
            break;
    }
    return 0;
}
