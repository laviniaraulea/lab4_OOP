#pragma once
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "service.h"
#include "repo.h"
#include "medicine.h"
#include "validator.h"
#include <stdlib.h>


void test_adauga_medicament()
{
	/*
	   Functie test care verifica daca un medicament a fost adaugat
	*/
	repo* l1 = create_repo();
	medicine m;
	m = create_med("Paracetamol", "3", "12", "10");
	adauga_med(l1, m);
	assert(l1->elemente[0].cantitate == (int)12);
	assert(l1->elemente[0].concentratie == (float)10);
	assert(l1->elemente[0].cod_unic == 3);
	//free(l1.elemente[0]);
	free_repo(l1);
}
void  test_cauta_medicament_dupa_index()
{
	/*
		Functie test care verifica daca un medicament este cautat dupa index
	*/
	repo* l = create_repo();
	medicine m;
	medicine med;
	int l1, l2, l3;
	m = create_med("ibuprofen", "1", "12", "10");
	adauga_med(l, m);
	med = create_med("paracetamol", "2", "3", "4");
	adauga_med(l, med);
	l1 = cauta_medicament_dupa_cod_unic(l, 1);
	l2 = cauta_medicament_dupa_cod_unic(l, 2);
	l3 = cauta_medicament_dupa_cod_unic(l, 5);
	assert(l1 == 0);
	assert(l2 == 1);
	assert(l3 == -1);
	free_repo(l);
}
void test_sortare_dupa_functie()
{
	repo* l = create_repo();
	medicine m;
	medicine med;
	m = create_med("Marcel", "345", "123", "1234");
	adauga_med(l, m);
	med = create_med("dafgl", "3435", "3", "4");
	adauga_med(l, med);
	med = create_med("Marcel", "2", "3", "4");
	adauga_med(l, med);
	med = create_med("adafgl", "35", "213", "34");
	adauga_med(l, med);
	l = ordonare_dupa_functie(l, functie_comparare);
	//printf("%d", l.elemente[0].cod_unic);
	assert(l->elemente[0].cod_unic == 345);
	//assert(l.elemente[1].cod_unic == 35);
//	assert(l.elemente[2].cod_unic == 2);
	//assert(l.elemente[3].cod_unic == 345);
	free_repo(l);
}
void  test_cauta_medicament_dupa_nume()
{
	/*
		Functie test care verifica daca un medicament este cautat dupa nume
	*/
	repo* l = create_repo();
	medicine m;
	medicine med;
	int l1, l2, l3;
	m = create_med("Marcel", "345", "123", "1234");
	adauga_med(l, m);
	med = create_med("dafgl", "3435", "3", "4");
	adauga_med(l, med);
	l1 = cauta_medicament_dupa_nume(l, "Marcel");
	l2 = cauta_medicament_dupa_nume(l, "dafgl");
	l3 = cauta_medicament_dupa_nume(l, "dahfag");
	assert(l1 == 0);
	assert(l2 == 1);
	assert(l3 == -1);
	free_repo(l);
}
void  test_sterge_element()
{
	/*
	   Functie care verifica daca un medicament este sters din lista
	*/
	repo* l = create_repo();
	medicine m;
	medicine med;
	m = create_med("Marcel", "345", "123", "1234");
	adauga_med(l, m);
	med = create_med("dafgl", "3435", "3", "4");
	adauga_med(l, med);
	l = sterge_element(l, 0);
	assert(l->elemente[0].cod_unic == 3435);
	free_repo(l);
}
void test_actualizare_medicament()
{
	/*
	   Functie care testeaza functia actualizare_medicament
	*/
	repo* l1 = create_repo();
	medicine m;
	m = create_med("paracetamol", "3", "12", "10");
	adauga_med(l1, m);
	int index = cauta_medicament_dupa_cod_unic(l1, m.cod_unic);
	//char nume1[20];
	char concentratie1[30];
	char cantitate1[30];
	//strcpy(nume1, "Paracetamol");
	strcpy(concentratie1, "10");
	strcpy(cantitate1, "8");
	actualizare_medicament(l1, index, m.nume, concentratie1, cantitate1);
	assert(m.cantitate == 12);
	assert(m.concentratie == 10);
	free_repo(l1);
}
void test_ordonare_dupa_nume_si_cantitate()
{
	/*
	   Functie care verifica daca lista a fost ordonata dupa nume si cantitate
	*/
	repo* l = create_repo();
	medicine m;
	medicine med;
	m = create_med("Marcel", "345", "123", "1234");
	adauga_med(l, m);
	med = create_med("dafgl", "3435", "3", "4");
	adauga_med(l, med);
	med = create_med("Marcel", "2", "3", "4");
	adauga_med(l, med);
	med = create_med("adafgl", "35", "213", "34");
	adauga_med(l, med);
	l = ordonare_dupa_nume_si_cantitate(l);
	assert(l->elemente[0].cod_unic == 35);
	assert(l->elemente[1].cod_unic == 3435);
	assert(l->elemente[2].cod_unic == 2);
	assert(l->elemente[3].cod_unic == 345);
	free_repo(l);
}
void test_filtrare_dupa_litera()
{
	/*
	   Functie care verifica daca se gasesc medicamentele care incep cu o litera data
	*/
	repo* l = create_repo();
	medicine m;
	medicine med;
	m = create_med("ibuprofen", "1", "12", "10");
	adauga_med(l, m);
	med = create_med("paracetamol", "2", "3", "4");
	adauga_med(l, med);
	char a;
	repo* s;
	a = med.nume[0];
	s= filtrare_dupa_litera(l, a);
	assert(s->elemente[0].cod_unic == 2);;
	free_repo(l);
	free_repo(s);
}
void test_filtrare_dupa_cantitate()
{
	/*
	   Functie care verifica daca se gasesc medicamentele care au o cantitate mai mica decat cea data
	*/
	repo* l = create_repo();
	medicine m;
	medicine med;
	m = create_med("ibuprofen\0", "1", "12", "10");
	adauga_med(l, m);
	med = create_med("paracetamol\0", "2", "3", "4");
	adauga_med(l, med);
	int c = 4;
	repo * s;
	s = filtrare_dupa_cantitate(l, c);
	assert(s->elemente[0].cod_unic == 2);
	free_repo(l);
	free_repo(s);
}
void test_validation()
{
	repo* l1 = create_repo();
	medicine m = create_med("ibuprofen", "1", "12", "10");
	adauga_med(l1, m);
	assert(validator(l1,"3", "12", "10") > 0);
	double ok = validator(l1,"3", "68", "64");
	assert(ok > 0);
	ok = validator(l1,"1", "68", "64");
	assert(ok == 0);
	ok = validator(l1, "4", "fff8", "64");
	assert(ok == 0);
	free_repo(l1);
}

void all_test()

{
	/*
	   Functia apelata care contine toate testele
	*/
	test_sortare_dupa_functie();
	test_adauga_medicament();
	test_cauta_medicament_dupa_index();
	test_cauta_medicament_dupa_nume();
	test_sterge_element();
	test_ordonare_dupa_nume_si_cantitate();
	test_filtrare_dupa_litera();
	test_filtrare_dupa_cantitate();
	test_actualizare_medicament();
	test_validation();
}
