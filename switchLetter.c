#include "header.h"

void switchLetter (t_config *config)
{
    char temp, touche, minuscule; /// La variable ephemere sert � donner au programme le num�ro de la colonne
    int k=0;

    /// Affichage de la lettre selectionn�e en minuscule
    minuscule=config->grid[config->cursy][config->cursx]+('a'-'A');
    printf("%c", minuscule);


    /// Boucle qui se r�p�te tant que le joueur indique des commandes qui sortent du tableau
 do
    {
        fflush(stdin);
        touche=getch();
        switch (touche)
        {
        /// D�placement vers la gauche
        case 'q' : if((config->cursx)>0)
            {
                temp=config->grid[config->cursy][config->cursx];  //ephemere -> config->cursx
                config->grid[config->cursy][config->cursx]=config->grid[config->cursy][config->cursx-1];
                config->grid[config->cursy][config->cursx-1]=temp;
                printGrid(config, config->cursx, config->cursy);
                printGrid(config, config->cursx-1, config->cursy);
                k=1;
            }
            break;

        /// D�placement vers la droite
        case 'd' : if((config->cursx)<(config->gridWidth)-1)
            {
                temp=config->grid[config->cursy][config->cursx];
                config->grid[config->cursy][config->cursx]=config->grid[config->cursy][config->cursx+1];
                config->grid[config->cursy][config->cursx+1]=temp;
                printGrid(config, config->cursx, config->cursy);
                printGrid(config, config->cursx+1, config->cursy);
                k=1;
            }
            break;
        /// D�placement vers le haut
        case 'z' : if((config->cursy)>0)
            {
                temp=config->grid[config->cursy][config->cursx];
                config->grid[config->cursy][config->cursx]=config->grid[config->cursy-1][config->cursx];
                config->grid[config->cursy-1][config->cursx]=temp;
                printGrid(config, config->cursx, config->cursy);
                printGrid(config, config->cursx, config->cursy-1);
                k=1;
            }
            break;
            /// D�placement vers le bas
        case 's' : if((config->cursy)<(config->gridHeight)-1)
            {
                temp=config->grid[config->cursy][config->cursx];
                config->grid[config->cursy][config->cursx]=config->grid[config->cursy+1][config->cursx];
                config->grid[config->cursy+1][config->cursx]=temp;
                printGrid(config, config->cursx, config->cursy);
                printGrid(config, config->cursx, config->cursy+1);
                k=1;
            }
            break;
        case ' ' : k=1;
            config->grid[config->cursy][config->cursx]=minuscule-('a'-'A');
            printGrid(config, config->cursx, config->cursy);
            break;
        }
    } while(k==0);
}




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
