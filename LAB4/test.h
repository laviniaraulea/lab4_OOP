#pragma once
/*
* Testeaza functia adauga_medicament din repo_farmacie
*/
void test_adauga_medicament();
/*
* Testeaza functia cauta_medicament_dupa_index() din repo_farmacie
*/
void  test_cauta_medicament_dupa_index();
/*
* Testeaza functia cauta_medicament_dupa_nume() din repo_farmacie
*/
void test_cauta_medicament_dupa_nume();
/*
* Testeaza functia sterge_element() din repo_farmacie
*/
void  test_sterge_element();
/*
* Testeaza functia ordonare_dupa_nume_si_cantitate() din service_farmacie
*/
void test_ordonare_dupa_nume_si_cantitate();
/*
* Ruleaza toate testele
*/
void test_filtrare_dupa_litera();
/*
   Testeaza daca gaseste medicamentele care incep cu o litera
*/
void test_filtrare_dupa_cantitate();
/*
   Testeaza daca gaseste medicamentele cu o cantitatea mai mica decat cea data
*/
void test_sortare_dupa_functie();
void all_test();