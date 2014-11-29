#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <time.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

/// Structures
typedef struct config
{
    char** grid;
    int gridHeight,gridWidth,cursy,cursx;
    FILE* sauvegarde;
}t_config;

typedef struct infos
{
    char *name;
    int score; ///Score actuel
    int fraise, mandarine, oignon, pomme, soleil;
    int multiplicateur;
    int contratF, contratM, contratO, contratP, contratS;
    int maxF, maxM, maxO, maxP, maxS;
    int niveau;
}t_infos;



/// Fonctions
void menu(t_config *config, t_infos *infos);
t_config* configInit(t_config *config, t_infos *infos);
void printGrid(t_config *config, int x, int y);
void game(t_config *config, t_infos *infos);
void switchLetter (t_config *config);
void searchPattern (t_config *config, t_infos *infos, int k);
char fillAlea ();
int menuPause(t_config *config, t_infos *infos);
void contrat(t_config *config, t_infos *infos, char lettre, int nb);

#endif // HEADER_H_INCLUDED
