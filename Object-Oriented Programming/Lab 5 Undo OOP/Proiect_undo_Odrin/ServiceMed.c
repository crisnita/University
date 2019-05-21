#include<string.h>
#include<assert.h>
#include<stdlib.h>

#include"ServiceMed.h"
#include"MySort.h"

/*
Creeaza ServiceMed
*/
ServiceMed creeazaService() {
	ServiceMed serv;
	serv.medicamente = creeazaLista(destroyMedicament);
	serv.undoList = creeazaLista(destroy);
	return serv;
}

/*
Distruge service
*/
void destroyService(ServiceMed* serv) {
	destroy(serv->medicamente);
	destroy(serv->undoList);
}

/*
Adauga un medicament in lista.
*/
int adaugaMed(ServiceMed *serv, char * nume, int concentratie, int cantitate) {
	Medicament *m = creeazaMedicament(dim(serv->medicamente)+1, nume, concentratie, cantitate);
	int ok = valideazaMedicament(m);
	if (ok == 0) {
		destroyMedicament(m);
		return -1;// medicamentul nu este valid.
	}
	MyList* undo = copieLista(serv->medicamente,copieMedicament);
	for (int i = 0; i < dim(serv->medicamente); i++) {
		Medicament *rez = get(serv->medicamente, i);
		if (strcmp(m->nume, rez->nume) == 0 && m->concentratie == rez->concentratie)
		{
			rez->cantitate += m->cantitate;
			set(serv->medicamente, i, rez);
			destroyMedicament(m);
			add(serv->undoList, undo);
			return 1; // Cantitatea produsului existent a crescut.
		}
	}
	add(serv->medicamente, m);
	add(serv->undoList, undo);
	return 0; // medicamentul a fost adaugat;
	
}
/*
Returneaza elemntele care au ca prima litera o litera data.
*/
MyList* filtrareNume(MyList *list, char litera[1]) {
	MyList *lista_noua = creeazaLista(destroyMedicament);
	for (int i = 0; i < dim(list); i++) {
		Medicament *m = get(list, i);
		
		if (litera[0] == m->nume[0])
			add(lista_noua, copieMedicament(m));
	}
	return lista_noua;
}

/*
Returneaza elementele ce au stocul mai mare decat un numar dat.
*/
MyList* filtrareCantitate(MyList *list, int cantitate) {
	MyList *lista_noua = creeazaLista(destroyMedicament);
	for (int i = 0; i < dim(list); i++) {
		Medicament *m = get(list, i);
		if (m->cantitate >= cantitate)
			add(lista_noua, copieMedicament(m));
	}
	
	return lista_noua;

}
/*
Returneaza toate medicamentele dupa anumite criterii
*/
MyList* getMedicamente(ServiceMed *serv, int ok ,char* litera, int cantitate) {
	if (ok == 0)
		return filtrareNume(serv->medicamente, litera);
	if(ok ==1)
		return filtrareCantitate(serv->medicamente, cantitate);
	return copieLista(serv->medicamente,copieMedicament);
}

/*
Comparam numele a 2-a medicamente
*/
int cmpNume(Medicament *m1, Medicament *m2) {
	return strcmp(m1->nume, m2->nume);
}

/*
Comparam cantitatea a 2-a medicamente
*/
int cmpCantitate(Medicament *m1, Medicament *m2) {
	if (m1->cantitate > m2->cantitate)
		return 1;
	if (m1->cantitate < m2->cantitate)
		return -1;
	return 0;
}


/*
Sorteaza lista
*/

void sortareMed(ServiceMed *serv, int reversed,int criteriu) {
	if (reversed != 0 && reversed != 1)
		return;
	if (criteriu == 0) {
		sortare(serv->medicamente, cmpNume, reversed);
		return;
	}
	else if(criteriu == 1) {
		sortare(serv->medicamente, cmpCantitate, reversed);
	}
}
/*
Sterge un medicament din lista.
*/
int stergeMed(ServiceMed *serv, int cod) {
	MyList *undo = copieLista(serv->medicamente, copieMedicament);
	int ok = delete(serv->medicamente, cod);
	if (ok == 0)
		add(serv->undoList, undo);
	else 
		destroy(undo);
	return ok;
}
/*
Modifica un element dat.
*/
int modificaMed(ServiceMed *serv, int cod, char *nume, int concentratie) {
	Medicament *m = creeazaMedicament(cod, nume, concentratie, -1);
	for (int i = 0; i < dim(serv->medicamente); i++) {
		Medicament *m1 = get(serv->medicamente, i);
		if (m1->cod == m->cod) {
			MyList *undo = copieLista(serv->medicamente, copieMedicament);
			m->cantitate = m1->cantitate;
			set(serv->medicamente, i, copieMedicament(m));
			destroyMedicament(m1);
			destroyMedicament(m);
			add(serv->undoList, undo);
			return 0;
		}
	}
	destroyMedicament(m);
	return -1;

}

