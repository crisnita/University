#pragma once
#include "Colectie.h"

class IteratorColectie {

	friend class Colectie;

private:
	int curent;
	const Colectie& con;

public:
	// returneaza un itereator pe colectie
	IteratorColectie(const Colectie& c);

	// muta iteratorul pe prima pozitie din colectie
	void prim();

	// muta iteratorul pe pozitia urmatoare
	void urmator();

	// muta iteratorul pe pozitia anterioara
	void inapoi();

	// ne returneaza true daca itereatorul este valid, false altfel
	bool valid() const;

	// ne returneaza elementul de pe pozitia curenta a iteratorului
	TElem element() const;
};
