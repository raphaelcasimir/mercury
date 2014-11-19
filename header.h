#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <time.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

<<<<<<< HEAD

void gotoligcol( int lig, int col ) /// Fonction permettant de placer le pointeur à un endroit
{
COORD mycoord;

mycoord.X = col;
mycoord.Y = lig;
SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );
}

=======
/// Structures
>>>>>>> 0f2ec7e126445227bd819fb9d15ad2bf71f4c5ed
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
