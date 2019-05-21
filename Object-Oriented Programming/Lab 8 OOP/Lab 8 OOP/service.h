#pragma once
#include "repo.h"
#include "cart.h"
#include "validator.h"
#include "movies.h"
#include <iostream>


class Service {
private:
	Repository& repo;
	Cart& cart;
	Validator& val;

public:
	Service(Repository& repo, Cart& cart, Validator& val) noexcept :repo{ repo }, cart{ cart }, val{ val }{
	}

	Service(const Service& ot) = delete;

	// returns all movies
	const vector<Movie>& getAll() const noexcept {
		return repo.getAll();
	}

	// adds a movie. throws an exception if it cannot be added or is invalid
	Movie addMovie(const string& title, const string& genre, const int& year, const string& actor);

	// adds a movie in the cart and throws an exception blablabla
	Movie addCart(const string& title);

	// deletes a movie. throws an exception if it doesn't exist
	Movie delMovie(const string& title);

	// deletes all movies from the cart
	void del_all();

	// adds some random movies to the cart
	vector<Movie> random_cart(const int nrFilme);

	// returns all elements from the cart
	const vector<Movie>& getAllCart() const noexcept {
		return cart.getAllCart();
	}

	// searches for a movie
	Movie searchMovie(const string& title);

	// modifies a movie. throws an exception if a movie with the input title does not exist or the new data is invalid
	void modMovie(const string& title, const string& genre, const int& year, const string& actor);

	// filters movies
	vector<Movie> filterMovies(const vector<Movie>& movies, const string& substr, const int& criteria);

	// sorts movies
	vector<Movie> sortMovies(const vector<Movie>& movies, const int& criteria);

	int cmp(string s1, string s2);
};

