#include "console.h"
#include "tests.h"
#include "service.h"
#include "repo.h"
#include <iostream>


void testAll() {
	Repository rep;
	Validator val;
	Service srv{ rep, val };

	/*Movie m1 = srv.addMovie("John Wick", "Action", 2014, "Keanu Reeves");
	Movie m2 = srv.addMovie("Mr. Bean", "Comedy", 2008, "Mr. Bean?");
	assert(size(srv.getAll()) == 2);
	assert(srv.getAll()[0].get_title() == m1.get_title());
	assert(srv.getAll()[1].get_actor() == m2.get_actor());

	Movie m3 = srv.delMovie("John Wick");
	assert(size(srv.getAll()) == 1);

	Movie m4 = srv.searchMovie("Mr. Bean");
	assert(m4.get_genre() == m2.get_genre());
	assert(rep.search_movie_repo("Mr. Bean") == 0);

	try {
		Movie m5 = srv.addMovie("Mr. Bean", "Action", 1999, "Donald Duck");
	}
	catch (const RepoException& err) {}
	assert(size(srv.getAll()) == 1);

	try {
		Movie m6 = srv.delMovie("Deadpool");
	}
	catch (const RepoException& err) {}
	assert(size(srv.getAll()) == 1);

	Movie m7 = srv.delMovie("Mr. Bean");
	assert(size(srv.getAll()) == 0);

	try {
		Movie m8 = srv.searchMovie("Morometii");
	}
	catch (const RepoException& err) {}

	m1 = srv.addMovie("John Wick", "Action", 2014, "Keanu Reeves");
	m2 = srv.addMovie("Mr. Bean", "Comedy", 2008, "Mr. Bean?");
	srv.modMovie("Mr. Bean", "Tragedy", 1999, "Mr. Bean!");
	assert(srv.getAll()[1].get_genre() == "Tragedy");

	try {
		srv.modMovie("Pulp Fiction", "Drama", 1994, "Motherfucker");
	}
	catch (const RepoException& err) {}

	try {
		m3 = srv.addMovie("The Interview", "Wtf", -200, "a terrorist");
	}
	catch (const ValidateException& err) {}

	vector<Movie> movies = srv.filterMovies(srv.getAll(), "a", 1);
	assert(size(movies) == 1);
	movies = srv.filterMovies(srv.getAll(), "1999", 2);
	assert(size(movies) == 1);

	assert(srv.cmp("a", "b") == -1);
	assert(srv.cmp("b", "a") == 1);
	assert(srv.cmp("aa", "aa") == 0);
	assert(srv.cmp("aaaa", "aa") == 1);

	movies = srv.getAll();
	vector<Movie> new_movies = srv.sortMovies(movies, 1);
	assert(new_movies[0].get_title() == m1.get_title());

	new_movies = srv.sortMovies(movies, 2);
	assert(new_movies[0].get_title() == m1.get_title());

	new_movies = srv.sortMovies(movies, 3);
	assert(new_movies[1].get_title() == m1.get_title());

	new_movies = srv.sortMovies(movies, 4);
	assert(new_movies[0].get_title() == m1.get_title());*/
}