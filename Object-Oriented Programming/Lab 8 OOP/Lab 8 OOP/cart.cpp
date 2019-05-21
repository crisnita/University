#include "cart.h"
#include "movies.h"
#include <iostream>

// adauga un film in carucior
Movie Cart::add(const Movie& m) {
	string title = m.get_title();
	if (search_movie_cart(title) == -1) {
		allCart.push_back(m);
		return m;
	}
	throw(CartException("Filmul exista deja!\n"));
}

// cauta un film si returneaza index-ul
int Cart::search_movie_cart(const string& title) {
	int i = 0;
	if (this->allCart.size() == 0)
		return -1;
	while (i <= (int) this->allCart.size()){
		if ((string) this->allCart[i].get_title() == (string) title) {
			return i;
		}
		i++;
	}
	return -1;
}

// sterge toate filmele din cos
void Cart::del_all() {
	this->allCart.clear();
}

// returneaza toata lista de cumparaturi
const vector<Movie>& Cart::getAllCart() const noexcept {
	return allCart;
}