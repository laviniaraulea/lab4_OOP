#include <stdio.h>
#include <string.h>
#include "repo.h"
#include "medicine.h"


int functie_comparare(medicine med1, medicine med2)
{
	if (med1.concentratie > med2.concentratie)
		return 0;
	return 1;
}
repo* ordonare_dupa_functie(repo* l, int (*comparare)(medicine med1, medicine med2))
{
	for (int i = 0; i < l->lungime - 1; i++)
	{
		for (int j = i + 1; j < l->lungime; j++)
		{
			if (comparare(l->elemente[i], l->elemente[j]) > 0)
			{
				medicine m = l->elemente[i];
				l->elemente[i] = l->elemente[j];
				l->elemente[j] = m;
			}
				
		}
	}
	return l;
}

repo *ordonare_dupa_nume_si_cantitate(repo *l)
{
	for (int i = 0; i < l->lungime - 1; i++)
	{
		for (int j = i + 1; j < l->lungime; j++)
		{
			if (_stricmp(l->elemente[i].nume, l->elemente[j].nume) > 0)
			{
				medicine m = l->elemente[i];
				l->elemente[i] = l->elemente[j];
				l->elemente[j] = m;
			}
			else
			{
				if (strcmp(l->elemente[i].nume, l->elemente[i].nume) == 0)
					if (l->elemente[i].cantitate > l->elemente[j].cantitate)
					{
						medicine m = l->elemente[i];
						l->elemente[i] = l->elemente[j];
						l->elemente[j] = m;
					}
			}
		}
	}
	return l;
}
repo * filtrare_dupa_litera(repo* l, char a)
{
	repo* filtrat = create_repo();
	int j = 0;
	for (int i = 0; i < l->lungime; i++)
		if (l->elemente[i].nume[0] == a)
		{
			medicine m = create_med_int(get_nume(l->elemente[i]), get_cod(l->elemente[i]), get_cantitate(l->elemente[i]), get_concentratie(l->elemente[i]));
			adauga_med(filtrat, m);
				j++;
		}
	return filtrat;
}
repo * filtrare_dupa_cantitate(repo* l, int a)
{
	repo* filtrat = create_repo();
	int j = 0;
	for (int i = 0; i < l->lungime; i++)
		if (l->elemente[i].cantitate <= a)
		{
			medicine m = create_med_int(get_nume(l->elemente[i]), get_cod(l->elemente[i]), get_cantitate(l->elemente[i]), get_concentratie(l->elemente[i]));
			adauga_med(filtrat, m);
			j++;
		}
	return filtrat;
}


