#pragma once
#ifndef ENTITATI_H_
#define ENTITATI_H_


typedef struct {
	int cod_unic;
	char *nume;
	double cantitate;
	double concentratie;
}medicine;

void tipareste_med(medicine m);
medicine create_med(char name[], char cod_unic[], char cantitate[], char concentratie[]);
medicine create_med_int(char *name,int cod_unic, double cantitate, double concentratie);
void free_med(medicine m);
int get_cod(medicine m);
double get_concentratie(medicine m);
double get_cantitate(medicine m);
char* get_nume(medicine m);
#endif