#include "service.h"
#include <functional>
#include <algorithm>
#include <assert.h>
#include <iostream>
#include <algorithm>
#include <random> // std::default_random_engine
#include <chrono> // std::chrono::system_clock

using namespace std;

// adds a movie
Movie Service::addMovie(const string& title, const string& genre, const int& year, const string& actor) {
	Movie m{ title, genre, year, actor };
	val.validate(m);
	m = repo.add(m);
	return m;
}

// adds a movie in the cart
Movie Service::addCart(const string& title) {
	Movie m = repo.search(title);
	m = cart.add(m);
	return m;
}

// deletes all movies from the cart
void Service::del_all() {
	cart.del_all();
}

// deletes a movie
Movie Service::delMovie(const string& title) {
	Movie m = repo.del(title);
	return m;
}

// searches for a movies and returns it
Movie Service::searchMovie(const string& title) {
	Movie m = repo.search(title);
	return m;
}

// adds some random movies to the cart
vector<Movie> Service::random_cart(const int nrFilme) {
	vector<Movie> m = repo.getAll();
	vector<Movie> movies = m, aux;
	if (nrFilme > m.size()) {
		cout << "Nu putem pune mai multe filme decat avem in repository!\n";
	}
	auto seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::shuffle(movies.begin(), movies.end(), std::default_random_engine(seed));
	for (int i = 0; i < nrFilme; i++) {
		aux.push_back(movies[i]);
	}
	return aux;
}

// modifies a movie
void Service::modMovie(const string&title, const string& genre, const int& year, const string& actor) {
	Movie m{ title, genre, year, actor };
	val.validate(m);
	m = repo.mod(m, title, genre, year, actor);
}

// filters movies
vector<Movie> Service::filterMovies(const vector<Movie>& movies, const string& substr, const int& criteria) {
	vector<Movie> filtered;
	if (criteria == 1) {
		for (auto movie : movies) {
			if (movie.get_title().find(substr) != std::string::npos) {
				filtered.push_back(movie);
			}
		}
	}
	if (criteria == 2) {
		for (auto movie : movies) {
			if (std::to_string(movie.get_year()) == substr) {
				filtered.push_back(movie);
			}
		}
	}
	return filtered;
}

// compara 2 string-uri
int Service::cmp(string s1, string s2) {
	if (s1 == s2) return 0;
	int min;
	if (size(s1) < size(s2)) min = size(s1);
	else min = size(s2);
	for (int i = 0; i < min; i++) {
		if (s1[i] < s2[i]) return -1;
		else if (s1[i] > s2[i]) return 1;
	}
	if (min == size(s1)) return -1;
	return 1;
}

// sorts movies
vector<Movie> Service::sortMovies(const vector<Movie>& movies, const int& criteria) {
	vector<Movie> new_movies = movies;
	switch (criteria) {
		// sortam dupa titlu
	case 1:
		sort(new_movies.begin(), new_movies.end(), [&](const Movie& m1, const Movie& m2) {
			auto title1 = m1.get_title();
			auto title2 = m2.get_title();
			return cmp(title1, title2) <= 0;
		});
		break;
	case 2:
		sort(new_movies.begin(), new_movies.end(), [&](const Movie& m1, const Movie& m2) {
			auto actor1 = m1.get_actor();
			auto actor2 = m2.get_actor();
			return cmp(actor1, actor2) <= 0;
		});
		break;
	case 3:
		sort(new_movies.begin(), new_movies.end(), [](const Movie& m1, const Movie& m2) {
			auto year1 = m1.get_year();
			auto year2 = m2.get_year();
			return year1 < year2;
		});
		break;
	case 4:
		sort(new_movies.begin(), new_movies.end(), [&](const Movie& m1, const Movie& m2) {
			auto gen1 = m1.get_genre();
			auto gen2 = m2.get_genre();
			return cmp(gen1, gen2) <= 0;
		});
		break;
	default:
		break;
	}

	return new_movies;
}