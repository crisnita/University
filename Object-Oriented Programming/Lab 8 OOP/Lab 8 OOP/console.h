#pragma once
#include "service.h"
#include "movies.h"

class UI {
	Service& service;

	// adds an element to the list
	void adauga_UI();

	// modifies an element
	void modifica_UI();

	// deletes an element
	void delete_UI();

	// searches for an element
	void cauta_UI();

	// prints all movies
	void printAll(const vector<Movie>& movies);

	// filters movies
	void filter_UI(const vector<Movie>& movies);

	// sorts movies
	void sort_UI(const vector<Movie>& movies);

	// adds a movie in the cart
	void adauga_cart_UI();

	// deletes all movies from the cart
	void sterge_cart_UI();

	// genereaza un cart random
	void genereaza_cart_UI();

public:
	// constructor
	UI(Service& service) noexcept :service{ service } {
	}

	// nu permitem copierea obiectelor
	UI(const UI& ot) = delete;

	// starts the program
	void show_ui();
};