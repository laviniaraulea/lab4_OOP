#pragma once
#include "medicine.h"
typedef struct {
	int lungime;
	medicine* elemente;
	int cp;
}repo;

void resize(repo *l);
repo* create_repo();
repo *free_repo(repo *l);
void tipareste_repo(repo *l);
repo * adauga_med(repo* l, medicine m);
repo* actualizare_medicament(repo *l, int index, char nume[30], char concentratie[30], char cantitate[30]);
int cauta_medicament_dupa_cod_unic(repo *l, int cod_unic);
int cauta_medicament_dupa_nume(repo *l, char nume[]);
repo* sterge_element(repo* l, int index);