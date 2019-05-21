#include <iostream>
#include "IteratorColectie.h"

using namespace std;

class Colectie;

// Complexitate: teta(1)
// initializare iterator
IteratorColectie::IteratorColectie(const Colectie& c) : con(c) {
	this->curent = c.primul;
}


// Complexitate: teta(1)
// 'curent' va referi primul element din container
void IteratorColectie::prim() {
	this->curent = this->con.primul;
}

// Complexitate: teta(1)
// muta iteratorul pe pozitia urmatoare
void IteratorColectie::urmator() {
	if (this->curent == -1) 
		throw exception();

	this->curent = this->con.urm[this->curent];
}

// Complexitate: O(n)
// muta iteratorul pe pozitia anterioara
void IteratorColectie::inapoi() {
	if (this->curent == this->con.primul)
		throw exception();

	int j = con.primul;
	while (j != -1) {
		int previous = j;
		j = this->con.urm[j];
		if (j == this->curent) {
			this->curent = previous;
			break;
		}
	}
}

// Complexitate: teta(1)
// ne arata daca iteratorul se afla pe o pozitie valida
bool IteratorColectie::valid() const {
	return this->curent != -1;
}

// Complexitate: teta(1)
// returneaza elementul curent din iteratie
TElem IteratorColectie::element() const {
	if (this->curent == -1)
		throw exception();

	return this->con.p[this->curent].first;	
}