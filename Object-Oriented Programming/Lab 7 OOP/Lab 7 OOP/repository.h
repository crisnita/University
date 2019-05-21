#pragma once
#include "movies.h"
#include "list.h"
#include <vector>
#include <string>

#define Node MyNode<Movie>

using namespace std;

class Repository {
private:
	MyList<MyNode<Movie>> all;

	//veifica daca exista deja filmul
	//bool exist(const Movie& m);

public:

	Repository() = default;

	// nu permitem copierea de obiecte
	Repository(const Repository& ot) = delete;

	// searches for a movie and returns its position in the list
	int search_movie_repo(const string& title);

	// adauga un film in lista. arunca exceptie daca acesta exista deja
	Movie add(const Movie& m);

	// sterge un film din lista. arunca exceptie daca nu exista un film cu acest nume
	Movie del(const string& title);

	// modifica un film din lista. arunca exceptie daca nu exista un film cu acest nume
	Movie mod(const Movie& m, const string& title, const string& genre, const int year, const string& actor);

	// cauta un film din lista si il returneaza
	Movie search(const string& title);

	// returneaza toate filmele salvate
	const MyList<MyNode<Movie>>& getAll() const noexcept;
};

// clasa pentru exceptiile din repo
class RepoException {
public:
	RepoException(const string& message) : msg(message) {}
	~RepoException() {}

	string getMessage() const { return(msg); }
private:
	string msg;
};