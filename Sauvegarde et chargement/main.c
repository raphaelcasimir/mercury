#include "header.h"
#include <curses.h>

void gotoligcol( int lig, int col ) /// Fonction permettant de placer le pointeur à un endroit
{
COORD mycoord;

mycoord.X = col;
mycoord.Y = lig;
SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );
}

void configInit(t_config *config, t_infos *infos) /// Initialisation de la structure t_config, contenant toutes les infos personnalisables et la grille de jeu.
{


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

    infos->name=NULL;
    infos->score=0; infos->niveau=1; infos->maxF=0; infos->maxM=0; infos->maxO=0; infos->maxP=0;
    infos->maxS=0; infos->contratF=0; infos->contratM=0; infos->contratO=0; infos->contratP=0; infos->contratS=0;
    infos->multiplicateur=0; infos->fraise=0; infos->mandarine=0; infos->oignon=0; infos->pomme=0; infos->soleil=0;
}
void saveAll (t_config *config, t_infos *infos)//t_config *config, t_user *user, t_infos *infos
{
    FILE *save;
    char file[23],*username,*tempname,niveau=1;
    int i=1,j=0;

    system("cls");
    refresh();

    printf("S\202lectionnez un emplacement de sauvegarde :\n");

    for (i=1; i<6; i++)
    {
        sprintf(file,"save_files\\save_%d.mcy",i);

        printf("\n( ) Emplacement %d ",i);
        save=fopen(file,"r");

        if (save==NULL)
        {
            system("COLOR 2");
            printf("vide\n");
            system("COLOR 7");
        }

        else
        {
            /// Blindage de récupération du nom dans le fichier
            tempname=(char*)malloc(150*sizeof(char));

            fscanf(save,"%s",tempname); // Récupération du nom

            username=(char*)malloc((strlen(tempname)+1)*sizeof(char));
            strcpy(username,tempname);
            free(tempname);

            fscanf(save," niveau=%d, %d",&niveau,&j); // Récupération du niveau
            system("COLOR C");
            printf(": %s, niveau %d - %d points\n", username, niveau, j); // Affichage du contenu de l'emplacement
            system("COLOR 7");
            fclose(save);
        }
    }
    j=2;
    gotoligcol(j,1);
    printf("*");
    gotoligcol(j,1);

    while(i!=27) // Boucle de choix de l'emplacement de sauvegarde
    {
            if(kbhit())
            {
                i=getch();

                switch (i)
                {
                case KEY_DOWN :
                    printf(" ");
                    j=(j)%10+2;
                    gotoligcol(j,1);
                    printf("*");
                    gotoligcol(j,1);

                    break;

                case KEY_UP :
                    printf(" ");
                    j=j-2;
                    if (j==0)
                        j=10;
                    gotoligcol(j,1);
                    printf("*");
                    gotoligcol(j,1);
                    break;

                case 13 :

                    gotoligcol(12,0);
                    j=j/2;
                    printf("Etes vous s\226r de vouloir \202crire \205 l'emplacement %d ? (y/n) ", j);

                    fflush(stdin);
                    scanf("%c",&username[0]);
                    if(username[0]=='n')
                        {
                            saveAll(config,infos); // Relancer le programme de sauvegarde pour avoir de nouveau les choix
                            i=27;
                            break;
                        }
                    sprintf(file,"save_files\\save_%d.mcy",j);

                    save=fopen(file,"w");
                    if(save==NULL)
                    {
                        system("COLOR C");
                        printf("\n\aProbleme d'initialisation fichier de sauvegarde\n"); // "Blindage" d'ouverture de fichier
                        Sleep(1500);
                        system("COLOR 7");
                        i=27;
                        break;
                    }

                    system("cls");

                    if((infos->name)==NULL)
                    {
                        printf("Entrez votre nom : ");

                        /// Blindage de saisie du nom à retirer si nécessaire (on peut demander le nom au début)
                        tempname=(char*)malloc(150*sizeof(char));
                        fflush(stdin);
                        gets(tempname); // Récupération du nom

                        for (i=0; i<(strlen(tempname)); i++)
                        {
                            if(tempname[i]==' ')
                                tempname[i]='_';
                        }

                        (infos->name)=(char*)malloc((strlen(tempname)+1)*sizeof(char));

                        strcpy((infos->name),tempname);
                        free(tempname);

                    }


                    fprintf(save,"%s niveau=%d, %d points\n%d %d %d %d %d\n%d\n%d %d %d %d %d",infos->name,infos->niveau,infos->score , infos->maxF, infos->maxM, infos->maxO, infos->maxP, infos->maxS, infos->contratF, infos->contratM, infos->contratO, infos->contratP, infos->contratS, infos->multiplicateur, infos->fraise, infos->mandarine, infos->oignon, infos->pomme, infos->soleil);
                    fprintf(save,"\nHeight=%d, Width=%d, cursx=%d, cursy=%d\nnumverif=42",config->gridHeight,config->gridWidth,config->cursx,config->cursy);

                    fprintf(save,"\n\n");
                    for (i=0; i<(config->gridHeight); i++)
                        {
                            for (j=0; j<(config->gridWidth); j++)
                                fprintf(save,"%c ",config->grid[i][j]);
                            fprintf(save,"\n");
                        }

                    system("cls");
                    printf("Partie sauvegard\202e");
                    Sleep(1500);
                    i=27;
                    break;
                }
            }
    }
    fclose(save);
}

