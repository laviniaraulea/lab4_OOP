#include "medicine.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int get_cod(medicine m)
{
	return m.cod_unic;
}
double get_concentratie(medicine m)
{
	return m.concentratie;
}
double get_cantitate(medicine m)
{
	return m.cantitate;
}
char* get_nume(medicine m)
{
	return m.nume;
}
void free_med(medicine m)
{
	free(m.nume);
}
void tipareste_med(medicine m)
{
	printf("Nume %s", m.nume);
	printf(" Cod unic %i", m.cod_unic);
	printf(" Cantitate %lf", m.cantitate);
	printf(" Concentratie %lf", m.concentratie);
	printf("\n");

}
medicine create_med(char name[], char cod_unic[], char cantitate[], char concentratie[])
{
	medicine m;
	m.nume = (char*)malloc(strlen(name) + 1);
	strcpy_s(m.nume, strlen(name)+1, name);
	m.cantitate = atof(cantitate);
	m.cod_unic = atoi(cod_unic);
	m.concentratie = atof(concentratie);

	return m;
}
medicine create_med_int(char* name, int cod_unic, double cantitate, double concentratie)
{
	medicine m;
	m.nume = (char*)malloc(strlen(name) + 1);
	strcpy_s(m.nume, strlen(name) + 1, name);
	m.cantitate = cantitate;
	m.cod_unic = cod_unic;
	m.concentratie = concentratie;

	return m;
}
