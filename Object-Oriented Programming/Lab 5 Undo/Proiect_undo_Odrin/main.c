#include<stdio.h>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h> 
#include "Medicament.h"
#include "Repo.h"
#include "ServiceMed.h"
#include "MySort.h"
void testAll() {
	testCreateDestroy();
	testCopiereLista();
	testCreeazaLista();
	testIterareLista();
	testResize();
	testAdaugaMed();
	testFiltreazaMed();
	testStergeMed();
	testModificaMed();
	testSortareMed();
	testUndo();
	/*
	
	
	
	



	
	 
	
	
	
	*/
}

void citireMedicamente(ServiceMed * serv) {
	

	printf("Nume:");
	char nume[30];
	scanf_s("%s", nume, sizeof(nume));
	printf("Concentratie:");
	int concentratie;
	scanf_s("%d", &concentratie);
	printf("Cantitate:");
	int cantitate;
	scanf_s("%d", &cantitate);
	int ok = adaugaMed(serv, nume, concentratie, cantitate);
	switch (ok) {
	case -1:
		printf("Date invalide!\n");
		break;
	case 0:
		printf("Produsul a fost adaugat!\n");
		break;
	case 1:
		printf("Produs deja existent.Cantitatea a fost modificata.\n");
		break;
	default:
		break;
	}
}

void afisareMedicamente(ServiceMed *serv) {
	MyList *list = getMedicamente(serv, 1,"", 0);
	printf("ID	Nume	Concentratie	Cantitate\n");
	printf("_________________________________________\n");
	for (int i = 0; i < dim(list); i++) {
		Medicament *m = get(list, i);
		printf("%d.	%s		%dg		%d\n", m->cod, m->nume, m->concentratie, m->cantitate);
	}
	printf("__________________________________________\n");
	printf("len: %d\n", dim(list));
	destroy(list);
}


void filtrareMedicamente(ServiceMed *serv) {
	int cmd;
	printf("[1]. Dupa prima litera.\n[2]. Dupa cantitate.\n");
	scanf_s("%d", &cmd);
	if (cmd == 1) {
		char litera[10];
		printf("Litera:");
		scanf_s("%s", litera, sizeof(litera));
		MyList *l = getMedicamente(serv,0, litera, -1);
		printf("ID	Nume	Concentratie	Cantitate\n");
		printf("_________________________________________\n");
		for (int i = 0; i < dim(l); i++) {
			Medicament *m = get(l, i);
			printf("%d.	%s		%dg		%d\n", m->cod, m->nume, m->concentratie, m->cantitate);
		}
		printf("__________________________________________\n");
		printf("len: %d\n", dim(l));
		destroy(l);
	}
	else {
		int ok;
		printf("Cantitate:");
		scanf_s("%d", &ok);
		MyList *l = getMedicamente(serv,1, "abca", ok);
		printf("ID	Nume	Concentratie	Cantitate\n");
		printf("_________________________________________\n");
		for (int i = 0; i < dim(l); i++) {
			Medicament *m = get(l, i);
			printf("%d.	%s		%dg		%d\n", m->cod, m->nume, m->concentratie, m->cantitate);
		}
		printf("__________________________________________\n");
		printf("len: %d\n", dim(l));
		destroy(l);
		
	}
}

void stergereMedicamente(ServiceMed *serv) {
	printf("Cod:");
	int cod;
	scanf_s("%d", &cod);
	int ok = stergeMed(serv, cod);
	if (ok == -1) {
		printf("Nu exista nici un medicament cu acest cod!\n");
		return;
	}
	printf("Medicamentul a fost sters.!\n");

}

void modificaMedicament(ServiceMed *serv) {
	int cod;
	char nume[30];
	int concentratie;
	printf("Cod:");
	scanf_s("%d", &cod);

	printf("Nume:");
	scanf_s("%s", nume, sizeof(nume));

	printf("Concentratie:");
	scanf_s("%d", &concentratie);

	int ok = modificaMed(serv, cod, nume, concentratie);
	if (ok == -1) {
		printf("Nu exista nici un medicament cu acest cod.\n");
		return;
	}
	printf("Medicamentul a fost modificat.\n");
}

void sorteazaMedicament(ServiceMed *serv) {
	int reversed;
	printf("Crescator/Descrescator(0/1):");
	scanf_s("%d", &reversed);

	int criteriu;
	printf("Sortare dupa: Nume/Cantitate(0/1):");
	scanf_s("%d", &criteriu);

	sortareMed(serv,reversed,criteriu);
	afisareMedicamente(serv);
}

void undoMed(ServiceMed *serv) {
	int ok = undo(serv);
	if (ok == -1)
		printf("Nu se mai pot reface operatii.\n");
	else
		afisareMedicamente(serv);
}
void run() {
	ServiceMed serv = creeazaService();
	int ruleaza = 1;
	while (ruleaza)
	{
		printf("[1] Adauga.\n[2] Printeaza.\n[3] Sterge\n[4] Modifica\n[5] Filtreaza\n[6] Sortare\n[7] Undo.\n[0] Exit.\n>>>");
		int cmd = 0;
		scanf_s("%d", &cmd);
		switch (cmd)
		{
		case 1:
			citireMedicamente(&serv);
			break;
		case 2:
			afisareMedicamente(&serv);
			break;
		case 3:
			stergereMedicamente(&serv);
			break;
		case 4:
			modificaMedicament(&serv);
			break;
		case 5:
			filtrareMedicamente(&serv);
			break;
		case 6:
			sorteazaMedicament(&serv);
			break;
		case 7:
			undoMed(&serv);
			break;
		case 0:
			ruleaza = 0;
			break;
		default:
			printf("Invalid command!!\n");
			break;
		}
	}
	destroyService(&serv);
}
int main() {
	testAll();
	run();
	_CrtDumpMemoryLeaks();//print memory leak
	
	return 0;
}