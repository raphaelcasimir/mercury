#include "header.h"

//fmod musique

void gotoligcol( int lig, int col ) /// Fonction permettant de placer le pointeur � un endroit
{
COORD mycoord;

mycoord.X = col;
mycoord.Y = lig;
SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );
}

void menu(t_config *config, t_info *info) /// Il s'agit du menu qui permettra de modifier les param�tres du jeu comme charger une partie ou en cr�er une nouvelle
{
    int choice;

    printf("1. Nouvelle partie\n2. Charger partie\n3. Reprendre de la derni\212re partie\n4. Options\n5. Quitter\n");

    fflush(stdin);
    scanf("%d",&choice);
    switch (choice)
    {
    default :
        game(config, info);
    }
}

t_config* configInit(t_config *config) /// Initialisation de la structure t_config, contenant toutes les infos personnalisables et la grille de jeu.
{
    config=(t_config*)malloc(sizeof(t_config));

    config->gridHeight=10; /// A retirer ensuite
    config->gridWidth=15;

    config->cursy=0;
    config->cursx=0;

    int i,j,x;

    config->grid=(char**)malloc( (config->gridHeight)*sizeof(char*) );


     for (i=0; i<(config->gridHeight); i++)
    {
            config->grid[i]=(char*)malloc(config->gridWidth*sizeof(char));
    }/// Fin de la cr�ation en m�moire de la grille

    /// Remplissage de la grille
    for (i=0; i<(config->gridHeight); i++)
    {
        for (j=0; j<(config->gridWidth); j++)
        {
        /// G�n�ration d'un nombre al�atoire entre 0 et 4
        x=rand()%5;
        /// Remplacement de la grille par le caract�re correspondant au nombre g�n�r�
        if(x==0) config->grid[i][j]='P';
        if(x==1) config->grid[i][j]='M';
        if(x==2) config->grid[i][j]='O';
        if(x==3) config->grid[i][j]='S';
        if(x==4) config->grid[i][j]='F';
        }
    }
    return config;
}


void game(t_config *config, t_info *info)
{
    char touche='1';
    int i, j;
    config=configInit(config); /// Initialisation de la configuration du jeu
    system("cls");

    /// Affichage de la matrice initialis�e
    for(j=0; j<(config->gridHeight); j++)
    {
        for(i=0; i<(config->gridWidth); i++)
        {
            printGrid(config, i, j);
        }
        printf("\n");
    }
    /// Placement du curseur � la premi�re ligne de la premi�re colonne
    gotoligcol(0,0);

    do
    {
            touche=getch();

            switch (touche)
            {
            case 'z' :
                if ((config->cursy)>0)
                    (config->cursy)=(config->cursy)-1;
                break;

            case 's' :
                if ((config->cursy)<(config->gridHeight)-1)
                (config->cursy)=(config->cursy)+1;
                break;

            case 'q' :
                if ((config->cursx)>0)
                    (config->cursx)=(config->cursx)-1;
                break;

            case 'd' :
                if ((config->cursx)<(config->gridWidth)-1)
                (config->cursx)=(config->cursx)+1;
                break;

            case ' ' :
                switchLetter (config);
                //searchPattern (config);
                break;

            case 27:
                touche=menuPause(config, info);
                if(touche==1)
                {
                    system("cls");

                    /// R�-affichage de la matrice
                    for(j=0; j<(config->gridHeight); j++)
                    {
                        for(i=0; i<(config->gridWidth); i++)
                        {
                            printGrid(config, i, j);
                        }
                    printf("\n");

                    }
                }
            }
            gotoligcol(config->cursy,config->cursx*2);
    } while (touche!=127);
}


int main()
{
    t_config *config;
    t_info *info;
    int i,j;
    srand(time(NULL));

    printf("gameMatrix\n\n");
    menu(config, info);
    return 0;
}
