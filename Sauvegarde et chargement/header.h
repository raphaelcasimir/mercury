#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <time.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/// Structures
typedef struct config
{
    char** grid;
    int gridHeight,gridWidth,cursy,cursx;
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
void menu(t_config *config);
void configInit(t_config *config, t_infos *infos);
void printGrid(t_config *config);
int game(t_config *config);
void switchLetter (t_config *config);
void searchPattern (t_config *config, t_infos *infos);
void saveAll(t_config *config, t_infos *infos);
void loadAll(t_config *config, t_infos *infos);

#endif // HEADER_H_INCLUDED
