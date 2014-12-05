#include "header.h"

void switchLevel (t_config *config,t_infos *infos)
{
    if ( (infos->contratF>=infos->maxF)&&(infos->contratM>=infos->maxM)&&(infos->contratO>=infos->maxO)
          &&(infos->contratP>=infos->maxP)&&(infos->contratS>=infos->maxS) )
    {
        system("cls");
        gotoligcol(5,7);
        infos->niveau++;
        printf("NIVEAU %d",infos->niveau);
        Sleep(1500);
        initLevel(infos);
        game(config,infos);
    }
    if((infos->hits)>(infos->maxHits))
    {
        infos->vies--;
        system("cls");
        gotoligcol(5,7);
        printf("Life(s) remaining : %d",infos->vies);
        Sleep(2000);
        if (infos->vies!=0)
        {
            initLevel(infos);
            game(config,infos);
        }

    }
    if(infos->vies==0)
    {
        system("cls");
        gotoligcol(5,7);
        printf("GAME OVER");
        Sleep(2000);
        initLevel(infos);
        saveAll(config,infos);
        configInit(config,infos);
        infos->vies=5;
        game(config,infos);
    }
}

void score (t_infos *infos, int points)
{
    // Calcul du score
    infos->score+=infos->multiplicateur*points;

    //Affichage du score et des contracts
    gotoligcol(0,34);
    printf("Score : %d\n", infos->score);
    gotoligcol(1,34);
    printf("Functions : %d\/%d",infos->contratF,infos->maxF);
    gotoligcol(2,34);
    printf("Processes : %d\/%d",infos->contratP,infos->maxP);
    gotoligcol(3,34);
    printf("Masters   : %d\/%d",infos->contratM,infos->maxM);
    gotoligcol(4,34);
    printf("Origins   : %d\/%d",infos->contratO,infos->maxO);
    gotoligcol(5,34);
    printf("Slices    : %d\/%d",infos->contratS,infos->maxS);
    gotoligcol(7,34);
    printf("ModTokens : %d\/%d",infos->hits,infos->maxHits);
    gotoligcol(8,34);
    printf("Lifes : %d\/5",infos->vies);
    gotoligcol(10,34);
    printf("Level : %d ",infos->niveau);

}

void switchLetter (t_config *config,t_infos *infos)
{
    char temp, touche, minuscule; /// La variable ephemere sert à donner au programme le numéro de la colonne
    int k=0;

    /// Affichage de la lettre selectionnée en minuscule
    minuscule=config->grid[config->cursy][config->cursx]+('a'-'A');
    printf("%c", minuscule);


    /// Boucle qui se répète tant que le joueur indique des commandes qui sortent du tableau
 do
    {
        fflush(stdin);
        touche=getch();
        switch (touche)
        {
        /// Déplacement vers la gauche
        case 'q' : if((config->cursx)>0)
            {
                temp=config->grid[config->cursy][config->cursx];  //ephemere -> config->cursx
                config->grid[config->cursy][config->cursx]=config->grid[config->cursy][config->cursx-1];
                config->grid[config->cursy][config->cursx-1]=temp;
                printGrid(config, config->cursx, config->cursy);
                printGrid(config, config->cursx-1, config->cursy);
                k=1;infos->hits++;
            }
            break;

        /// Déplacement vers la droite
        case 'd' : if((config->cursx)<(config->gridWidth)-1)
            {
                temp=config->grid[config->cursy][config->cursx];
                config->grid[config->cursy][config->cursx]=config->grid[config->cursy][config->cursx+1];
                config->grid[config->cursy][config->cursx+1]=temp;
                printGrid(config, config->cursx, config->cursy);
                printGrid(config, config->cursx+1, config->cursy);
                k=1;infos->hits++;
            }
            break;
        /// Déplacement vers le haut
        case 'z' : if((config->cursy)>0)
            {
                temp=config->grid[config->cursy][config->cursx];
                config->grid[config->cursy][config->cursx]=config->grid[config->cursy-1][config->cursx];
                config->grid[config->cursy-1][config->cursx]=temp;
                printGrid(config, config->cursx, config->cursy);
                printGrid(config, config->cursx, config->cursy-1);
                k=1;infos->hits++;
            }
            break;
            /// Déplacement vers le bas
        case 's' : if((config->cursy)<(config->gridHeight)-1)
            {
                temp=config->grid[config->cursy][config->cursx];
                config->grid[config->cursy][config->cursx]=config->grid[config->cursy+1][config->cursx];
                config->grid[config->cursy+1][config->cursx]=temp;
                printGrid(config, config->cursx, config->cursy);
                printGrid(config, config->cursx, config->cursy+1);
                k=1;infos->hits++;
            }
            break;
        case ' ' : k=1;
            config->grid[config->cursy][config->cursx]=minuscule-('a'-'A');
            printGrid(config, config->cursx, config->cursy);
            break;
        }
    } while(k==0);
}

/// Sous-programme qui met à jour les contrats selon les items supprimés
void contrat(t_config *config, t_infos *infos, char lettre, int nb)
{
    if (lettre=='M') infos->contratM=infos->contratM+nb;

    if (lettre=='O') infos->contratO=infos->contratO+nb;

    if (lettre=='S') infos->contratS=infos->contratS+nb;

    if (lettre=='F') infos->contratF=infos->contratF+nb;

    if (lettre=='P') infos->contratP=infos->contratP+nb;
}


void game(t_config *config, t_infos *infos)
{
    char touche='1';
    int i, j, k=0;
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
    while (searchPattern (config, infos, k)==1)
    {
        gravity(config,infos);
    }
    /// Placement du curseur à la première ligne de la première colonne
    gotoligcol(0,0);

    k=1;
    score(infos,0);
    do
    {
        switchLevel(config,infos);
        if(kbhit())
        {
            touche=getch();
            fflush(stdin);

            switch (touche)
            {
            case 'z' :
                if ((config->cursy)>0)
                    (config->cursy)=(config->cursy)-1;
                    score(infos,0);
                break;

            case 's' :
                if ((config->cursy)<(config->gridHeight)-1)
                (config->cursy)=(config->cursy)+1;
                score(infos,0);
                break;

            case 'q' :
                if ((config->cursx)>0)
                    (config->cursx)=(config->cursx)-1;
                    score(infos,0);
                break;

            case 'd' :
                if ((config->cursx)<(config->gridWidth)-1)
                (config->cursx)=(config->cursx)+1;
                score(infos,0);
                break;

            case ' ' :
                switchLetter (config,infos);
                while (searchPattern (config, infos, k)==1)
                {
                    gravity(config,infos);
                }
                break;

            case 27:
                fflush(stdin);
                i=menuPause(config, infos);
                break;
            }
            gotoligcol(config->cursy,config->cursx*2);
        }

    } while (i!=50);
}
