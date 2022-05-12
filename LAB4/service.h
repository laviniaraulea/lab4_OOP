#pragma once
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "repo.h"
#include "medicine.h"
#pragma warning(disable : 4996)
int functie_comparare(medicine med1, medicine med2);
repo* ordonare_dupa_functie(repo* l, int (*comparare)(medicine med1, medicine med2));
repo* ordonare_dupa_nume_si_cantitate(repo* l);
repo* filtrare_dupa_litera(repo* l, char a);
repo* filtrare_dupa_cantitate(repo* l, int a);

