#include <stdlib.h>
#include<assert.h>
#include "Repo.h"

/*
Creeaza o lista goala.
*/
MyList* creeazaLista(DestroyFct fct) {
	MyList *rez = malloc(sizeof(MyList));
	rez->lg = 0;
	rez->cap = 2;
	rez->elems = malloc(sizeof(ElemType)*rez->cap);
	rez->dfnc = fct;
	return rez;
}

/*
Distruge lista
*/
void destroy(MyList *l) {
	//dealocam elementele listei
	for (int i = 0; i < l->lg; i++) {
		l->dfnc(l->elems[i]);
	}
	free(l->elems);
	free(l);
}

/*
Sterge si returneaza ultimul element din lista
*/
ElemType stergeUltimul(MyList* l) {
	ElemType rez = l->elems[l->lg - 1];
	l->lg--;
	return rez;
}

/*
Returneaza un element din lista
in: poz --> pozitia elementului, trebuie sa fie valida.
out: elementul de pe pozitia poz.
*/
ElemType get(MyList *l, int poz) {
	return l->elems[poz];
}

/*
Modifica elementul de pe o pozitie data.
returneaza noul element.
*/
ElemType set(MyList* l, int poz, ElemType m) {
	ElemType rez = l->elems[poz];
	l->elems[poz] = m;
	return rez;
}




/*
Returneaza numarul de elemente din lista.
*/
int dim(MyList* l) {
	return l->lg;
}

/*
Alocam memorie daca este necesar.
*/
void alocareMemorie(MyList *l) {
	if (l->lg < l->cap) {
		//avem destula memorie
		return;
	}
	//alocam mai multa memorie
	ElemType *nElems = malloc(sizeof(ElemType)*(l->cap + 2));
	//copiem elementele
	for (int i = 0; i < l->lg; i++) {
		nElems[i] = l->elems[i];
	}
	// stergem vechea lista.
	free(l->elems);
	l->elems = nElems;
	l->cap += 2;
}

/*
Adauga un element in lista.

*/
void add(MyList *l, ElemType el) {
	alocareMemorie(l);
	l->elems[l->lg++] = el;
}
/*
Sterge un element din lista.
*/
int delete(MyList *l, int cod) {
	for (int i = 0; i < dim(l); i++) {
		Medicament *m = get(l, i);
		if (m->cod == cod) {
			destroyMedicament(m);
			l->elems[i] = l->elems[l->lg - 1];
			l->lg--;
			return 0;
		}
		
	}
	return -1;

}

/*
Creeaza o copie a listei pe care o returneaza.
*/
MyList* copieLista(MyList *l, CopyFct cf) {
	MyList *l1=creeazaLista(l->dfnc);
	for (int i = 0; i < l->lg; i++) {
		ElemType el = get(l, i);
		add(l1, cf(el));
	}
	return l1;
}



void testCreeazaLista() {
	MyList *l = creeazaLista(destroyMedicament);
	assert(dim(l) == 0);
	destroy(l);
}

void testIterareLista() {
	MyList *l = creeazaLista(destroyMedicament);
	add(l, creeazaMedicament(1, "abc", 14, 10));
	add(l, creeazaMedicament(2, "vcc", 10, 12));
	assert(dim(l) == 2);

	Medicament *m = get(l, 0);

	assert(m->cod == 1);
	assert(strcmp(m->nume, "abc") == 0);
	assert(m->cantitate == 10);
	assert(m->concentratie == 14);

	m = get(l, 1);

	assert(m->cod == 2);
	assert(strcmp(m->nume, "vcc") == 0);
	assert(m->cantitate == 12);
	assert(m->concentratie == 10);

	destroy(l);
	
}

void testCopiereLista() {
	MyList* l1 = creeazaLista(destroyMedicament);
	add(l1, creeazaMedicament(1, "abc", 10, 10));
	add(l1, creeazaMedicament(2, "abc", 10, 10));
	MyList *l2 = copieLista(l1,copieMedicament);
	assert(dim(l2) == 2);
	Medicament* m = get(l2, 0);
	assert(m->cod == 1);
	destroy(l1);
	destroy(l2);
}

void testResize() {
	MyList *l = creeazaLista(destroyMedicament);
	for (int i = 0; i < 10; i++) {
		add(l, creeazaMedicament(1, "abc", 15, 20));
	}

	assert(dim(l) == 10);
	destroy(l);


	

}