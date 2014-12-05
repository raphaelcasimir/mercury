#include "header.h"
//Auteurs : Marianne Champalier et Raphaël CASIMIR ING1 TD2

int main()
{
    t_config *config;
    t_infos *infos;
    config=(t_config*)malloc(sizeof(t_config));
    infos=(t_infos*)malloc(sizeof(t_infos));
    srand(time(NULL));

    configInit(config,infos);
    infos->vies=5;
    menu(config, infos);

    return 0;
}