void loadAll(t_config *config, t_infos *infos)
{
    FILE *save;
    char file[23],*username,*tempname,niveau=1;
    int i=1,j=0;

    system("cls");
    refresh();

    printf("S\202lectionnez un emplacement \205 charger :\n");

    for (i=1; i<6; i++)
    {
        sprintf(file,"save_files\\save_%d.mcy",i);

        printf("\n( ) Emplacement %d ",i);
        save=fopen(file,"r");

        if (save==NULL)
        {
            system("COLOR 2");
            printf("vide\n");
            system("COLOR 7");
        }

        else
        {
            /// Blindage de récupération du nom dans le fichier
            tempname=(char*)malloc(150*sizeof(char));

            fscanf(save,"%s",tempname); // Récupération du nom

            username=(char*)malloc((strlen(tempname)+1)*sizeof(char));
            strcpy(username,tempname);
            free(tempname);

            fscanf(save," niveau=%d, %d",&niveau,&j); // Récupération du niveau
            system("COLOR C");
            printf(": %s, niveau %d - %d points\n", username, niveau, j); // Affichage du contenu de l'emplacement
            system("COLOR 7");
            fclose(save);
        }
    }
    j=2;
    gotoligcol(j,1);
    printf("*");
    gotoligcol(j,1);

    while(i!=27) // Boucle de choix de l'emplacement de sauvegarde
    {
            if(kbhit())
            {
                i=getch();

                switch (i)
                {
                case KEY_DOWN :
                    printf(" ");
                    j=(j)%10+2;
                    gotoligcol(j,1);
                    printf("*");
                    gotoligcol(j,1);

                    break;

                case KEY_UP :
                    printf(" ");
                    j=j-2;
                    if (j==0)
                        j=10;
                    gotoligcol(j,1);
                    printf("*");
                    gotoligcol(j,1);
                    break;

                case 13 :

                    gotoligcol(12,0);
                    j=j/2;
                    printf("Etes vous s\226r de vouloir charger le contenu de l'emplacement %d ? (y/n) ", j);

                    fflush(stdin);
                    scanf("%c",&username[0]);
                    if(username[0]=='n')
                        {
                            saveAll(config,infos); // Relancer le programme de sauvegarde pour avoir de nouveau les choix
                            i=27;
                            break;
                        }

                    sprintf(file,"save_files\\save_%d.mcy",j);

                    save=fopen(file,"r");
                    if(save==NULL)
                    {
                        system("cls");
                        system("COLOR C");
                        printf("\aFichier vide"); // "Blindage" d'ouverture de fichier
                        i=27;
                        Sleep(1500);
                        system("COLOR 7");
                        loadAll(config,infos);
                        break;
                    }

                    system("cls");

                    tempname=(char*)malloc(150*sizeof(char));

                    fscanf(save,"%s",tempname); // Récupération du nom

                    infos->name=(char*)malloc((strlen(tempname)+1)*sizeof(char));
                    strcpy(infos->name,tempname);
                    free(tempname);

                    fscanf(save," niveau=%d, %d points\n%d %d %d %d %d\n%d\n%d %d %d %d %d",&infos->niveau,&infos->score , &infos->maxF, &infos->maxM, &infos->maxO, &infos->maxP, &infos->maxS, &infos->contratF, &infos->contratM, &infos->contratO, &infos->contratP, &infos->contratS, &infos->multiplicateur, &infos->fraise, &infos->mandarine, &infos->oignon, &infos->pomme, &infos->soleil);
                    fscanf(save,"\nHeight=%d, Width=%d, cursx=%d, cursy=%d\nnumverif=%d",&config->gridHeight,&config->gridWidth,&config->cursx,&config->cursy,&username[0]);

                    fscanf(save,"\n\n",NULL);
                    for (i=0; i<(config->gridHeight); i++)
                        {
                            for (j=0; j<(config->gridWidth); j++)
                                fscanf(save,"%c ",&config->grid[i][j]);
                            fscanf(save,"\n",NULL);
                        }

                    system("cls");

                    if (username[0]!=42)
                    {
                        configInit(config,infos); // Réinitialiser les structures chargées
                        printf("Le fichier de sauvegarde semble \210tre corrompu.\nLe supprimer ? (y/n) ");
                        fflush(stdin);
                        scanf("%c",&username[0]);
                        if (username[0]=='n')
                        {
                            loadAll(config,infos);
                            i=27;
                            break;
                        }
                        fclose(save);
                        remove(file);
                        printf("Fichier supprim\202");
                    }
                    else
                        printf("Partie charg\202e");

                    Sleep(1500);
                    i=27;
                    break;
                }
            }
    }
    fclose(save);
}

int main()
{
    t_config *config;
    t_infos *infos;
    config=(t_config*)malloc(sizeof(t_config));
    infos=(t_infos*)malloc(sizeof(t_infos));

    /// Initialisation pdcurses
    initscr();			// Start curses mode
	raw();				// Line buffering disabled
	keypad(stdscr, TRUE);		// We get F1, F2 etc..
	noecho();			// Don't echo() while we do getch
    ///Fin initialisation

    configInit(config,infos);

    printf ("Structure initialis\202e\n");

    loadAll(config,infos);
    saveAll(config, infos);

    endwin();
    return 0;
}
