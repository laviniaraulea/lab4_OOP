#ifndef ENTITATI_H_
#define ENTITATI_H_

/*
    Cream entitatea medicament
*/

typedef struct
{
	int cod_unic;
	char nume[30];
	float cantitate;
	float concentratie;
}medicament;

medicament creeaza_med(char nume[], char cod_unic[30], char cantitate[30], char concentratie[30]);
#endif