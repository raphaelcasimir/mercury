#include "header.h"

void initLevel (t_infos *infos) /// Initialisation des variables propres au niveau
{
    infos->maxF=(infos->niveau)*10+rand()%9; infos->maxM=(infos->niveau)*10+rand()%9; infos->maxO=(infos->niveau)*10+rand()%9; infos->maxP=(infos->niveau)*10+rand()%9; infos->maxS=(infos->niveau)*10+rand()%9;
    infos->contratF=0; infos->contratM=0; infos->contratO=0; infos->contratP=0; infos->contratS=0;
    infos->maxHits=(infos->niveau)*10+4-(2*(infos->niveau));
    infos->hits=0;
}

void configInit(t_config *config, t_infos *infos) /// Initialisation de la structure t_config, contenant toutes les infoss personnalisables et la grille de jeu.
{

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
    infos->multiplicateur=0;infos->hits=0;infos->maxHits=0;


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
    initLevel(infos);
}
