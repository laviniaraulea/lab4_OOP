#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include "repo.h"

void tipareste_repo(repo* l)
{
	for (int i = 0; i < l->lungime; i++)
	{
		tipareste_med(l->elemente[i]);
	}
	printf("\n");
}

repo* create_repo()
{
	repo* farm = malloc(sizeof(repo));
	farm->cp = 3;
	farm->elemente = (medicine*)malloc(sizeof(medicine) * farm->cp);
	farm->lungime = 0;
	return farm;
}
repo *free_repo(repo* l)
{
	for (int i = 0; i < l->lungime; i++)
	{
		free_med(l->elemente[i]);
	}
	free(l->elemente);
	free(l);
	return l;
}
repo* adauga_med(repo* l, medicine m)
{
	if (l->lungime == l->cp)
	{
		resize(l);
	}
	l->elemente[l->lungime] = m;
	l->lungime += 1;
	return l;
}
void resize(repo* l)
{
	int new_cp;
	new_cp = l->cp * 2;
	medicine* new_elems;
	new_elems = malloc(sizeof(medicine) * new_cp);
	for (int i = 0; i < l->lungime; i++)
		new_elems[i] = l->elemente[i];
	free(l->elemente);
	l->elemente = new_elems;
	l->cp = new_cp;
}

repo* actualizare_medicament(repo *l, int index, char nume[30], char concentratie[30], char cantitate[30])
{
	strcpy_s(l->elemente[index].nume,strlen(nume)+1, nume);
	l->elemente[index].concentratie = atof(concentratie);
	l->elemente[index].cantitate += atof(cantitate);
	return l;
}
int cauta_medicament_dupa_cod_unic(repo *l, int cod_unic)
{
	for (int i = 0; i < l->lungime; i++)
	{
		if (l->elemente[i].cod_unic == cod_unic)
			return i;
	}
	return -1;
}
int cauta_medicament_dupa_nume(repo* l, char nume[])
{
	for (int i = 0; i < l->lungime; i++)
	{
		if (!strcmp(l->elemente[i].nume, nume))
			return i;
	}
	return -1;
}
repo* sterge_element(repo *l, int index)
{
	free_med(l->elemente[index]);
	for (int i = index; i < l->lungime - 1; i++)
	{
		l->elemente[i] = l->elemente[i + 1];
	}
	l->lungime--;
	return l;
}