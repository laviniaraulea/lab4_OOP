#include<stdio.h>
#include<string.h>
#include "repository.h"
#pragma warning(disable : 4996)
#include <stdlib.h>

repo resize(repo l)
{
	int new_cp;
	new_cp = l.cp * 2;
	medicament* new_elems;
	new_elems = malloc(sizeof(medicament) * new_cp);
	for (int i = 0; i < l.lungime; i++)
		new_elems[i]=l.elemente[i];
	free(l.elemente);
	l.elemente = new_elems;
	l.cp = new_cp;
	return l;
}

repo create_repo()
{
	repo farm;
	farm.lungime = 0;
	farm.cp = 3;
	farm.elemente = malloc(sizeof(medicament) * farm.cp);
	return farm;
}
void free_repo(repo l)
{
	//for (int i = 0; i < l.lungime; i++)
		//free(l.elemente[i].nume);
	free(l.elemente);
}
int cauta_medicament_dupa_cod_unic(repo l, int cod_unic)
{
	/*
       Cauta un element in lista de medicamente dupa idex si returneaza indexul
    */
	for (int i = 0; i < l.lungime; i++)
	{
		if (l.elemente[i].cod_unic == cod_unic)
			return i;
	}
	return -1;
}
repo adauga_medicament(repo l, medicament m)
{
	/*
		Adauga un medicament in lista de medicamente si returneaza lista
	*/
	if (l.lungime == l.cp)
	{
		l=resize(l);
	}
	l.elemente[l.lungime] = m;
	l.lungime += 1;
	return l;
}

int cauta_medicament_dupa_nume(repo l, char nume[])
{
	/*
       Cauta un element in lista dupa denumirea sa si ii returneaza indexul
    */
	for (int i = 0; i < l.lungime; i++)
	{
		if (!strcmp(l.elemente[i].nume, nume))
			return i;
	}
	return -1;
}

repo actualizare_medicament(repo l, int index, char nume[30], float concentratie, int cantitate)
{
	/*
	   Actualizeaza numele si concentratia elementului "index" din lista
   */
	strcpy(l.elemente[index].nume, nume);
	l.elemente[index].concentratie = concentratie;
	l.elemente[index].cantitate += cantitate ;
	return l;
}

repo sterge_element(repo l, int index)
{
	/*
	   Sterge un element din lista dupa pozitia sa si returneaza noua lista
	*/
	for (int i = index; i < l.lungime - 1; i++)
	{
		l.elemente[i] = l.elemente[i + 1];
	}
	l.lungime--;
	return l;
}

