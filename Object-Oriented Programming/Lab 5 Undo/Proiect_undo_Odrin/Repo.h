#pragma once
#include "Medicament.h"
#include<string.h>
#include<stdlib.h>
//typedef void ElemType;
typedef void* ElemType;


/*
Functia de distrugere a unui obiect
*/
typedef void(*DestroyFct)(ElemType);

/*
Functia de copiere pt un obiect
*/

typedef ElemType(*CopyFct)(ElemType);
typedef struct {
	ElemType* elems;
	int lg;
	int cap; // capacitatea;
	DestroyFct dfnc;
}MyList;

/*
Creeaza o lista goala
*/
MyList* creeazaLista(DestroyFct fct);


/*
Sterge si returneaza ultimul element din lista
*/
ElemType stergeUltimul(MyList* l);
/*
Distruge lista
*/
void destroy(MyList *l);

/*
Returneaza un element din lista
in: poz --> pozitia elementului, trebuie sa fie valida.
out: elementul de pe pozitia poz.
*/
ElemType get(MyList *l, int poz);

/*
Modifica elementul de pe o pozitie data.
returneaza elementul initial.
*/
ElemType set(MyList* l, int poz,ElemType m);

/*
Returneaza numarul de elemente din lista.
*/
int dim(MyList* l);



/*
Alocam memorie daca este necesar.
*/
void alocareMemorie(MyList *l);
/*
Adauga un element in lista.

*/
void add(MyList *l, ElemType el);

/*
Creeaza o copie a listei pe care o returneaza.
*/
/*
Modifica elementul
*/

/*
Sterge un element din lista.
*/
int delete(MyList* l, int cod );
MyList *copieLista(MyList *l,CopyFct f);

void testCreeazaLista();
void testIterareLista();
void testCopiereLista();
void testResize();