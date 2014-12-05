#include "header.h"
#include <curses.h>

void init_pdcurses_color() // Initialialisation des couleurs pdcurses
{

    start_color();

    init_pair(1, COLOR_RED,     COLOR_BLACK);
    init_pair(2, COLOR_GREEN,   COLOR_BLACK);
    init_pair(3, COLOR_YELLOW,  COLOR_BLACK);
    init_pair(4, COLOR_BLUE,    COLOR_BLACK);
    init_pair(5, COLOR_CYAN,    COLOR_BLACK);
    init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(7, COLOR_WHITE,   COLOR_BLACK);
  }

char fillAlea () /// Génération d'un caractère aléatoire dans les bonnes bornes
{
    int x;
    /// Génération d'un nombre aléatoire entre 0 et 4
    x=rand()%5;
    /// Remplacement de la grille par le caractère correspondant au nombre généré
    if(x==0) x='P';
    if(x==1) x='M';
    if(x==2) x='O';
    if(x==3) x='S';
    if(x==4) x='F';
    /// Renvoi d'un caractère
    return(x);
}

void gotoligcol( int lig, int col ) /// Fonction permettant de placer le pointeur à un endroit, j'aime apprendre des choses aux gens.
{
COORD mycoord;

mycoord.X = col;
mycoord.Y = lig;
SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );
}

void score (t_infos *infos, int points) /// Affiche les scores à droite de la matrice
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Calcul du score
    infos->score+=infos->multiplicateur*points;

    //Affichage du score et des contracts
    gotoligcol(0,34);
    printf("Score : %d\n", infos->score);

/// On donne un indicateur pour chaque valeur : si c'est rouge c'est dangereux, si c'est vert, c'est le bien, et si c'est jaune... C'est jaune.
    gotoligcol(1,34);
    printf("Functions : ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED);
    if (( ( ((float)infos->contratF)/infos->maxF)>=0.75) && (((float)infos->contratF)/infos->maxF)<1)
        SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN); // Jaune
    if (( ((float)infos->contratF)/infos->maxF) >=1)
        SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
    printf("%d\/%d",infos->contratF,infos->maxF);
    SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Blanc

    gotoligcol(2,34);
    printf("Processes : ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED);
    if (( ( ((float)infos->contratP)/infos->maxP)>=0.75) && (((float)infos->contratP)/infos->maxP)<1)
        SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN); // Jaune
    if (( ((float)infos->contratP)/infos->maxP) >=1)
        SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
    printf("%d\/%d",infos->contratP,infos->maxP);
    SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Blanc

    gotoligcol(3,34);
    printf("Masters   : ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED);
    if (( ( ((float)infos->contratM)/infos->maxM)>=0.75) && (((float)infos->contratM)/infos->maxM)<1)
        SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN); // Jaune
    if (( ((float)infos->contratM)/infos->maxM) >=1)
        SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
    printf("%d\/%d",infos->contratM,infos->maxM);
    SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Blanc

    gotoligcol(4,34);
    printf("Origins   : ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED);
    if (( ( ((float)infos->contratO)/infos->maxO)>=0.75) && (((float)infos->contratO)/infos->maxO)<1)
        SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN); // Jaune
    if (( ((float)infos->contratO)/infos->maxO) >=1)
        SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
    printf("%d\/%d",infos->contratO,infos->maxO);
    SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Blanc

    gotoligcol(5,34);
    printf("Slices    : ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED);
    if (( ( ((float)infos->contratS)/infos->maxS)>=0.75) && (((float)infos->contratS)/infos->maxS)<1)
        SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN); // Jaune
    if (( ((float)infos->contratS)/infos->maxS) >=1)
        SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
    printf("%d\/%d",infos->contratS,infos->maxS);
    SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Blanc

    gotoligcol(7,34);
    printf("ModTokens : ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Blanc
    if (( ( ((float)infos->hits)/infos->maxHits)>=0.75))
        SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED); // Rouge
    printf("%d\/%d",infos->hits,infos->maxHits);
    SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Blanc

    gotoligcol(8,34);
    printf("Lifes : ");
    if ( ( (infos->vies)<=1))
        SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED); // Rouge
    printf("%d\/5",infos->vies);
    SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Blanc

    gotoligcol(10,34);
    printf("Level : %d ",infos->niveau);

}

///Sous-programme d'affichage case par case
void printGrid(t_config *config, int x, int y)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    gotoligcol(y,x*2);
    switch (config->grid[y][x])
    {
    case 'M' :
        SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN); // Jaune
        break;
    case 'P' :
        SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_BLUE); // Bleu
        break;
    case 'S' :
        SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED); // Rouge
        break;
    case 'O':
        SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_GREEN); // Vert
        break;
    case 'F':
        SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY ); // Gris
        break;

    }

    printf("%c ", config->grid[y][x]);
    SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Blanc
}

void gravity (t_config *config,t_infos *infos) /// Fonction donnant un style "matrix" (ou gravité si on le fait tourner au ralenti)
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
        /// Réimpression de la grille à chaque descente de 1 case pour avoir une impression de gravité
        for(x=0; x<(config->gridHeight); x++)
        {
            for(y=0; y<(config->gridWidth); y++)
            {
                printGrid(config, y, x);
            }
            printf("\n");
        }
            Sleep(60); /// Attendre un peu pour créer une impression de mouvement visible
    }


}
