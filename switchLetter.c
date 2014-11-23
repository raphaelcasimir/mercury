#include "header.h"

void switchLetter (t_config *config)
{
    char temp, touche, minuscule, ephemere; /// La variable ephemere sert � donner au programme le num�ro de la colonne
    int k=0;

    /// Affichage de la lettre selectionn�e en minuscule
    ephemere=(config->cursx/2);
    minuscule=config->grid[config->cursy][ephemere];
    minuscule=minuscule+('a'-'A');
    printf("%c", minuscule);


    /// Boucle qui se r�p�te tant que le joueur indique des commandes qui sortent du tableau
    while(k==0)
    {
        fflush(stdin);
        ephemere=(config->cursx/2);
        touche=getch();
        switch (touche)
        {
        /// D�placement vers la gauche
        case 'q' : if((config->cursx)!=0)
            {
                temp=config->grid[config->cursy][ephemere];  //ephemere -> config->cursx
                config->grid[config->cursy][ephemere]=config->grid[config->cursy][ephemere-1];
                config->grid[config->cursy][ephemere-1]=temp;
                system("cls");
                printGrid(config);
                k=1;
            }
        /// D�placement vers la droite
        case 'd' : if((config->cursx)!=(config->gridWidth))
            {
                temp=config->grid[config->cursy][config->cursx];
                config->grid[config->cursy][config->cursx]=config->grid[config->cursy][config->cursx+1];
                config->grid[config->cursy][config->cursx+1]=temp;
                system("cls");
                printGrid(config);
                k=1;
            }
        /// D�placement vers le haut
        case 'z' : if((config->cursy)!=0)
            {
                temp=config->grid[config->cursy][config->cursx];
                config->grid[config->cursy][config->cursx]=config->grid[config->cursy-1][config->cursx];
                config->grid[config->cursy-1][config->cursx]=temp;
                system("cls");
                printGrid(config);
                k=1;
            }
            /// D�placement vers le bas
        case 's' : if((config->cursx)!=(config->gridHeight))
            {
                temp=config->grid[config->cursy][config->cursx];
                config->grid[config->cursy][config->cursx]=config->grid[config->cursy+1][config->cursx];
                config->grid[config->cursy+1][config->cursx]=temp;
                system("cls");
                printGrid(config);
                k=1;
            }
        case ' ' : k=1;
                config->grid[config->cursy][ephemere]=minuscule-('a'-'A');
        }
    }
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
