#include "header.h"

///Sous-programme d'affichage case par case

void printGrid(t_config *config, int x, int y)
{
    gotoligcol(y,x*2);
    printf("%c ", config->grid[y][x]);
}

/// Sous-programme d'affichage du menu pendant le jeu
int menuPause(t_config *config, t_info *info)
{
    int k=0, l, touche;
    system("cls");
    printf("Menu Pause :\n\n1. Sauvergarder partie \n2. Charger partie sauvergardee \n3. Options \n4. Retour \n5. Quitter jeu\n");
    do{
        fflush(stdin);
    touche=getch();
    switch(touche)
    {
        /* case '1' : void save (config, info);
            break;

        case '2' : void load (config, info);
            break;

        case '3' : void menuOptions(info);
            break;
            */

        case '4' : k=1;
            break;

        case '5' : k=127;
            system("cls");
            printf("Merci d'avoir joue !\n");
            break;
    }
    }while(k==0);
    return k;
}


