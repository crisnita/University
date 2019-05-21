#include <iostream>
#include "Colectie.h"
#include "IteratorColectie.h"
#include <stdexcept>
#include <exception>
#include <utility>

bool rel(TElem cheie1, TElem cheie2) {
	if (cheie1 <= cheie2)
		return true;
	return false;
}


/*
	Complexitate: teta(1)
	aloca memorie de indice i (intreg)
*/

int Colectie::aloca() {
	int i = this->primulLiber;
	if (i != -1) {
		this->primulLiber = this->urm[i];
	}
	return i;
}

/*
	Complexitate: teta(1)
	dealoca memoria de pe indicele i
*/
void Colectie::dealoca(int i) {
	this->urm[i] = this->primulLiber;
	this->primulLiber = i;
}



/*
	Complexitate: teta(n)
	initializare spatiu liber
*/
void Colectie::initSpLiber() {
	for (int i = 0; i < this->cp-1; i++) {
		this->urm[i] = i+1;
	}

	this->urm[this->cp - 1] = -1; // setam urm pt ultimul element ca fiind NIL

	this->primulLiber = 0; // setam pozitia catre primul element din tablou
}


/*
	Complexitate: O(1)
	initializeaza colectia
*/
Colectie::Colectie() {
	cp = 100;
	this->countElems = 0;


	this->p = new TPereche[cp];
	this->urm = new int[cp];

	this->primulLiber = -1;
	this->primul = -1;
	
	this->initSpLiber();
}


/*
	Complexitate: O(n) 
	creeaza un nod nou in cazul in care nu se poate folosi spatiul de la un nod anterior
*/
int Colectie::creeazaNod(TElem e) {

	if (this->primulLiber == -1) { // daca lista este plina
		// realoca
		// copiaza elemente + legaturi
		// reinitializeaza lista spartiu liber

		TPereche* newP = new TPereche[cp * 2];
		int* newU = new int[cp * 2];

		for (int i = 0; i < cp; i++) { // copiem tot ce avem deja existent in lista
			newP[i] = this->p[i];
			newU[i] = this->urm[i];
		}

		this->primulLiber = cp; // pozitionam primul liber pe prima pozitie din a doua jumatate a noului tablou

		for (int i = cp; i < cp * 2 - 1; i++) {
			newU[i] = i + 1;
		}

		newU[cp * 2 - 1] = -1;

		// actualizam capacitatea
		this->cp = this->cp * 2;

		// stergem fostul tablou si facem noua asociere
		delete[] this->p;
		delete[] this->urm;

		this->p = newP;
		this->urm = newU;
	}

	int i = this->aloca();
	this->p[i].first = e;
	this->p[i].second = 1;
	this->urm[i] = -1;
	return i;
}


// returneaza un itereator
// complexitate: teta(1)
IteratorColectie Colectie::iterator() const {
	return IteratorColectie(*this);
}

// complexitate: teta(1)
// destructor
Colectie::~Colectie() {
	delete this->p;
	delete this->urm;
}


// complexitate: O(n)
// cauta un element si returneaza daca acesta apare
bool Colectie::cauta(TElem e) const {
	int j = this->primul;
	bool gasit = 0;
	while (j != -1) {
		if (this->p[j].first == e) {
			gasit = 1;
			break;
		}
		j = this->urm[j];
	}
	return gasit;
}

// Complexitate: O(n)
// adauga un element (pune frecventa 1 daca acesta nu exista, altfel o incrementeaza)
void Colectie::adauga(TElem e) {
	if (this->cauta(e) == true) {
		int j = this->primul;
		while (j != -1) {
			if (this->p[j].first == e) {
				this->p[j].second++;
				break;
			}
			j = this->urm[j];
		}
		return;
	}

	int j = this->creeazaNod(e);
	if (this->primul == -1) {
		this->primul = j;
		this->ultimul = j;
		this->urm[j] = -1;
		this->countElems++;
		return;
	}

	// verificam daca trebuie sa adaugam inaintea primului 
	if (rel(e, this->p[this->primul].first)) { // daca elementul este mai mic decat primul element deja existent
		this->urm[j] = this->primul;
		this->primul = j;
		this->countElems++;
	}
	// verificam daca trebuie sa adaugam dupa ultimul element
	else if (rel(this->p[this->ultimul].first, e)) {
		this->urm[this->ultimul] = j;
		this->ultimul = j;
		this->countElems++;
	}
	
	// parcurgem lista pana cand putem adauga
	else {
		int q = this->primul, p;
		while (!rel(e, this->p[q].first)) {
			p = q; // tinem minte si elementul precedent
			q = this->urm[q]; // am gasit locul de inserat
		}
		this->urm[p] = j;		

		this->urm[j] = q;
		this->countElems++; 
	}
}


/*
	Complexitate: O(n)
	sterge un element din lista daca acesta are frecventa 1, altfel scade frecventa sa cu 1
*/
bool Colectie::sterge(TElem e) {
	if (this->cauta(e) == 0) // daca nu exista elementul
		return false;

	int j = this->primul;
	int previous = -1;
	while (j != -1) {
		if (this->p[j].first == e) { // am gasit nodul
			if (this->p[j].second > 1) { // cazul in care doar modificam frecventa
				this->p[j].second--;
				this->countElems--;
				return true;
			}

			if (j == this->primul) { // stergem primul nod
				this->primul = this->urm[j];
				this->countElems--;

				// doar ca sa fim siguri, marcam vechiul fost nod ca fiind un punct mort
				this->urm[j] = -1;
				return true;
			}

			if (j == this->ultimul) { // stergem ultimul nod
				this->ultimul = previous;
				this->countElems--;
				this->urm[previous] = -1;
				return true;
			}

			// daca am ajuns aici, inseamna ca trebuie sa stergem nodul si sa ii conectam pe cel precedent si urmator
			this->countElems--;
			this->urm[previous] = this->urm[j];
			this->urm[j] = -1;
			return true;
		}
		previous = j;
		j = this->urm[j];
	}
}

/*
	Complexitate: O(n)
	returneaza numarul de aparitii pentru un element de tip TElem
*/
int Colectie::nrAparitii(TElem e) const {
	int j = this->primul;
	while (j != -1) {
		if (this->p[j].first == e) {
			return this->p[j].second;
		}
		j = this->urm[j];
	}
	return 0;
}

/*
	Complexitate: teta(n)
	returneaza dimensiunea totala a containerului
*/
int Colectie::dim() const {
	int j = this->primul;
	int sum = 0;
	while (j != -1) {
		sum += this->p[j].second;
		j = this->urm[j];
	}
	return sum;
}

/*
	Complexitate: teta(n)
	returneaza true daca avem container vid, false altfel 
	Obs: se foloseste de functia dim()
*/
bool Colectie::vida() const {
	if (this->dim() == 0) return true;
	return false;
}