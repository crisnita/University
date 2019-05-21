#include "console.h"
#include "service.h"
#include "movies.h"

#include <iostream>
#include <string>


// adauga un element in UI
void UI::adauga_UI() {
	string title, genre, actor;
	int year;
	cout << "Dati titlul: ";
	cin >> title;
	cout << "Dati genul: ";
	cin >> genre;
	cout << "Dati anul: ";
	cin >> year;
	cout << "Dati actorul principal: ";
	cin >> actor;
	Movie m = service.addMovie(title, genre, year, actor);
	cout << "Filmul a fost adaugat cu succes!\n";
}

void UI::delete_UI() {
	string title;
	cout << "Dati titlul filmului pe care vreti sa il stergeti: ";
	cin >> title;
	Movie m = service.delMovie(title);
	cout << "Filmul a fost sters cu succes!\n";
}


// modifica un element din UI
void UI::modifica_UI() {
	string title, genre, actor;
	int year;
	cout << "Dati titlul filmului pe care vreti sa il modificati: ";
	cin >> title;
	cout << "Dati noul gen: ";
	cin >> genre;
	cout << "Dati noul an: ";
	cin >> year;
	cout << "Dati noul actor principal: ";
	cin >> actor;
	service.modMovie(title, genre, year, actor);
	cout << "Filmul a fost modificat cu succes!\n";
}

// cauta un element din UI
void UI::cauta_UI() {
	string title;
	cout << "Dati titlul filmului cautat: ";
	cin >> title;
	Movie m = service.searchMovie(title);
}


// afiseaza toate elementele din UI
void UI::printAll(const vector<Movie>& movies) {
	cout << "----------------------------------------\n\n";
	cout << "TITLU  |  GEN  |  AN  |  ACTOR PRINCIPAL\n\n";
	for (const auto& movie : movies) {
		cout << movie.get_title() << " " << movie.get_genre() << " " << movie.get_year() << " " << movie.get_actor() << '\n';
	}
	cout << "----------------------------------------\n\n";
}

void UI::filter_UI(const vector<Movie>& movies) {
	int criteria;
	cout << "Filtrati dupa: \n1. Titlu\n2. Anul aparitiei\n";
	cin >> criteria;
	if (criteria != 1 && criteria != 2)
		cout << "Criteriu invalid!\n";
	else {
		string substr;
		cout << "Dati secventa cautata: ";
		cin >> substr;
		vector<Movie> new_movies = service.filterMovies(movies, substr, criteria);
		printAll(new_movies);
	}
}

void UI::sort_UI(const vector<Movie>& movies) {
	cout << "Sortati dupa:\n1. Titlu\n2. Actor principal\n3. Anul aparitiei\n4. Gen\n";
	int criteria;
	cin >> criteria;
	if (criteria != 1 && criteria != 2 && criteria != 3 && criteria != 4) {
		cout << "Criteriu invalid!\n";
		return;
	}
	vector<Movie> new_movies = service.sortMovies(movies, criteria);
	printAll(new_movies);
}

void UI::show_ui() {
	for (;;) {
		cout << "1. Adauga \n2. Sterge \n3. Modifica \n4. Cauta \n5. Tipareste\n6. Filtreaza\n7. Sorteaza\n0. Exit\n";
		int cmd;
		cin >> cmd;
		try {
			switch (cmd) {
			case 1:
				adauga_UI();
				break;
			case 2:
				delete_UI();
				break;
			case 3:
				modifica_UI();
				break;
			case 4:
				cauta_UI();
			case 5:
				printAll(service.getAll());
				break;
			case 6:
				filter_UI(service.getAll());
				break;
			case 7:
				sort_UI(service.getAll());
				break;
			case 0:
				return;
			default:
				cout << "Comanda invalida!\n";
			}
		}
		catch (RepoException& err) {
			cout << err.getMessage();
		}
		catch (ValidateException&) {
			cout << "Anul este invalid!\n";
		}
	}
}
