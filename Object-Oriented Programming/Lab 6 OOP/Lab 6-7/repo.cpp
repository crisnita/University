#include "repo.h"
#include "movies.h"
#include <assert.h>
#include <iostream>

// searches for a movie and returns its position
int Repository::search_movie_repo(const string& title) {
	for (int i = 0; i < (int) this->all.size(); i++)
		if (this->all[i].get_title() == title) {
			return i;
		}
	return -1;
}

// adds a movie to the list. throws an exception if it already exists
Movie Repository::add(const Movie& m) {
	string title = m.get_title();
	if (search_movie_repo(title) == -1) {
		all.push_back(m);
		return m;
	}
	throw(RepoException("Filmul exista deja!\n"));
}

// deletes a movie from the list. throws an exception if it doesn't exist
Movie Repository::del(const string& title) {
	int poz = search_movie_repo(title);
	if (poz < 0) {
		throw(RepoException("Filmul nu exista!\n"));
	}
	Movie to_ret = this->all[poz];
	this->all.erase(this->all.begin() + poz);
	return to_ret;
}

// modifies a movie and returns it
Movie Repository::mod(const Movie& m, const string& title, const string& genre, const int year, const string& actor) {
//	int poz = -1;
	for (size_t i = 0; i < this->all.size(); i++) {
		if (this->all[i].get_title() == title) {
			this->all[i] = m;
			return m;
		}
	}
	throw(RepoException("Filmul nu exista!\n"));
}

// searches for a movie and returns it. throws exception if it doesn't exist
Movie Repository::search(const string& title) {
	for (size_t i = 0; i < this->all.size(); i++) {
		if (this->all[i].get_title() == title) {
			return this->all[i];
		}
	}
	throw(RepoException("Filmul nu exista!\n"));
}

/*
returneaza toate filmele salvate
*/
const vector<Movie>& Repository::getAll() const noexcept {
	return all;
}
