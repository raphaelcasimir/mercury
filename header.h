#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <time.h>


#endif // HEADER_H_INCLUDED
#include <windows.h>

void gotoligcol( int lig, int col ) /// Fonction permettant de placer le pointeur à un endroit
{
COORD mycoord;

mycoord.X = col;
mycoord.Y = lig;
SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );
}

typedef struct config
{
    char** grid;
    int gridHeight,gridWidth,cursy,cursx;
}t_config;

/// Fonctions
void menu();
t_config* configInit(t_config *config);
void printGrid(t_config *config);
int game(t_config *config);
void switchLetter (t_config *config);
void searchPattern (config);
