#include "header.h"
#include <curses.h>

void saveAll (t_config *config, t_infos *infos) /// Programme de sauvegarde
{
        /// Initialisation pdcurses
    initscr();			// Start curses mode
	raw();				// Line buffering disabled
	keypad(stdscr, TRUE);		// We get F1, F2 etc..
	noecho();			// Don't echo() while we do getch
    ///Fin initialisation

    FILE *save;
    char file[23],*username,*tempname,niveau=1,*temp=NULL;
    int i=1,j=0;

    system("cls");
    refresh();

    printf("S\202lectionnez un emplacement de sauvegarde avec les fl\212ches et entr\202e :\n");

    for (i=1; i<6; i++)
    {
        sprintf(file,"save_files\\save_%d.mcy",i);

        printf("\n( ) Emplacement %d ",i);
        save=fopen(file,"r");

        if (save==NULL)
        {
            printf("vide\n");
            username=(char*)malloc(sizeof(char));
        }

        else
        {
            /// Blindage de récupération du nom dans le fichier
            tempname=(char*)malloc(150*sizeof(char));

            fscanf(save,"%s",tempname); // Récupération du nom

            username=(char*)malloc((strlen(tempname)+1)*sizeof(char));
            do // Gestion des espaces dans le nom
            {
                temp=strchr(tempname,'_');
                if(temp!=NULL)
                    *temp=' ';
            }while(temp!=NULL);

            strcpy(username,tempname);
            free(tempname);

            fscanf(save," niveau=%d, %d",&niveau,&j); // Récupération du niveau

            printf(": %s, niveau %d - %d points\n", username, niveau, j); // Affichage du contenu de l'emplacement

            fclose(save);
        }
    }
    j=2;
    gotoligcol(j,1);
    printf("*");
    gotoligcol(j,1);

    while(i!=27) /// Boucle de choix de l'emplacement de sauvegarde
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


                    fprintf(save,"%s niveau=%d, %d points\n%d %d %d %d %d\n%d %d %d %d %d\n%d %d %d %d",infos->name,infos->niveau,infos->score , infos->maxF,
                            infos->maxM, infos->maxO, infos->maxP, infos->maxS, infos->contratF, infos->contratM, infos->contratO, infos->contratP, infos->contratS, infos->multiplicateur, infos->hits, infos->maxHits,infos->vies);
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
    endwin();
}

void loadAll(t_config *config, t_infos *infos)
{
        /// Initialisation pdcurses
    initscr();			// Start curses mode
	raw();				// Line buffering disabled
	keypad(stdscr, TRUE);		// We get F1, F2 etc..
	noecho();			// Don't echo() while we do getch
    ///Fin initialisation

    FILE *save;
    char file[23],*username,*tempname,niveau=1,*temp=NULL;
    int i=1,j=0;

    system("cls");
    refresh();

    printf("S\202lectionnez un emplacement \205 charger avec les fl\212ches et entr\202e :\n");

    for (i=1; i<6; i++)
    {
        sprintf(file,"save_files\\save_%d.mcy",i);

        printf("\n( ) Emplacement %d ",i);
        save=fopen(file,"r");

        if (save==NULL)
        {

            printf("vide\n");
            username=(char*)malloc(sizeof(char));

        }

        else
        {
            /// Blindage de récupération du nom dans le fichier
            tempname=(char*)malloc(150*sizeof(char));

            fscanf(save,"%s",tempname); // Récupération du nom

            username=(char*)malloc((strlen(tempname)+1)*sizeof(char));
            do
            {
                temp=strchr(tempname,'_'); // Gestion des espaces dans le nom
                if(temp!=NULL)
                    *temp=' ';
            }while(temp!=NULL);

            strcpy(username,tempname);
            free(tempname);

            fscanf(save," niveau=%d, %d",&niveau,&j); // Récupération du niveau

            printf(": %s, niveau %d - %d points\n", username, niveau, j); // Affichage du contenu de l'emplacement

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

                    fscanf(save," niveau=%d, %d points\n%d %d %d %d %d\n%d %d %d %d %d\n%d %d %d %d",&infos->niveau,&infos->score , &infos->maxF, &infos->maxM, &infos->maxO,
                           &infos->maxP, &infos->maxS, &infos->contratF, &infos->contratM, &infos->contratO, &infos->contratP, &infos->contratS, &infos->multiplicateur, &infos->hits, &infos->maxHits,&infos->vies);
                    fscanf(save,"\nHeight=%d, Width=%d, cursx=%d, cursy=%d\nnumverif=%d",&config->gridHeight,&config->gridWidth,&config->cursx,&config->cursy,&username[0]);

                    fscanf(save,"\n\n",NULL);
                    for (i=0; i<(config->gridHeight); i++)
                        {
                            for (j=0; j<(config->gridWidth); j++)
                                fscanf(save,"%c ",&config->grid[i][j]);
                            fscanf(save,"\n",NULL);
                        }

                    system("cls");

                    if (username[0]!=42) /// Si le fichier est corrompu, demander à le supprimer (détecte un nombre spécifique à un endroit particulier qui montre que le fichier a été créé avec le programme de sauvegarde.
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
    endwin();
}

