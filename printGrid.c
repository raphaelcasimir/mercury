#include "header.h"

///Sous-programme d'affichage case par case

void printGrid(t_config *config, int x, int y)
{
    gotoligcol(y,x*2);
    printf("%c ", config->grid[y][x]);
}

/// Sous-programme d'affichage du menu pendant le jeu
/* int menuPause(t_config *config, t_user *user, t_info *info)
{
    int k, touche;
    system("cls");
    printf("Menu Pause :\n1. Sauvergarder partie \n2. Charger partie sauvergardee \n3. Options \n4. Retour \n5. Quitter jeu");
    scanf("%d", &touche);
    switch(touche)
    {
        /// case '1' : void save (config, user, info);

        /// case '2' : void load (config, user, info);

        /// case '3' : void menuOptions(t_user *user);

        case '4' : k=1;

        case '5' : k=0;
    }
    return k;
}
*/

