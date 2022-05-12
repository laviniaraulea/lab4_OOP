#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "validator.h"
#include "repo.h"

double validator(repo *l,char cod_unic[30], char concentratie[30], char  cantitate[30])
{
	/*
	   Functie care verifica ca valorile introduse sa respecte conditiile necesare
	*/
	double ok = 1;
	int cod;

	if (atof(cantitate) * atof(concentratie) * atoi(cod_unic) == 0)
		ok = 0;
	if (ok!=0)
	{
		cod = atoi(cod_unic);
		for (int i = 0; i < l->lungime; i++)
		{
			if ((l->elemente[i]).cod_unic == cod)
			{
				ok = 0;
			}
		}
	}
	return ok;
}