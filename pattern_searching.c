#include "header.h"

/// Sous-programme de recherche des figures dans la matrice
int searchPattern (t_config *config, t_infos *infos, int a)
{
    int i, j, k, l, m, n=0;
    char lettre;
    for(i=0; i<config->gridHeight; i++)
    {
        for(j=0; j<config->gridWidth; j++)
        {
             ///1.Figures � base d'un alignement de 5 caract�res identiques en ligne
            if((j<config->gridWidth-4)&&(config->grid[i][j]==config->grid[i][j+1])&&(config->grid[i][j]==config->grid[i][j+2])&&(config->grid[i][j]==config->grid[i][j+3])&&(config->grid[i][j]==config->grid[i][j+4]))
            {
                /// 1.1. Croix
                if((i>1)&&(i<config->gridHeight-2)&&(config->grid[i][j]==config->grid[i-1][j+2])&&(config->grid[i][j]==config->grid[i-2][j+2])&&(config->grid[i][j]==config->grid[i+1][j+2])&&(config->grid[i][j]==config->grid[i+2][j+2]))
                {
                    infos->multiplicateur=2;
                    /// En cas d'alignement de 5 char ou d'une croix de 5x5, suppression de la totalit� des items identiques de la matrice
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
                        score(infos, k);
                    }
                }

                ///1.2. T vers le bas
                if((i>1)&&(config->grid[i][j]==config->grid[i-1][j+2])&&(config->grid[i][j]==config->grid[i-2][j+2]))
                {
                    infos->multiplicateur=2;
                    lettre=config->grid[i][j];
                    if(a!=0)
                    {
                        contrat(config, infos, lettre, 8);
                        score(infos, 8);
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
                    infos->multiplicateur=2;
                    lettre=config->grid[i][j];
                    if(a!=0)
                    {
                        contrat(config, infos, lettre, 8);
                        score(infos, 8);
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
                n=1;
            }

            /// 2. Figures � base d'un alignement de 5 caract�res identiques en colonne
             if((i<config->gridHeight-4)&&(config->grid[i][j]==config->grid[i+1][j])&&(config->grid[i][j]==config->grid[i+2][j])&&(config->grid[i][j]==config->grid[i+3][j])&&(config->grid[i][j]==config->grid[i+4][j]))
            {
                /// 2.1. T vers la gauche
                if((j<config->gridWidth-2)&&(config->grid[i][j]==config->grid[i+2][j+1])&&(config->grid[i][j]==config->grid[i+2][j+2]))
                {
                    infos->multiplicateur=2;
                    lettre=config->grid[i][j];
                    if(a!=0)
                    {
                        contrat(config, infos, lettre, 8);
                        score(infos, 8);
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
                    infos->multiplicateur=2;
                    lettre=config->grid[i][j];
                    if(a!=0)
                    {
                        contrat(config, infos, lettre, 8);
                        score(infos, 8);
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
                n=1;
            }


            /// 3. Figures � base d'un alignement de 4 caract�res identiques en ligne
            if((j<config->gridWidth-3)&&(config->grid[i][j]==config->grid[i][j+1])&&(config->grid[i][j]==config->grid[i][j+2])&&(config->grid[i][j]==config->grid[i][j+3]))
            {
                /// 3.1. T vers le bas (gauche)
                if((i>1)&&(config->grid[i][j]==config->grid[i-1][j+1])&&(config->grid[i][j]==config->grid[i-2][j+1]))
                {
                    infos->multiplicateur=2;
                    lettre=config->grid[i][j];
                    if(a!=0)
                    {
                        contrat(config, infos, lettre, 7);
                        score(infos, 7);
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
                    infos->multiplicateur=2;
                    lettre=config->grid[i][j];
                    if(a!=0)
                    {
                        contrat(config, infos, lettre, 7);
                        score(infos, 7);
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
                    infos->multiplicateur=2;
                    lettre=config->grid[i][j];
                    if(a!=0)
                    {
                        contrat(config, infos, lettre, 7);
                        score(infos, 7);
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
                    infos->multiplicateur=2;
                    lettre=config->grid[i][j];
                    if(a!=0)
                    {
                        contrat(config, infos, lettre, 7);
                        score(infos, 7);
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
                n=1;
            }

            /// 4. Figures � base d'un alignement de 4 caract�res identiques en colonne
            if((i<config->gridHeight-3)&&(config->grid[i][j]==config->grid[i+1][j])&&(config->grid[i][j]==config->grid[i+2][j])&&(config->grid[i][j]==config->grid[i+3][j]))
            {

                /// 4.1. T vers la gauche (haut)
                if((j<config->gridWidth-2)&&(config->grid[i][j]==config->grid[i+1][j+1])&&(config->grid[i][j]==config->grid[i+1][j+2]))
                {
                    infos->multiplicateur=2;
                    lettre=config->grid[i][j];
                    if(a!=0)
                    {
                        contrat(config, infos, lettre, 7);
                        score(infos, 7);
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
                    infos->multiplicateur=2;
                    lettre=config->grid[i][j];
                    if(a!=0)
                    {
                        contrat(config, infos, lettre, 7);
                        score(infos, 7);
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
                    infos->multiplicateur=2;
                    lettre=config->grid[i][j];
                    if(a!=0)
                    {
                        contrat(config, infos, lettre, 7);
                        score(infos, 7);
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
                    infos->multiplicateur=2;
                    lettre=config->grid[i][j];
                    if(a!=0)
                    {
                        contrat(config, infos, lettre, 7);
                        score(infos, 7);
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
                n=1;
            }

            /// 5. Figures � base d'un alignement de 3 caract�res en ligne
            if((j<config->gridWidth-2)&&(config->grid[i][j]==config->grid[i][j+1])&&(config->grid[i][j]==config->grid[i][j+2]))
            {
                /// 5.1. Croix
                if((i<config->gridHeight-1)&&(i>0)&&(config->grid[i][j]==config->grid[i-1][j+1])&&(config->grid[i][j]==config->grid[i+1][j+1]))
                {
                    infos->multiplicateur=2;
                    lettre=config->grid[i][j];
                    if(a!=0)
                    {
                        contrat(config, infos, lettre, 6);
                        score(infos, 6);
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
                    infos->multiplicateur=2;
                    lettre=config->grid[i][j];
                    if(a!=0)
                    {
                        contrat(config, infos, lettre, 6);
                        score(infos, 6);
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
                    infos->multiplicateur=2;
                    lettre=config->grid[i][j];
                    if(a!=0)
                    {
                        contrat(config, infos, lettre, 6);
                        score(infos, 6);
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

                /// 5.4. L invers� gauche
                if((i<config->gridHeight-2)&&(config->grid[i][j]==config->grid[i+1][j])&&(config->grid[i][j]==config->grid[i+2][j]))
                {
                    infos->multiplicateur=2;
                    lettre=config->grid[i][j];
                    if(a!=0)
                    {
                        contrat(config, infos, lettre, 6);
                        score(infos, 6);
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

                /// 5.5. L invers� droite
                if((i<config->gridHeight-2)&&(config->grid[i][j]==config->grid[i+1][j+2])&&(config->grid[i][j]==config->grid[i+2][j+2]))
                {
                    infos->multiplicateur=2;
                    lettre=config->grid[i][j];
                    if(a!=0)
                    {
                        contrat(config, infos, lettre, 6);
                        score(infos, 6);
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
                    infos->multiplicateur=2;
                    lettre=config->grid[i][j];
                    if(a!=0)
                    {
                        contrat(config, infos, lettre, 6);
                        score(infos, 6);
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
                    infos->multiplicateur=2;
                    lettre=config->grid[i][j];
                    if(a!=0)
                    {
                        contrat(config, infos, lettre, 6);
                        score(infos, 6);
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
                    infos->multiplicateur=2;
                    lettre=config->grid[i][j];
                    if(a!=0)
                    {
                        contrat(config, infos, lettre, 6);
                        score(infos, 6);
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
                    infos->multiplicateur=2;
                    lettre=config->grid[i][j];
                    if(a!=0)
                    {
                        contrat(config, infos, lettre, 6);
                        score(infos, 6);
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
                n=1;

            }


            /// 6. Alignements simples

                /// 6.1. Alignement de 5 caract�res en ligne
                if((j<config->gridWidth-4)&&(config->grid[i][j]==config->grid[i][j+1])&&(config->grid[i][j]==config->grid[i][j+2])&&(config->grid[i][j]==config->grid[i][j+3])&&(config->grid[i][j]==config->grid[i][j+4]))
                {
                    infos->multiplicateur=1;
                    /// En cas d'alignement de 5 char, suppression de la totalit� des items identiques de la matrice
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
                        score(infos, k);
                    }
                    n=1;
                }

                /// 6.2. Alignement de 5 caract�res en colonne

                if((i<config->gridHeight-4)&&(config->grid[i][j]==config->grid[i+1][j])&&(config->grid[i][j]==config->grid[i+2][j])&&(config->grid[i][j]==config->grid[i+3][j])&&(config->grid[i][j]==config->grid[i+4][j]))
                {
                    infos->multiplicateur=1;
                    /// En cas d'alignement de 5 char, suppression de la totalit� des items identiques de la matrice
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
                        score(infos, k);
                    }
                    n=1;
                }
                /// 6.3. Alignement de 4 caract�res en ligne
                if((j<config->gridWidth-3)&&(config->grid[i][j]==config->grid[i][j+1])&&(config->grid[i][j]==config->grid[i][j+2])&&(config->grid[i][j]==config->grid[i][j+3]))
                {
                    infos->multiplicateur=1;
                    lettre=config->grid[i][j];
                    if(a!=0)
                    {
                        contrat(config, infos, lettre, 4);
                        score(infos, 4);
                    }
                    config->grid[i][j]=' ';
                    config->grid[i][j+1]=' ';
                    config->grid[i][j+2]=' ';
                    config->grid[i][j+3]=' ';
                    printGrid(config, j, i);
                    printGrid(config, j+1, i);
                    printGrid(config, j+2, i);
                    printGrid(config, j+3, i);
                    n=1;
                }

                /// 6.4. Alignement de 4 caract�res en colonne
                if((i<config->gridHeight-3)&&(config->grid[i][j]==config->grid[i+1][j])&&(config->grid[i][j]==config->grid[i+2][j])&&(config->grid[i][j]==config->grid[i+3][j]))
                {
                    infos->multiplicateur=1;
                    lettre=config->grid[i][j];
                    if(a!=0)
                    {
                        contrat(config, infos, lettre, 4);
                        score(infos, 4);
                    }
                    config->grid[i][j]=' ';
                    config->grid[i+1][j]=' ';
                    config->grid[i+2][j]=' ';
                    config->grid[i+3][j]=' ';
                    printGrid(config, j, i);
                    printGrid(config, j, i+1);
                    printGrid(config, j, i+2);
                    printGrid(config, j, i+3);
                    n=1;
                }
                /// 6.5. Alignement de 3 caract�res en ligne
                if((j<config->gridWidth-2)&&(config->grid[i][j]==config->grid[i][j+1])&&(config->grid[i][j]==config->grid[i][j+2]))
                {
                    infos->multiplicateur=1;
                    lettre=config->grid[i][j];
                    if(a!=0)
                    {
                        contrat(config, infos, lettre, 3);
                        score(infos, 3);
                    }
                    config->grid[i][j]=' ';
                    config->grid[i][j+1]=' ';
                    config->grid[i][j+2]=' ';
                    printGrid(config, j, i);
                    printGrid(config, j+1, i);
                    printGrid(config, j+2, i);
                    n=1;
                }
                /// 6.6. Alignement de 3 caract�res en colonne
                if((i<config->gridHeight-2)&&(config->grid[i][j]==config->grid[i+1][j])&&(config->grid[i][j]==config->grid[i+2][j]))
                {
                    infos->multiplicateur=1;
                    lettre=config->grid[i][j];
                    if(a!=0)
                    {
                        contrat(config, infos, lettre, 3);
                        score(infos, 3);

                    }
                    config->grid[i][j]=' ';
                    config->grid[i+1][j]=' ';
                    config->grid[i+2][j]=' ';
                    printGrid(config, j, i);
                    printGrid(config, j, i+1);
                    printGrid(config, j, i+2);
                    n=1;
                }
        }
    }
    return n;
}
