#pragma once

typedef struct {
	int cod;
	char* nume;
	int concentratie;
	int cantitate;
}Medicament;

/*
Creeaza un nou medicament
*/
Medicament* creeazaMedicament(int cod, char* nume, int concentratie, int cantitiate);

/*
Elibereaza memoria ocupata de obiectul Medicament
*/
void destroyMedicament(Medicament *m);

/*
Creeaza si returneaza o copie a medicamentului.
*/
Medicament* copieMedicament(Medicament *m);

/*
Valideaza datele medicamentului.
*/
int valideazaMedicament(Medicament *m);

/*
Seteaza o noua cantitate pentru un medicament dat.
*/
void setCantitate(Medicament *m, int nc);




/*
Compara concentratia a 2-a medicamente
*/
int cmpConcentratie(Medicament *m1, Medicament *m2);
/*
Returneaza cantitatea unui medicament dat.
*/
int getCantitate(Medicament *m);

void testCreateDestroy();
void testCmpConcentratie();