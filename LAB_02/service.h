#pragma once
#include "repository.h"

repo ordonare_dupa_nume_si_cantitate(repo l);
/*
    Ordoneaza stocul de medicamente dupa nume, apoi dupa cantitate si il returneaza
*/

repo filtrare_dupa_litera(repo l, char a);
/*
    Creeaza o noua lista de medicamente care indeplinesc cerinta si o returneaza
*/

repo filtrare_dupa_cantitate(repo l, int a);
/*
    Creeaza o noua lista de medicamente care indeplinesc cerinta si o returneaza
*/