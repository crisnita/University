#pragma once
#include <utility>
//Colectie.h

using namespace std;

typedef int TElem;

typedef std::pair <TElem, TElem> TPereche;
	
typedef bool(*Relatie)(TElem, TElem);

bool rel(TElem, TElem);

class IteratorColectie;

class Colectie {
	friend class IteratorColectie;
private:
	/* aici e reprezentarea */

	int countElems; // numarul de elemente

	Relatie relatie;

	int cp; // capacitate
	TPereche* p;
	int* urm;
	int primul, primulLiber, ultimul;

	void initSpLiber();
	int aloca();
	void dealoca(int i);
	int creeazaNod(TElem e);

public:
	//constructorul implicit
	Colectie();

	//adauga un element in colectie
	void adauga(TElem e);

	//sterge o aparitie a unui element din colectie
	//returneaza adevarat daca s-a putut sterge
	bool sterge(TElem e);

	//verifica daca un element se afla in colectie
	bool cauta(TElem elem) const;

	//returneaza numar de aparitii ale unui element in colectie
	int nrAparitii(TElem elem) const;


	//intoarce numarul de elemente din colectie;
	int dim() const;

	//verifica daca colectia e vida;
	bool vida() const;

	//returneaza un iterator pe colectie
	IteratorColectie iterator() const;

	// destructorul colectiei
	~Colectie();

};