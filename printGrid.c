#include "header.h"

///Sous-programme d'affichage case par case

void printGrid(t_config *config, int x, int y)
{
    gotoligcol(y,x*2);
    printf("%c ", config->grid[y][x]);
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

/// Sous-programme d'affichage du menu pendant le jeu
int menuPause(t_config *config, t_infos *infos)
{
    int k=0, touche;
    system("cls");
    printf("Menu Pause :\n\n1. Sauvergarder partie \n2. Charger partie sauvergard\202e \n3. Options \n4. Retour \n5. Quitter jeu\n");
    do{
        fflush(stdin);
    touche=getch();
    switch(touche)
    {
        /* case '1' : void save (config, infos);
            break;

        case '2' : void load (config, infos);
            break;

        case '3' : void menuOptions(infos);
            break;
            */

        case '4' : k=1;
            break;

        case '5' : k=127;
            system("cls");
            printf("Merci d'avoir jou\202 !\n");
            break;
    }
    }while(k==0);
    return k;
}

/// Sous-programme de recherche des figures dans la matrice
void searchPattern (t_config *config, t_infos *infos, int a)
{
    int i, j, k, l, m;
    char lettre;
    for(i=0; i<config->gridHeight; i++)
    {
        for(j=0; j<config->gridWidth; j++)
        {
             ///1.Figures à base d'un alignement de 5 caractères identiques en ligne
            if((j<config->gridWidth-4)&&(config->grid[i][j]==config->grid[i][j+1])&&(config->grid[i][j]==config->grid[i][j+2])&&(config->grid[i][j]==config->grid[i][j+3])&&(config->grid[i][j]==config->grid[i][j+4]))
            {
                /// 1.1. Croix
                if((i>1)&&(i<config->gridHeight-2)&&(config->grid[i][j]==config->grid[i-1][j+2])&&(config->grid[i][j]==config->grid[i-2][j+2])&&(config->grid[i][j]==config->grid[i+1][j+2])&&(config->grid[i][j]==config->grid[i+2][j+2]))
                {
                    /// En cas d'alignement de 5 char ou d'une croix de 5x5, suppression de la totalité des items identiques de la matrice
                    k=0;
                    lettre=config->grid[i][j];
                    for(l=0; l<config->gridHeight; l++)
                    {
                        for(m=0; m<config->gridWidth; m++)
                        {
                            if (config->grid[l][m]==lettre)
                            {
                                config->grid[l][m]=' ';
                                printGrid(config, m, l);
                                k++;

                            }
                        }
                    }

                    if(a!=0)
                    {
                        contrat(config, infos, lettre, k);

                    }
                }

                ///1.2. T vers le bas
                if((i>1)&&(config->grid[i][j]==config->grid[i-1][j+2])&&(config->grid[i][j]==config->grid[i-2][j+2]))
                {
                    lettre=config->grid[i][j];
                    if(a!=0)
                    {
                        contrat(config, infos, lettre, 8);

                    }
                    config->grid[i][j]=' ';
                    config->grid[i][j+1]=' ';
                    config->grid[i][j+2]=' ';
                    config->grid[i][j+3]=' ';
                    config->grid[i][j+4]=' ';
                    config->grid[i-1][j+2]=' ';
                    config->grid[i-2][j+2]=' ';
                    printGrid(config, j, i);
                    printGrid(config, j+1, i);
                    printGrid(config, j+2, i);
                    printGrid(config, j+3, i);
                    printGrid(config, j+4, i);
                    printGrid(config, j+2, i-1);
                    printGrid(config, j+2, i-2);
                }
                ///1.3. T vers le haut
                if((i<(config->gridHeight-2))&&(config->grid[i][j]==config->grid[i+1][j+2])&&(config->grid[i][j]==config->grid[i+2][j+2]))
                {
                    lettre=config->grid[i][j];
                    if(a!=0)
                    {
                        contrat(config, infos, lettre, 8);

                    }
                    config->grid[i][j]=' ';
                    config->grid[i][j+1]=' ';
                    config->grid[i][j+2]=' ';
                    config->grid[i][j+3]=' ';
                    config->grid[i][j+4]=' ';
                    config->grid[i+1][j+2]=' ';
                    config->grid[i+2][j+2]=' ';
                    printGrid(config, j, i);
                    printGrid(config, j+1, i);
                    printGrid(config, j+2, i);
                    printGrid(config, j+3, i);
                    printGrid(config, j+4, i);
                    printGrid(config, j+2, i+1);
                    printGrid(config, j+2, i+2);
                }
            }

            /// 2. Figures à base d'un alignement de 5 caractères identiques en colonne
             if((i<config->gridHeight-4)&&(config->grid[i][j]==config->grid[i+1][j])&&(config->grid[i][j]==config->grid[i+2][j])&&(config->grid[i][j]==config->grid[i+3][j])&&(config->grid[i][j]==config->grid[i+4][j]))
            {
                /// 2.1. T vers la gauche
                if((j<config->gridWidth-2)&&(config->grid[i][j]==config->grid[i+2][j+1])&&(config->grid[i][j]==config->grid[i+2][j+2]))
                {
                    lettre=config->grid[i][j];
                    if(a!=0)
                    {
                        contrat(config, infos, lettre, 8);

                    }
                    config->grid[i][j]=' ';
                    config->grid[i+1][j]=' ';
                    config->grid[i+2][j]=' ';
                    config->grid[i+3][j]=' ';
                    config->grid[i+4][j]=' ';
                    config->grid[i+2][j+1]=' ';
                    config->grid[i+2][j+2]=' ';
                    printGrid(config, j, i);
                    printGrid(config, j, i+1);
                    printGrid(config, j, i+2);
                    printGrid(config, j, i+3);
                    printGrid(config, j, i+4);
                    printGrid(config, j+1, i+2);
                    printGrid(config, j+2, i+2);
                }

                /// 2.2. T vers la droite
                if((j>1)&&(config->grid[i][j]==config->grid[i+2][j-1])&&(config->grid[i][j]==config->grid[i+2][j-2]))
                {
                    lettre=config->grid[i][j];
                    if(a!=0)
                    {
                        contrat(config, infos, lettre, 8);

                    }
                    config->grid[i][j]=' ';
                    config->grid[i+1][j]=' ';
                    config->grid[i+2][j]=' ';
                    config->grid[i+3][j]=' ';
                    config->grid[i+4][j]=' ';
                    config->grid[i+2][j-1]=' ';
                    config->grid[i+2][j-2]=' ';
                    printGrid(config, j, i);
                    printGrid(config, j, i+1);
                    printGrid(config, j, i+2);
                    printGrid(config, j, i+3);
                    printGrid(config, j, i+4);
                    printGrid(config, j-1, i+2);
                    printGrid(config, j-2, i+2);
                }
            }


            /// 3. Figures à base d'un alignement de 4 caractères identiques en ligne
            if((j<config->gridWidth-3)&&(config->grid[i][j]==config->grid[i][j+1])&&(config->grid[i][j]==config->grid[i][j+2])&&(config->grid[i][j]==config->grid[i][j+3]))
            {
                /// 3.1. T vers le bas (gauche)
                if((i>1)&&(config->grid[i][j]==config->grid[i-1][j+1])&&(config->grid[i][j]==config->grid[i-2][j+1]))
                {
                    if(a!=0)
                    {
                        lettre=config->grid[i][j];
                        contrat(config, infos, lettre, 7);

                    }
                    config->grid[i][j]=' ';
                    config->grid[i][j+1]=' ';
                    config->grid[i][j+2]=' ';
                    config->grid[i][j+3]=' ';
                    config->grid[i-1][j+1]=' ';
                    config->grid[i-2][j+1]=' ';
                    printGrid(config, j, i);
                    printGrid(config, j+1, i);
                    printGrid(config, j+2, i);
                    printGrid(config, j+3, i);
                    printGrid(config, j+1, i-1);
                    printGrid(config, j+1, i-2);
                }
                /// 3.2. T vers le bas (droite)
                if((i>1)&&(config->grid[i][j]==config->grid[i-1][j+2])&&(config->grid[i][j]==config->grid[i-2][j+2]))
                {
                    lettre=config->grid[i][j];
                    if(a!=0)
                    {
                        contrat(config, infos, lettre, 7);

                    }
                    config->grid[i][j]=' ';
                    config->grid[i][j+1]=' ';
                    config->grid[i][j+2]=' ';
                    config->grid[i][j+3]=' ';
                    config->grid[i-1][j+2]=' ';
                    config->grid[i-2][j+2]=' ';
                    printGrid(config, j, i);
                    printGrid(config, j+1, i);
                    printGrid(config, j+2, i);
                    printGrid(config, j+3, i);
                    printGrid(config, j+2, i-1);
                    printGrid(config, j+2, i-2);
                }

                /// 3.3. T vers le haut (gauche)
                if((i<config->gridHeight-2)&&(config->grid[i][j]==config->grid[i+1][j+1])&&(config->grid[i][j]==config->grid[i+2][j+1]))
                {
                    lettre=config->grid[i][j];
                    if(a!=0)
                    {
                        contrat(config, infos, lettre, 7);

                    }
                    config->grid[i][j]=' ';
                    config->grid[i][j+1]=' ';
                    config->grid[i][j+2]=' ';
                    config->grid[i][j+3]=' ';
                    config->grid[i+1][j+1]=' ';
                    config->grid[i+2][j+1]=' ';
                    printGrid(config, j, i);
                    printGrid(config, j+1, i);
                    printGrid(config, j+2, i);
                    printGrid(config, j+3, i);
                    printGrid(config, j+1, i+1);
                    printGrid(config, j+1, i+2);
                }

                /// 3.4. T vers le haut (droite)
                if((i<config->gridHeight-2)&&(config->grid[i][j]==config->grid[i+1][j+2])&&(config->grid[i][j]==config->grid[i+2][j+2]))
                {
                    lettre=config->grid[i][j];
                    if(a!=0)
                    {
                        contrat(config, infos, lettre, 7);

                    }
                    config->grid[i][j]=' ';
                    config->grid[i][j+1]=' ';
                    config->grid[i][j+2]=' ';
                    config->grid[i][j+3]=' ';
                    config->grid[i+1][j+2]=' ';
                    config->grid[i+2][j+2]=' ';
                    printGrid(config, j, i);
                    printGrid(config, j+1, i);
                    printGrid(config, j+2, i);
                    printGrid(config, j+3, i);
                    printGrid(config, j+2, i+1);
                    printGrid(config, j+2, i+2);
                }
            }

            /// 4. Figures à base d'un alignement de 4 caractères identiques en colonne
            if((i<config->gridHeight-3)&&(config->grid[i][j]==config->grid[i+1][j])&&(config->grid[i][j]==config->grid[i+2][j])&&(config->grid[i][j]==config->grid[i+3][j]))
            {

                /// 4.1. T vers la gauche (haut)
                if((j<config->gridWidth-2)&&(config->grid[i][j]==config->grid[i+1][j+1])&&(config->grid[i][j]==config->grid[i+1][j+2]))
                {
                    lettre=config->grid[i][j];
                    if(a!=0)
                    {
                        contrat(config, infos, lettre, 7);

                    }
                    config->grid[i][j]=' ';
                    config->grid[i+1][j]=' ';
                    config->grid[i+2][j]=' ';
                    config->grid[i+3][j]=' ';
                    config->grid[i+1][j+1]=' ';
                    config->grid[i+1][j+2]=' ';
                    printGrid(config, j, i);
                    printGrid(config, j, i+1);
                    printGrid(config, j, i+2);
                    printGrid(config, j, i+3);
                    printGrid(config, j+1, i+1);
                    printGrid(config, j+2, i+1);
                }
                /// 4.1. T vers la gauche (bas)
                if((j<config->gridWidth-2)&&(config->grid[i][j]==config->grid[i+2][j+1])&&(config->grid[i][j]==config->grid[i+2][j+2]))
                {
                    lettre=config->grid[i][j];
                    if(a!=0)
                    {
                        contrat(config, infos, lettre, 7);

                    }
                    config->grid[i][j]=' ';
                    config->grid[i+1][j]=' ';
                    config->grid[i+2][j]=' ';
                    config->grid[i+3][j]=' ';
                    config->grid[i+2][j+1]=' ';
                    config->grid[i+2][j+2]=' ';
                    printGrid(config, j, i);
                    printGrid(config, j, i+1);
                    printGrid(config, j, i+2);
                    printGrid(config, j, i+3);
                    printGrid(config, j+1, i+2);
                    printGrid(config, j+2, i+2);
                }
                /// 4.3. T vers la droite (haut)
                if((j>1)&&(config->grid[i][j]==config->grid[i+1][j-1])&&(config->grid[i][j]==config->grid[i+1][j-2]))
                {
                    lettre=config->grid[i][j];
                    if(a!=0)
                    {
                        contrat(config, infos, lettre, 7);

                    }
                    config->grid[i][j]=' ';
                    config->grid[i+1][j]=' ';
                    config->grid[i+2][j]=' ';
                    config->grid[i+3][j]=' ';
                    config->grid[i+1][j-1]=' ';
                    config->grid[i+1][j-2]=' ';
                    printGrid(config, j, i);
                    printGrid(config, j, i+1);
                    printGrid(config, j, i+2);
                    printGrid(config, j, i+3);
                    printGrid(config, j-1, i+1);
                    printGrid(config, j-2, i+1);
                }

                /// 4.4. T vers la droite (bas)
                if((j>1)&&(config->grid[i][j]==config->grid[i+2][j-1])&&(config->grid[i][j]==config->grid[i+2][j-2]))
                {
                    lettre=config->grid[i][j];
                    if(a!=0)
                    {
                        contrat(config, infos, lettre, 7);

                    }
                    config->grid[i][j]=' ';
                    config->grid[i+1][j]=' ';
                    config->grid[i+2][j]=' ';
                    config->grid[i+3][j]=' ';
                    config->grid[i+2][j-1]=' ';
                    config->grid[i+2][j-2]=' ';
                    printGrid(config, j, i);
                    printGrid(config, j, i+1);
                    printGrid(config, j, i+2);
                    printGrid(config, j, i+3);
                    printGrid(config, j-1, i+2);
                    printGrid(config, j-2, i+2);
                }
            }

            /// 5. Figures à base d'un alignement de 3 caractères en ligne
            if((j<config->gridWidth-2)&&(config->grid[i][j]==config->grid[i][j+1])&&(config->grid[i][j]==config->grid[i][j+2]))
            {
                /// 5.1. Croix
                if((i<config->gridHeight-1)&&(i>0)&&(config->grid[i][j]==config->grid[i-1][j+1])&&(config->grid[i][j]==config->grid[i+1][j+1]))
                {
                    lettre=config->grid[i][j];
                    if(a!=0)
                    {
                        contrat(config, infos, lettre, 6);

                    }
                    config->grid[i][j]=' ';
                    config->grid[i][j+1]=' ';
                    config->grid[i][j+2]=' ';
                    config->grid[i-1][j+1]=' ';
                    config->grid[i+1][j+1]=' ';
                    printGrid(config, j, i);
                    printGrid(config, j+1, i);
                    printGrid(config, j+2, i);
                    printGrid(config, j+1, i-1);
                    printGrid(config, j+1, i+1);
                }

                /// 5.2. L vers la gauche
                if((i>1)&&(config->grid[i][j]==config->grid[i-1][j])&&(config->grid[i][j]==config->grid[i-2][j]))
                {
                    lettre=config->grid[i][j];
                    if(a!=0)
                    {
                        contrat(config, infos, lettre, 6);

                    }
                    config->grid[i][j]=' ';
                    config->grid[i-1][j]=' ';
                    config->grid[i-2][j]=' ';
                    config->grid[i][j+1]=' ';
                    config->grid[i][j+2]=' ';
                    printGrid(config, j, i);
                    printGrid(config, j, i-1);
                    printGrid(config, j, i-2);
                    printGrid(config, j+1, i);
                    printGrid(config, j+2, i);
                }

                /// 5.3. L vers la droite
                if((i>1)&&(config->grid[i][j]==config->grid[i-1][j+2])&&(config->grid[i][j]==config->grid[i-2][j+2]))
                {
                    lettre=config->grid[i][j];
                    if(a!=0)
                    {
                        contrat(config, infos, lettre, 6);

                    }
                    config->grid[i][j]=' ';
                    config->grid[i-1][j+2]=' ';
                    config->grid[i-2][j+2]=' ';
                    config->grid[i][j+1]=' ';
                    config->grid[i][j+2]=' ';
                    printGrid(config, j, i);
                    printGrid(config, j+2, i-1);
                    printGrid(config, j+2, i-2);
                    printGrid(config, j+1, i);
                    printGrid(config, j+2, i);
                }

                /// 5.4. L inversé gauche
                if((i<config->gridHeight-2)&&(config->grid[i][j]==config->grid[i+1][j])&&(config->grid[i][j]==config->grid[i+2][j]))
                {
                    lettre=config->grid[i][j];
                    if(a!=0)
                    {
                        contrat(config, infos, lettre, 6);

                    }
                    config->grid[i][j]=' ';
                    config->grid[i][j+1]=' ';
                    config->grid[i][j+2]=' ';
                    config->grid[i+1][j]=' ';
                    config->grid[i+2][j]=' ';
                    printGrid(config, j, i);
                    printGrid(config, j+1, i);
                    printGrid(config, j+2, i);
                    printGrid(config, j, i+1);
                    printGrid(config, j, i+2);
                }

                /// 5.5. L inversé droite
                if((i<config->gridHeight-2)&&(config->grid[i][j]==config->grid[i+1][j+2])&&(config->grid[i][j]==config->grid[i+2][j+2]))
                {
                    lettre=config->grid[i][j];
                    if(a!=0)
                    {
                        contrat(config, infos, lettre, 6);

                    }
                    config->grid[i][j]=' ';
                    config->grid[i][j+1]=' ';
                    config->grid[i][j+2]=' ';
                    config->grid[i+1][j+2]=' ';
                    config->grid[i+2][j+2]=' ';
                    printGrid(config, j, i);
                    printGrid(config, j+1, i);
                    printGrid(config, j+2, i);
                    printGrid(config, j+2, i+1);
                    printGrid(config, j+2, i+2);
                }

                /// 5.6. T vers le haut
                if((i<config->gridHeight-2)&&(config->grid[i][j]==config->grid[i+1][j+1])&&(config->grid[i][j]==config->grid[i+2][j+1]))
                {
                    lettre=config->grid[i][j];
                    if(a!=0)
                    {
                        contrat(config, infos, lettre, 6);

                    }
                    config->grid[i][j]=' ';
                    config->grid[i][j+1]=' ';
                    config->grid[i][j+2]=' ';
                    config->grid[i+1][j+1]=' ';
                    config->grid[i+2][j+1]=' ';
                    printGrid(config, j, i);
                    printGrid(config, j+1, i);
                    printGrid(config, j+2, i);
                    printGrid(config, j+1, i+1);
                    printGrid(config, j+1, i+2);
                }

                /// 5.7. T vers le bas
                if((i>1)&&(config->grid[i][j]==config->grid[i-1][j+1])&&(config->grid[i][j]==config->grid[i-2][j+1]))
                {
                    lettre=config->grid[i][j];
                    if(a!=0)
                    {
                        contrat(config, infos, lettre, 6);

                    }
                    config->grid[i][j]=' ';
                    config->grid[i][j+1]=' ';
                    config->grid[i][j+2]=' ';
                    config->grid[i-1][j+1]=' ';
                    config->grid[i-2][j+1]=' ';
                    printGrid(config, j, i);
                    printGrid(config, j+1, i);
                    printGrid(config, j+2, i);
                    printGrid(config, j+1, i-1);
                    printGrid(config, j+1, i-2);
                }

                /// 5.8. T vers la droite
                if((i>0)&&(i<config->gridHeight-1)&&(config->grid[i][j]==config->grid[i-1][j+2])&&(config->grid[i][j]==config->grid[i+1][j+2]))
                {
                    lettre=config->grid[i][j];
                    if(a!=0)
                    {
                        contrat(config, infos, lettre, 6);

                    }
                    config->grid[i][j]=' ';
                    config->grid[i][j+1]=' ';
                    config->grid[i][j+2]=' ';
                    config->grid[i-1][j+2]=' ';
                    config->grid[i+1][j+2]=' ';
                    printGrid(config, j, i);
                    printGrid(config, j+1, i);
                    printGrid(config, j+2, i);
                    printGrid(config, j+2, i-1);
                    printGrid(config, j+2, i+1);
                }

                /// 5.9. T vers la gauche
                if((i>0)&&(i<config->gridHeight-1)&&(config->grid[i][j]==config->grid[i-1][j])&&(config->grid[i][j]==config->grid[i+1][j]))
                {
                    lettre=config->grid[i][j];
                    if(a!=0)
                    {
                        contrat(config, infos, lettre, 6);

                    }
                    config->grid[i][j]=' ';
                    config->grid[i][j+1]=' ';
                    config->grid[i][j+2]=' ';
                    config->grid[i-1][j]=' ';
                    config->grid[i+1][j]=' ';
                    printGrid(config, j, i);
                    printGrid(config, j+1, i);
                    printGrid(config, j+2, i);
                    printGrid(config, j, i-1);
                    printGrid(config, j, i+1);
                }

            }

            /// 6. Alignements simples

                /// 6.1. Alignement de 5 caractères en ligne
                if((j<config->gridWidth-4)&&(config->grid[i][j]==config->grid[i][j+1])&&(config->grid[i][j]==config->grid[i][j+2])&&(config->grid[i][j]==config->grid[i][j+3])&&(config->grid[i][j]==config->grid[i][j+4]))
                {
                    /// En cas d'alignement de 5 char, suppression de la totalité des items identiques de la matrice
                    k=0;
                    lettre=config->grid[i][j];
                    for(l=0; l<config->gridHeight; l++)
                    {
                        for(m=0; m<config->gridWidth; m++)
                        {
                            if (config->grid[l][m]==lettre)
                            {
                                config->grid[l][m]=' ';
                                printGrid(config, m, l);
                                k++;

                            }
                        }
                    }

                    if(a!=0)
                    {
                        contrat(config, infos, lettre, k);

                    }
                }

                /// 6.2. Alignement de 5 caractères en colonne

                if((i<config->gridHeight-4)&&(config->grid[i][j]==config->grid[i+1][j])&&(config->grid[i][j]==config->grid[i+2][j])&&(config->grid[i][j]==config->grid[i+3][j])&&(config->grid[i][j]==config->grid[i+4][j]))
                {
                    /// En cas d'alignement de 5 char, suppression de la totalité des items identiques de la matrice
                    k=0;
                    lettre=config->grid[i][j];
                    for(l=0; l<config->gridHeight; l++)
                    {
                        for(m=0; m<config->gridWidth; m++)
                        {
                            if (config->grid[l][m]==lettre)
                            {
                                config->grid[l][m]=' ';
                                printGrid(config, m, l);
                                k++;

                            }
                        }
                    }

                    if(a!=0)
                    {
                        contrat(config, infos, lettre, k);

                    }
                }
                /// 6.3. Alignement de 4 caractères en ligne
                if((j<config->gridWidth-3)&&(config->grid[i][j]==config->grid[i][j+1])&&(config->grid[i][j]==config->grid[i][j+2])&&(config->grid[i][j]==config->grid[i][j+3]))
                {
                    lettre=config->grid[i][j];
                    if(a!=0)
                    {
                        contrat(config, infos, lettre, 4);

                    }
                    config->grid[i][j]=' ';
                    config->grid[i][j+1]=' ';
                    config->grid[i][j+2]=' ';
                    config->grid[i][j+3]=' ';
                    printGrid(config, j, i);
                    printGrid(config, j+1, i);
                    printGrid(config, j+2, i);
                    printGrid(config, j+3, i);
                }

                /// 6.4. Alignement de 4 caractères en colonne
                if((i<config->gridHeight-3)&&(config->grid[i][j]==config->grid[i+1][j])&&(config->grid[i][j]==config->grid[i+2][j])&&(config->grid[i][j]==config->grid[i+3][j]))
                {
                    lettre=config->grid[i][j];
                    if(a!=0)
                    {
                        contrat(config, infos, lettre, 4);

                    }
                    config->grid[i][j]=' ';
                    config->grid[i+1][j]=' ';
                    config->grid[i+2][j]=' ';
                    config->grid[i+3][j]=' ';
                    printGrid(config, j, i);
                    printGrid(config, j, i+1);
                    printGrid(config, j, i+2);
                    printGrid(config, j, i+3);
                }
                /// 6.5. Alignement de 3 caractères en ligne
                if((j<config->gridWidth-2)&&(config->grid[i][j]==config->grid[i][j+1])&&(config->grid[i][j]==config->grid[i][j+2]))
                {
                    lettre=config->grid[i][j];
                    if(a!=0)
                    {
                        contrat(config, infos, lettre, 3);

                    }
                    config->grid[i][j]=' ';
                    config->grid[i][j+1]=' ';
                    config->grid[i][j+2]=' ';
                    printGrid(config, j, i);
                    printGrid(config, j+1, i);
                    printGrid(config, j+2, i);
                }
                /// 6.6. Alignement de 3 caractères en colonne
                if((i<config->gridHeight-2)&&(config->grid[i][j]==config->grid[i+1][j])&&(config->grid[i][j]==config->grid[i+2][j]))
                {
                    lettre=config->grid[i][j];
                    if(a!=0)
                    {
                        contrat(config, infos, lettre, 3);

                    }
                    config->grid[i][j]=' ';
                    config->grid[i+1][j]=' ';
                    config->grid[i+2][j]=' ';
                    printGrid(config, j, i);
                    printGrid(config, j, i+1);
                    printGrid(config, j, i+2);
                }
        }
    }
}


