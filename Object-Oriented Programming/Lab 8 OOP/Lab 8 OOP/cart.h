#pragma once
#include "movies.h"

#include <vector>
#include <string>

using namespace std;

class Cart {
private:
	vector<Movie> allCart;

public:

	Cart() = default;

	// nu permitem copierea de obiecte
	Cart(const Cart& ot) = delete;

	// adauga un film in cos
	Movie add(const Movie& m);

	// cauta un film si returneaza indexul 
	int search_movie_cart(const string& title);

	// sterege toate filmele din cos
	void del_all();

	// returneaza toata lista de cumparaturi
	const vector<Movie>& getAllCart() const noexcept;
	
};

// class for cart exceptions
class CartException {
public:
	CartException(const string& message) : msg(message) {}
	~CartException() {}

	string getMessage() const { return(msg); }
private:
	string msg;
};