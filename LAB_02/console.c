#pragma warning(disable : 4996);
#include <stdio.h>
#include <string.h>
#include "repository.h"
#include "validation.h"
#include "service.h"
#include "entitati.h"


void print(repo l)
{
	/*
	   Functie care afiseaza  elementele din lista de medicamente
	*/
	if (l.lungime > 0)
	{
		for (int i = 0; i < l.lungime; i++)
			//print_medicine(l.elemente[i]);
		{
			printf("Nume %s", l.elemente[i].nume);
			printf(" Cod unic %i", l.elemente[i].cod_unic);
			printf(" Cantitate %i", l.elemente[i].cantitate);
			printf(" Concentratie %f", l.elemente[i].concentratie);
			printf("\n");
		}
		printf("\n");
	}
}
void meniu()
{
	/*
	   Functie care va afisa optiunile care pot fi alese
	   Nu returneaza nimic
	*/
	printf("\n");
	printf("1.Adauga medicament.\n");
	printf("2.Afiseaza medicamente.\n");
	printf("3.Actualizeaza medicament.\n");
	printf("4.Sterge aparitia unui medicament.\n");
	printf("5.Sorteaza dupa nume si cantitate.\n");
	printf("6.Afiseaza medicamentele care incep cu o anumita litera.\n");
	printf("7.Medicamentele cu o cantitate mai mica decat cantitatea data.\n");
	printf("0.Exit\n");
}


repo add_medicament(repo lista)
{
	/*
	   Functia care adauga un element in vector(lista de medicamente)
       Returneaza lista modificata, iar daca elementul nu e valid, se afiseaza un mesaj prin care se mentioneaza ca adaugarea nu a avut loc
	*/
	char nume[30];
	char concentratie[30];
	char cod_unic[30], cantitate[30];
	medicament m;
	printf("Numele medicament: ");
	scanf("%s", nume);

	printf("Cod unic: ");
	scanf("%s", &cod_unic);

	printf("Cantitate: ");
	scanf("%s", &cantitate);

	printf("Concentratie: ");
	scanf("%s", &concentratie);

	nume[strlen(nume)] = '\0';

	if (validator(lista, nume, cod_unic, concentratie, cantitate)>0)
	{
		return adauga_medicament(lista, creeaza_med(nume, cod_unic, cantitate, concentratie));
	}
	else
	{
		printf("ELEMENTUL NU A PUTUT FI ADAUGAT!");
		return lista;
	}
}

repo actualizare_med(repo l)
{
	/*
	   Functie care actualizeaza un medicament 
	   Returneaza lista modificata
	*/
	char nume[30];
	float  concentratie;
	int cod_unic, cantitate;
	int index;
	medicament m;
	printf("Cod unic dupa care sa se caute medicamentul: ");
	scanf("%i", &cod_unic);

	index = cauta_medicament_dupa_cod_unic(l, cod_unic);
	if (index == -1)
	{
		printf("Medicamentul care doreste sa se modifice nu a fost gasit");
	}
	else
	{
		printf("Numele medicament: ");
		scanf("%s", nume);

		printf("Concentratie: ");
		scanf("%f", &concentratie);

		printf("Cantitate: ");
		scanf("%i", &cantitate);

		nume[strlen(nume)] = '\0';
		l = actualizare_medicament(l, index, nume, concentratie, cantitate);
	}

	return l;
}
repo sterge_medicamente(repo l)
{
	/*
	    Functie care sterge aparitiile unui medicament din stoc
		Returneaza lista modificata
	*/
	char nume[30];
	int index;
	printf("Numele medicament care sa se stearga: ");
	scanf("%s", nume);
	nume[strlen(nume)] = '\0';
	index = cauta_medicament_dupa_nume(l, nume);
	while (index != -1)
	{
		l = sterge_element(l, index);
		index = cauta_medicament_dupa_nume(l, nume);
	}
	printf("Aparitiile medicamentului s-au eliminat");
	return l;
}

repo consola_ordonare_dupa_nume_si_cantitate(repo l)
{
	/*
	   Functia ordoneaza lista dupa nume si cantitate
	*/
	ordonare_dupa_nume_si_cantitate(l);
	printf("Lista a fost sortata!\n");
}
void controler_filtrare_dupa_litera(repo l)
{
	/*
	    Functie care afiseaza toate medicamentele care incep cu o litera anume
	*/
	char a[100], letter;
	repo m;
	printf("Litera este: ");
	scanf("%s", &a);
	letter = a[0];
	m = filtrare_dupa_litera(l, letter);
	print(m);
}
void controler_filtrare_dupa_cantitate(repo l)
{
	/*
	    Functie care afiseaza medicamentele din stoc care se gasesc intr-o cantitate mai mica decat cea data
	*/
	int a;
	repo m;
	printf("Cantitatea este: ");
	scanf("%i", &a);
	m = filtrare_dupa_cantitate(l, a);
	print(m);
}
void optiuni() {
	repo l = create_repo();
	int n = 1;
	while (1) {
		meniu();
		printf("Alege optiunea: \n");
		scanf("%d", &n);
		switch (n)
		{
		case 1:l = add_medicament(l); break;
		case 2:print(l); break;
		case 3: l = actualizare_med(l); break;
		case 4: l = sterge_medicamente(l); break;
		case 5: l = ordonare_dupa_nume_si_cantitate(l); printf("Lista a fost sortata!\n"); break;
		case 6: controler_filtrare_dupa_litera(l); break;
		case 7:controler_filtrare_dupa_cantitate(l); break;
		case 0:return 0; break;
		default:printf("Optiunea nu este corecta!!");
			break;
		}

	}
}