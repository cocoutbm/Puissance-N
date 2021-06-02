cmake_minimum_required(VERSION 3.17)
project(ifb_projet C)

set(CMAKE_C_STANDARD 99)

add_executable(ifb_projet main.c Jouer.c Jouer.h Demarrage_partie.c Demarrage_partie.h IA.c IA.h Sauvegarde&chargement.c Sauvegarde&chargement.h Grille.c Grille.h)