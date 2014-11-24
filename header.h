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
}t_config;

typedef struct info
{
    int score; ///Score actuel
    int fraise, mandarine, oignon, pomme, soleil;
    int multiplicateur;
    int contratF, contratM, contratO, contratP, contratS;
    int maxF, maxM, maxO, maxP, maxS;
    int niveau;
}t_info;


/// Fonctions
void menu(t_config *config);
t_config* configInit(t_config *config);
void printGrid(t_config *config, int x, int y);
void game(t_config *config);
void switchLetter (t_config *config);
//void searchPattern (config);
char fillAlea ();
/// int menuPause(t_config *config, t_user *user, t_info *info);

#endif // HEADER_H_INCLUDED