int undo(ServiceMed *serv) {
	if (serv->undoList->lg == 0) {
		return -1; // nu se mai poate face operatia undo
	}
	MyList* l = stergeUltimul(serv->undoList);
	destroy(serv->medicamente);
	serv->medicamente = l;
	return 0;
}

void testAdaugaMed() {
	ServiceMed serv = creeazaService();
	assert(dim(serv.medicamente) == 0);
	int ok = adaugaMed(&serv, "abc", 10, 15);
	assert(ok == 0);
	assert(dim(serv.medicamente) == 1);
	Medicament *m = get(serv.medicamente, 0);
	assert(m->cod == 1);
	assert(m->cantitate == 15);

	ok = adaugaMed(&serv, "abc", 10, 1);
	assert(ok == 1);
	assert(dim(serv.medicamente) == 1);
	m = get(serv.medicamente, 0);
	assert(m->cod == 1);
	assert(m->cantitate == 16);

	ok = adaugaMed(&serv, "", 0, -1);
	assert(ok == -1);
	assert(dim(serv.medicamente) == 1);
	m = get(serv.medicamente, 0);
	assert(m->cod == 1);
	assert(m->cantitate == 16);

	ok = adaugaMed(&serv, "", 0, -1);
	assert(ok == -1);
	assert(dim(serv.medicamente) == 1);
	m = get(serv.medicamente, 0);
	assert(m->cod == 1);
	assert(m->cantitate == 16);

	ok = adaugaMed(&serv, "abc", 0, -1);
	assert(ok == -1);
	assert(dim(serv.medicamente) == 1);
	m = get(serv.medicamente, 0);
	assert(m->cod == 1);
	assert(m->cantitate == 16);

	ok = adaugaMed(&serv, "abc", 25, -1);
	assert(ok == -1);
	assert(dim(serv.medicamente) == 1);
	m = get(serv.medicamente, 0);
	assert(m->cod == 1);
	assert(m->cantitate == 16);

	destroyService(&serv);


}
void testFiltreazaMed() {
	ServiceMed serv = creeazaService();
	assert(dim(serv.medicamente) == 0);
	int ok = adaugaMed(&serv, "abc", 10, 15);
	assert(ok == 0);
	assert(dim(serv.medicamente) == 1);

	ok = adaugaMed(&serv,"acb", 10, 35);
	assert(ok == 0);

	ok = adaugaMed(&serv, "bcc", 10, 25);
	assert(ok == 0);
	
	assert(dim(serv.medicamente) == 3);
	MyList *list1 = getMedicamente(&serv, 0, "a", -1);
	assert(dim(list1) == 2);
	Medicament *m1 = get(list1, 0);
	assert( m1->cod== 1);
	m1 = get(list1, 1);
	assert(m1->cod == 2);
	destroy(list1);

	list1 = getMedicamente(&serv, 1, "a", 16);
	assert(dim(list1) == 2);
	m1 = get(list1, 0);
	assert(m1->cod == 2);
	m1 = get(list1, 1);
	assert(m1->cod == 3);
	destroy(list1);

	list1 = getMedicamente(&serv, 2, "a", 16);

	assert(dim(list1) == 3);
	m1 = get(list1, 0);
	assert(m1->cod == 1);
	m1 = get(list1, 1);
	assert(m1->cod == 2);
	m1 = get(list1, 2);
	assert(m1->cod == 3);
	destroy(list1);

	destroyService(&serv);


}

