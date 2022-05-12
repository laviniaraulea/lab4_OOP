#pragma once
#include "entitati.h"

typedef struct {
	int lungime;
	medicament* elemente;
	int cp;
}repo;

repo resize(repo l);

repo create_repo();
void free_repo(repo l);

void print(repo l);
/*
  Afiseaza lista de medicamente
*/
repo adauga_medicament(repo l, medicament m);
/*
 Adauga un medicament in repolista
 */
repo actualizare_medicament(repo l, int index, char nume[30], float concentratie, int cantitate);
/*
 Actualizeaza un medicament cu noile valori dupa index
*/
int cauta_medicament_dupa_cod_unic(repo l, int cod_unic);
/*
 Cauta un meidcament in lista de medicamente dupa codul unic
 return:index
*/
int cauta_medicament_dupa_nume(repo l, char nume[]);
/*
 Cauta un meidcament in lista de medicamente dupa nume
 return:index
*/

repo sterge_element(repo l, int index);
/*
 Sterge un element din lista dupa index
*/