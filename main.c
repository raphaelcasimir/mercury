#include "header.h"

//fmod musique

void gotoligcol( int lig, int col ) /// Fonction permettant de placer le pointeur à un endroit
{
COORD mycoord;

mycoord.X = col;
mycoord.Y = lig;
SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );
}

void menu(t_config *config) /// Il s'agit du menu qui permettra de modifier les paramètres du jeu comme charger une partie ou en créer une nouvelle
{
    int choice;

    printf("1. Nouvelle partie\n2. Charger partie\n3. Sauvegarder parie\n4. Reprendre de la derni\212re partie\n5. Options\n6. Quitter\n");

    fflush(stdin);
    scanf("%d",&choice);
    switch (choice)
    {
    default :
        config=configInit(config); /// Initialisation de la configuration du jeu
        game(config);
    }
}

t_config* configInit(t_config *config) /// Initialisation de la structure t_config, contenant toutes les infos personnalisables et la grille de jeu.
{
    config=(t_config*)malloc(sizeof(t_config));

    config->gridHeight=10; /// A retirer ensuite
    config->gridWidth=15;

    config->cursy=0;
    config->cursx=0;

    int i,j;

    config->grid=(char**)malloc( (config->gridHeight)*sizeof(char*) );


     for (i=0; i<(config->gridHeight); i++)
    {
            config->grid[i]=(char*)malloc(config->gridWidth*sizeof(char));
    }// Fin de la création en mémoire de la grille

    for (i=0; i<(config->gridHeight); i++)// Remplissage de la grille
    {
        for (j=0; j<(config->gridWidth); j++)
            config->grid[i][j]=(rand()%('E'-'A') +'A');
    }
    return config;
}

void printGrid(t_config *config) /// Sous-programme d'affichage à refaire
{
    int i,j;

        for (i=0; i<(config->gridHeight); i++)
    {
        for (j=0; j<(config->gridWidth); j++)
            printf("%c ",config->grid[i][j]);
        printf("\n");
    }
}

int game(t_config *config)
{
    char touche='1';

    system("cls");
    printGrid(config); /// Affichage de la grille
    gotoligcol(config->cursy,config->cursx);

    do
    {
        if (kbhit())
        {
            touche=getch();

            switch (touche)
            {
            case 'z' :
                if ((config->cursy-1)>=0)
                    (config->cursy)=(config->cursy)-2;
                break;

            case 's' :
                if ((config->cursy+1)<=(2*(config->gridHeight)-2))
                (config->cursy)=(config->cursy)+2;
                break;

            case 'q' :
                if ((config->cursx-1)>=0)
                    (config->cursx)=(config->cursx)-2;
                break;

            case 'd' :
                if ((config->cursx+1)<=(2*(config->gridWidth)-2))
                (config->cursx)=(config->cursx)+2;
                break;

            case ' ' :
                switchLetter (config);
                //searchPattern (config);
            }
            gotoligcol(config->cursy,config->cursx);
        }
    }

    while (touche!=27);
}

void switchLetter (t_config *config)
{
    char temp;
    if ((config->cursx)!=0)
    {
        temp=config->grid[config->cursy][config->cursx];
        config->grid[config->cursy][config->cursx]=config->grid[config->cursy][config->cursx-1];
        config->grid[config->cursy][config->cursx-1]=temp;
        system("cls");
        printGrid(config);
    }

    else
        {
            temp=config->grid[config->cursy][config->cursx];
            config->grid[config->cursy][config->cursx]=config->grid[config->cursy][config->cursx+1];
            config->grid[config->cursy][config->cursx+1]=temp;
            system("cls");
            printGrid(config);
        }

}
int main()
{
    t_config *config;
    int i,j;
    srand(time(NULL));

    printf("gameMatrix\n");
    menu(&config);
    return 0;
}
