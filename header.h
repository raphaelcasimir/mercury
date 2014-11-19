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


/// Fonctions
void menu(t_config *config);
t_config* configInit(t_config *config);
void printGrid(t_config *config);
int game(t_config *config);
void switchLetter (t_config *config);
void searchPattern (config);

#endif // HEADER_H_INCLUDED
