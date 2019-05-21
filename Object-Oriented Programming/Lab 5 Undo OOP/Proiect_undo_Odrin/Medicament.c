#include <string.h>
#include<stdlib.h>
#include<assert.h>
#include "Medicament.h"

/*
Creeaza un nou medicament
*/
Medicament* creeazaMedicament(int cod, char* nume, int concentratie, int cantitate) {
	Medicament *m = malloc(sizeof(Medicament));
	int nrC = strlen(nume) + 1;
	m->nume = malloc(sizeof(char) * nrC);
	strcpy_s(m->nume, nrC, nume);
	m->cod = cod;
	m->concentratie = concentratie;
	m->cantitate = cantitate;
	return m;
}

/*
Elibereaza memoria ocupata de obiectul medicament
*/
void destroyMedicament(Medicament * m) {
	free(m->nume);
	free(m);
}

/*
Creeaza si returneaza o copie a medicamentului.
*/
Medicament* copieMedicament(Medicament *m) {
	return creeazaMedicament(m->cod, m->nume, m->concentratie, m->cantitate);
	
}


/*
Valideaza datele medicamentului.
*/
int valideazaMedicament(Medicament *m) {
	if (strcmp(m->nume, "") == 0)
		return 0; // nume invalid
	if (m->concentratie <= 0)
		return 0; // concentratie invalida.
	if (m->cantitate <= 0)
		return 0; // cantitate invalida.
	return 1; //totul este ok.
}


/*
Compara numele a 2-a medicamente
*/



void testCreateDestroy() {
	Medicament *m = creeazaMedicament(1, "Parasinus", 25, 1);
	assert(m->cod == 1);
	assert(strcmp(m->nume, "Parasinus") == 0);
	assert(m->concentratie == 25);
	assert(m->cantitate == 1);

	destroyMedicament(m);
	
}

