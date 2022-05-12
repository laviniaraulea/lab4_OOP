#include <stdio.h>
#include <string.h>
#include <stdlib.h>    
#include "medicine.h"
#include "repo.h"
#include "service.h"
void tipareste_meniu()
{
	printf("\n");
	printf("1.Adauga medicament.\n");
	printf("2.Afiseaza medicamente.\n");
	printf("3.Actualizeaza medicament.\n");
	printf("4.Sterge aparitia unui medicament.\n");
	printf("5.Sorteaza dupa nume si cantitate.\n");
	printf("6.Afiseaza medicamentele care incep cu o anumita litera.\n");
	printf("7.Medicamentele cu o cantitate mai mica decat cantitatea data.\n");
	printf("8.Sortare dupa functia data.\n");
	printf("9.Exit\n");
}
void adauga_med_meniu(repo* l)
{
	char nume[100];
	char concentratie[30];
	char cod_unic[30], cantitate[30];
	medicine m;

	printf("Numele medicament(doar un cuvant, fara spatii): ");
	scanf_s("%s", nume, 100);

	printf("Cod unic: ");
	scanf_s("%s", cod_unic, 30);

	printf("Cantitate: ");
	scanf_s("%s", cantitate, 30);

	printf("Concentratie: ");
	scanf_s("%s", concentratie, 30);

//	int ok = validator(l, cod_unic, cantitate, concentratie);
//	if (ok>0)
	//{
		m = create_med(nume, cod_unic, cantitate, concentratie);
        adauga_med(l, m);
	//}
	//else
	//{
	//	printf("%s", "Medicamentul nu a putut fi adaugat!!\n");
	//	return l;
	//}
	
}
void actualizare_med(repo* l)
{
	char nume[30];
	char  concentratie[30];
	char cod_unic[30], cantitate[30];
	int index;
	printf("Cod unic dupa care sa se caute medicamentul: ");
	scanf_s("%s", cod_unic, 30);
	cod_unic[strlen(cod_unic) + 1] = '\0';
	int cod = atoi(cod_unic);
	index = cauta_medicament_dupa_cod_unic(l, cod);
	if (index == -1)
	{
		printf("Medicamentul care doreste sa se modifice nu a fost gasit");
	}
	else
	{
		printf("Numele medicament: ");
		scanf_s("%s", nume, 30);

		printf("Concentratie: ");
		scanf_s("%s", concentratie, 30);

		printf("Cantitate: ");
		scanf_s("%s", cantitate, 30);

		nume[strlen(nume)] = '\0';
		l = actualizare_medicament(l, index, nume, concentratie, cantitate);
	}
}
void sterge_medicamente(repo* l)
{
	/*
		Functie care sterge aparitiile unui medicament din stoc
		Returneaza lista modificata
	*/
	char nume[30];
	int index;
	printf("Numele medicament care sa se stearga: ");
	scanf_s("%s", nume, 30);
	nume[strlen(nume)] = '\0';
	index = cauta_medicament_dupa_nume(l, nume);
	while (index != -1)
	{
		l = sterge_element(l, index);
		index = cauta_medicament_dupa_nume(l, nume);
	}
	printf("Aparitiile medicamentului s-au eliminat");
}
void consola_ordonare_dupa_nume_si_cantitate(repo *l)
{
	/*
	   Functia ordoneaza lista dupa nume si cantitate
	*/
	ordonare_dupa_nume_si_cantitate(l);
	printf("Lista a fost sortata!\n");
}
void controler_filtrare_dupa_litera(repo *l)
{
	/*
		Functie care afiseaza toate medicamentele care incep cu o litera anume
	*/
	char b;
	printf("Litera este:");
	scanf_s(" %c", &b,1);
	//b = a[0];
	printf("%c", b);
	repo* m;
    m=filtrare_dupa_litera(l, b);
	tipareste_repo(m);
	free_repo(m);
}
void controler_ordonare_dupa_functie(repo *l)
{
	ordonare_dupa_functie(l, functie_comparare);
}
void controler_filtrare_dupa_cantitate(repo *l)
{
	/*
		Functie care afiseaza medicamentele din stoc care se gasesc intr-o cantitate mai mica decat cea data
	*/
	int a;
	repo* m;
	printf("Cantitatea este: ");
	scanf_s("%i", &a);
	m=filtrare_dupa_cantitate(l, a);
	tipareste_repo(m);
	free_repo(m);
}

int optiuni()
{
	char n;
	repo* l=create_repo();
	while (1) {
		tipareste_meniu();
		printf("Alege optiunea (un caracter ):\n");
		scanf_s(" %c",&n,1);
			switch (n)
			{
			case '1':adauga_med_meniu(l); break;
			case '2':tipareste_repo(l); break;
			case '3':actualizare_med(l); break;
			case '4': sterge_medicamente(l); break;
			case '5': ordonare_dupa_nume_si_cantitate(l); printf("Lista a fost sortata!\n"); break;
			case '6': controler_filtrare_dupa_litera(l); break;
			case '7':controler_filtrare_dupa_cantitate(l); break;
			case '8':controler_ordonare_dupa_functie(l); break;
			case '9':free_repo(l); return 0; break;
			default:printf("Optiunea nu este corecta!!");n=65; break;
			}
		}
}
