#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <time.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
//#include <curses.h>

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
    int multiplicateur;
    int contratF, contratM, contratO, contratP, contratS;
    int maxF, maxM, maxO, maxP, maxS;
    int niveau,hits,maxHits;
}t_infos;



/// Fonctions
void menu(t_config *config, t_infos *infos);
void configInit(t_config *config, t_infos *infos);
void printGrid(t_config *config, int x, int y);
void game(t_config *config, t_infos *infos);
void switchLetter (t_config *config,t_infos *infos);
int searchPattern (t_config *config, t_infos *infos, int k);
char fillAlea ();
int menuPause(t_config *config, t_infos *infos);
void contrat(t_config *config, t_infos *infos, char lettre, int nb);
void loadAll(t_config *config, t_infos *infos);
void saveAll(t_config *config, t_infos *infos);
void gotoligcol( int lig, int col );
void score(t_infos *infos, int points);

#endif // HEADER_H_INCLUDED
