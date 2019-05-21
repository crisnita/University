#pragma once
#include "repo.h"
#include "validator.h"
#include "movies.h"


class Service {
private:
	Repository& repo;
	Validator& val;

public:
	Service(Repository& repo, Validator& val) noexcept :repo{ repo }, val{ val }{
	}

	Service(const Service& ot) = delete;

	// returns all movies
	const vector<Movie>& getAll() const noexcept {
		return repo.getAll();
	}

	// adds a movie. throws an exception if it cannot be added or is invalid
	Movie addMovie(const string& title, const string& genre, const int& year, const string& actor);

	// deletes a movie. throws an exception if it doesn't exist

	Movie delMovie(const string& title);

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

