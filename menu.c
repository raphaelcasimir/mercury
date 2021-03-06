#include "header.h"

/// Il s'agit du menu qui permettra de modifier les param�tres du jeu comme charger une partie ou en cr�er une nouvelle
void menu(t_config *config, t_infos *infos)
{
    char choice;

    printf("1. Nouvelle partie\n2. Charger partie\n3. Options\n4. Quitter\n");

    fflush(stdin);
    scanf("%c",&choice);
    switch (choice)
    {
    case '1':
        system("cls");
        printf("Utilisez z,q,s,d pour vous d\202placer et espace pour s\202lectionner");
        Sleep(2000);
        game(config,infos);
        fflush(stdin);
        break;
    case '2': // Appel du sspgrm de chargement
        loadAll(config,infos);
        game(config,infos);
        fflush(stdin);
        break;
    case '3':
        //menuOptions(config,infos);
        break;
    case '4':
        break;
    }
}


/// Sous-programme d'affichage du menu pendant le jeu
int menuPause(t_config *config, t_infos *infos)
{
    int k=95, touche;
    system("cls");
    printf("Menu Pause :\n\n1. Sauvergarder partie \n2. Charger partie sauvergard\202e \n3. Options \n4. Retour \n5. Nouvelle partie \n6. Quitter jeu\n");
    fflush(stdin);
    do{
        if (kbhit())
    {
        touche=getch();
    }

    switch(touche)
    {
         case '1' :
            saveAll (config, infos);
            game(config,infos);
            k=50;
            break;

        case '2' :
            loadAll (config, infos);
            game(config,infos);
            k=50;
            break;

        //case '3' : void menuOptions(infos);
            //break;


        case '4' :
            k=50;
            game(config,infos);
            break;

        case '5' : // Nouvelle partie
            configInit(config,infos);
            infos->vies=5;
            game(config,infos);
            break;

        case '6' : // Quitter
            system("cls");
            fflush(stdin);
            printf("Merci d'avoir jou\202 !\n");
            Sleep(1500);
            k=50;
            break;
        case 27 : // Quand on appuye sur �chap
            k=50;
            game(config,infos);
            break;
    }
    }while(k!=50);
    return k;
}