void testStergeMed() {
	ServiceMed serv = creeazaService();
	assert(dim(serv.medicamente) == 0);
	int ok = adaugaMed(&serv, "abc", 10, 15);
	assert(ok == 0);
	assert(dim(serv.medicamente) == 1);

	ok = adaugaMed(&serv,  "acb", 10, 35);
	assert(ok == 0);

	ok = adaugaMed(&serv,  "bcc", 10, 25);
	assert(ok == 0);

	assert(dim(serv.medicamente) == 3);

	ok = stergeMed(&serv, 1);
	assert(ok == 0);
	
	assert(dim(serv.medicamente) == 2);

	ok = stergeMed(&serv, 2);
	
	assert(ok == 0);
	assert(dim(serv.medicamente) == 1);

	ok = stergeMed(&serv, 3);
	assert(ok == 0);
	assert(dim(serv.medicamente) == 0);

	ok = stergeMed(&serv, 5);
	assert(ok == -1);
	assert(dim(serv.medicamente) == 0);

	destroyService(&serv);

}

void testModificaMed() {
	ServiceMed serv = creeazaService();
	
	assert(dim(serv.medicamente) == 0);
	int ok = adaugaMed(&serv,"abc", 10, 15);
	assert(ok == 0);
	assert(dim(serv.medicamente) == 1);

	ok = modificaMed(&serv, 1,"bca", 20);
	assert(ok == 0);
	
	assert(dim(serv.medicamente) == 1);
	Medicament *m = get(serv.medicamente, 0);
	
	assert(strcmp(m->nume, "bca") == 0);
	assert(m->concentratie == 20);

	ok = modificaMed(&serv, 4, "bca", 20);
	assert(ok == -1);
	assert(dim(serv.medicamente) == 1);

	
	destroyService(&serv);

}

void testSortareMed() {
	ServiceMed serv = creeazaService();
	assert(dim(serv.medicamente) == 0);
	int ok = adaugaMed(&serv, "abc", 10, 15);
	assert(ok == 0);
	assert(dim(serv.medicamente) == 1);

	ok = adaugaMed(&serv, "acb", 10, 35);
	assert(ok == 0);

	ok = adaugaMed(&serv, "bcc", 10, 25);
	assert(ok == 0);

	assert(dim(serv.medicamente) == 3);

	sortareMed(&serv, 0, 0);
	Medicament *m1 = get(serv.medicamente, 0);
	assert(m1->cod == 1);
	

	m1 = get(serv.medicamente, 1);
	assert(m1->cod == 2);


	m1 = get(serv.medicamente, 2);
	assert(m1->cod == 3);
	

	sortareMed(&serv, 1, 0);

	m1 = get(serv.medicamente, 0);
	assert(m1->cod == 3);
	

	m1 = get(serv.medicamente, 1);
	assert(m1->cod == 2);
	

	m1 = get(serv.medicamente, 2);
	assert(m1->cod == 1);
	

	

	sortareMed(&serv, 0, 1);

	m1 = get(serv.medicamente, 0);
	assert(m1->cod == 1);
	

	m1 = get(serv.medicamente, 1);
	assert(m1->cod == 3);
	

	m1 = get(serv.medicamente, 2);
	assert(m1->cod == 2);
	

	sortareMed(&serv, 1, 1);

	m1 = get(serv.medicamente, 0);
	assert(m1->cod ==2);
	

	m1 = get(serv.medicamente, 1);
	assert(m1->cod == 3);
	

	m1 = get(serv.medicamente, 2);
	assert(m1->cod == 1);
	

	destroyService(&serv);

}

void testUndo() {
	ServiceMed serv = creeazaService();
	int ok = adaugaMed(&serv, "abc", 10, 10);
	assert(ok == 0);

	ok = adaugaMed(&serv, "bbc", 10, 10);
	assert(ok == 0);

	ok = adaugaMed(&serv, "cbc", 10, 10);
	assert(ok == 0);

	ok = adaugaMed(&serv, "dbc", 10, 10);
	assert(ok == 0);

	assert(dim(serv.medicamente) == 4);
	
	ok = undo(&serv);
	assert(ok == 0);
	assert(dim(serv.medicamente) == 3);

	ok = undo(&serv);
	assert(ok == 0);
	assert(dim(serv.medicamente) == 2);

	ok = undo(&serv);
	assert(ok == 0);
	assert(dim(serv.medicamente) == 1);

	ok = undo(&serv);
	assert(ok == 0);
	assert(dim(serv.medicamente) == 0);

	ok = undo(&serv);
	assert(ok == -1);
	assert(dim(serv.medicamente) == 0);

	destroyService(&serv);
}