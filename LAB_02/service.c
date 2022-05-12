#include <stdio.h>
#include <string.h>
#include "repository.h"
#include "entitati.h"
#pragma warning(disable : 4996)
void swap(medicament* a, medicament* b)
{
	/*
	    Functie care interschimba pozitia a 2 medicamente
	*/
	medicament c;
	c = *a;
	*a = *b;
	*b = c;

}
repo ordonare_dupa_nume_si_cantitate(repo l)
{
	/*
	    Functie care ordoneaza medicamentele dupa nume si cantitate
	*/
	for (int i = 0; i < l.lungime - 1; i++)
	{
		for (int j = i + 1; j < l.lungime; j++)
		{
			if (stricmp(l.elemente[i].nume, l.elemente[j].nume) > 0)
				swap(&l.elemente[i], &l.elemente[j]);
			else
			{
				if (strcmp(l.elemente[i].nume, l.elemente[i].nume) == 0)
					if (l.elemente[i].cantitate > l.elemente[j].cantitate)
						swap(&l.elemente[i], &l.elemente[j]);
			}
		}
	}
	return l;
}
repo filtrare_dupa_litera(repo l, char a)
{
	/*
	    Functie care cauta medicamentele care incep cu o litera data
		Returneaza o noua lista cu medicamentele gasite
	*/
	repo filtrat=create_repo();
	filtrat.lungime = 0;
	int j = 0;
	for (int i = 0;i < l.lungime;i++)
		if (l.elemente[i].nume[0] == a)
		{
			filtrat.elemente[j] = l.elemente[i];
			j++;
			filtrat.lungime++;
		}
	return filtrat;
}
repo filtrare_dupa_cantitate(repo l, int a)
{
	/*
	    Functie care cauta medicamentele ce se gasesc intr-o cantitate mai mica decat cea data
		Returneaza o noua lista cu medicamentele gasite
	*/
	repo filtrat=create_repo();
	filtrat.lungime = 0;
	int j = 0;
	for (int i = 0; i < l.lungime; i++)
		if (l.elemente[i].cantitate <= a)
		{
			filtrat.elemente[j] = l.elemente[i];
			j++;
			filtrat.lungime++;
		}
	return filtrat;
}
