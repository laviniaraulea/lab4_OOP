#pragma once
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "validation.h"
#include "repository.h"
#include <windows.h>

int validator(repo l, char nume[30], char cod_unic[30], char concentratie[30], char  cantitate[30])
{
	/*
	   Functie care verifica ca valorile introduse sa respecte conditiile necesare
	*/
	int ok = 1,n;
	ok = atof(cantitate);
	ok = atof(concentratie);
	ok = atoi(cod_unic);
	if (ok > 0)
	{
		for (int i = 0; i < l.lungime; i++)
		{
			if ((l.elemente[i]).cod_unic == ok)
			{
				ok = 0;
			}
		}
	}
	return ok;
}