#include "Repo.h"

typedef struct {
	MyList *medicamente;
	MyList *undoList;
}ServiceMed;

/*
Creeaza ServiceMed
*/
ServiceMed creeazaService();

/*
Distruge service
*/
void destroyService(ServiceMed* serv);

/*
Sorteaza lista crescator/descrescator in functie de nume,cantitate
*/
void sortareMed(ServiceMed *serv, int reversed, int criteriu);

/*
Adauga un medicament in lista.
*/
int adaugaMed(ServiceMed *serv, char * nume, int concentratie, int cantitate);
/*
Sterge un medicament din lista.
*/
int stergeMed(ServiceMed *serv, int cod);
/*
Returneaza elemntele care au ca prima litera o litera data.
*/
MyList *filtrareNume(MyList *serv, char * litera);

/*
Returneaza elementele ce au stocul mai mare decat un numar dat.
*/
MyList *filtrareCantitate(MyList *serv, int cantitate);
/*
Returneaza toate medicamentele dupa anumite criterii
*/
MyList *getMedicamente(ServiceMed *serv, int ok,char* litera, int cantitate);

/*
Reface ultima operatie.
*/
int undo(ServiceMed *serv);

int modificaMed(ServiceMed *serv,int cod ,char *nume, int concentratie);
void testAdaugaMed();
void testFiltreazaMed();
void testStergeMed();
void testModificaMed();
void testSortareMed();

void testUndo();
