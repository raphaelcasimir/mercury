#include "header.h"

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




char fillAlea ()
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
    printf("Level : %d",infos->niveau);

}

void initLevel (t_infos *infos) /// Initialisation des variables propres au niveau
{
    infos->maxF=(infos->niveau)*10+rand()%9; infos->maxM=(infos->niveau)*10+rand()%9; infos->maxO=(infos->niveau)*10+rand()%9; infos->maxP=(infos->niveau)*10+rand()%9; infos->maxS=(infos->niveau)*10+rand()%9;
    infos->contratF=0; infos->contratM=0; infos->contratO=0; infos->contratP=0; infos->contratS=0;
    infos->maxHits=(infos->niveau)*10+4-(2*(infos->niveau));
    infos->hits=0;
}

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
            configInit(config,infos);
            game(config,infos);
        }

    }
    if(infos->vies==0)
    {
        system("cls");
        gotoligcol(5,7);
        printf("GAME OVER");
        Sleep(2000);
        saveAll(config,infos);
        configInit(config,infos);
        infos->vies=5;
        game(config,infos);
    }
}
