#include <stdio.h>
#include <string.h>
#include "entitati.h"
#include <stdlib.h>]

medicament creeaza_med(char nume[], char cod_unic[30], char cantitate[30], char concentratie[30])
{
	medicament m;
	m.cantitate = atof(cantitate);
	m.cod_unic = atoi(cod_unic);
	m.concentratie = atof(concentratie);
	//m.nume = (char*)malloc(strlen(nume)+1);
	strcpy_s(m.nume, 20, nume);
	return m;
}