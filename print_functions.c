#include "header.h"

char fillAlea ()
{
    int x;
    /// G�n�ration d'un nombre al�atoire entre 0 et 4
    x=rand()%5;
    /// Remplacement de la grille par le caract�re correspondant au nombre g�n�r�
    if(x==0) x='P';
    if(x==1) x='M';
    if(x==2) x='O';
    if(x==3) x='S';
    if(x==4) x='F';
    /// Renvoi d'un caract�re
    return(x);
}

void gotoligcol( int lig, int col ) /// Fonction permettant de placer le pointeur � un endroit
{
COORD mycoord;

mycoord.X = col;
mycoord.Y = lig;
SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );
}

///Sous-programme d'affichage case par case

void printGrid(t_config *config, int x, int y)
{
    gotoligcol(y,x*2);
    printf("%c ", config->grid[y][x]);
}

void gravity (t_config *config,t_infos *infos)
{
    int x, y, k=1;
    while (k==1)
    {
        k=0;
        for (x=0;x<config->gridWidth; x++)
        {
            if(config->grid[0][x]==' ')
                config->grid[0][x]=fillAlea();
        }
        for (y=1;y<config->gridHeight; y++)
        {
            for (x=0;x<config->gridWidth; x++)
            {
                if (config->grid[y][x]==' ')
                {
                    config->grid[y][x]=config->grid[y-1][x];
                    config->grid[y-1][x]=' ';
                    k=1;
                }
            }
        }
        /// R�impression de la grille � chaque descente de 1 case pour avoir une impression de gravit�
        for(x=0; x<(config->gridHeight); x++)
        {
            for(y=0; y<(config->gridWidth); y++)
            {
                printGrid(config, y, x);
            }
            printf("\n");
        }
            Sleep(60); /// Attendre un peu pour cr�er une impression de mouvement visible
    }


}
