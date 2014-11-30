#include "header.h"

//fmod musique

void gotoligcol( int lig, int col ) /// Fonction permettant de placer le pointeur à un endroit
{
COORD mycoord;

mycoord.X = col;
mycoord.Y = lig;
SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );
}

void menu(t_config *config, t_infos *infos) /// Il s'agit du menu qui permettra de modifier les paramètres du jeu comme charger une partie ou en créer une nouvelle
{
    int choice;

    printf("1. Nouvelle partie\n2. Charger partie\n3. Reprendre de la derni\212re partie\n4. Options\n5. Quitter\n");

    fflush(stdin);
    scanf("%d",&choice);
    switch (choice)
    {
    default :
        game(config, infos);
    }
}

t_config* configInit(t_config *config, t_infos *infos) /// Initialisation de la structure t_config, contenant toutes les infoss personnalisables et la grille de jeu.
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
    }/// Fin de la création en mémoire de la grille

    infos->name=NULL;
    infos->score=0; infos->niveau=1; infos->maxF=0; infos->maxM=0; infos->maxO=0; infos->maxP=0;
    infos->maxS=0; infos->contratF=0; infos->contratM=0; infos->contratO=0; infos->contratP=0; infos->contratS=0;
    infos->multiplicateur=0; infos->fraise=0; infos->mandarine=0; infos->oignon=0; infos->pomme=0; infos->soleil=0;


    /// Remplissage de la grille
    for (i=0; i<(config->gridHeight); i++)
    {
        for (j=0; j<(config->gridWidth); j++)
        {
        /// Génération d'un nombre aléatoire entre 0 et 4
        x=rand()%5;
        /// Remplacement de la grille par le caractère correspondant au nombre généré
        if(x==0) config->grid[i][j]='P';
        if(x==1) config->grid[i][j]='M';
        if(x==2) config->grid[i][j]='O';
        if(x==3) config->grid[i][j]='S';
        if(x==4) config->grid[i][j]='F';
        }
    }
    return config;
}



void game(t_config *config, t_infos *infos)
{
    char touche='1';
    int i, j, k=0;
    config=configInit(config, infos); /// Initialisation de la configuration du jeu
    system("cls");

    /// Affichage de la matrice initialisée
    for(j=0; j<(config->gridHeight); j++)
    {
        for(i=0; i<(config->gridWidth); i++)
        {
            printGrid(config, i, j);
        }
        printf("\n");
    }
    /// Placement du curseur à la première ligne de la première colonne
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
                searchPattern (config, infos, k);
                k++;
                break;

            case 27:
                touche=menuPause(config, infos);
                if(touche==1)
                {
                    system("cls");

                    /// Ré-affichage de la matrice
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
    t_infos *infos;
    int i,j;
    srand(time(NULL));

    printf("gameMatrix\n\n");
    menu(config, infos);

    return 0;
}
