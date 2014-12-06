#include "header.h"
//Auteurs : Marianne Champalier et Raphaël CASIMIR ING1 TD2

/// N'essayez pas de compiler ce programme sans la librairie pdcurses ou curses (#include <curses.h>).
/// Ouvez directement le fichier binaire mercury.exe dans le dossier Release ou gameMatrix.exe dans Debug.
/// La dll nécessaire est présente donc executez juste le .exe

int main()
{
    t_config *config;
    t_infos *infos;
    config=(t_config*)malloc(sizeof(t_config));
    infos=(t_infos*)malloc(sizeof(t_infos));
    srand(time(NULL));

    configInit(config,infos);
    infos->vies=5;
    menu(config, infos); // Dès que l'on sort du sous-programme menu, on quitte le jeu entier.

    return 0;
}
