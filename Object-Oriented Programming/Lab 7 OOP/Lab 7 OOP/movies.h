#pragma once
#include <vector>
#include <algorithm>
#include "list.h"

using std::string;


class Movie {
private:
	string title;
	string genre;
	int year;
	string actor;

public:
	Movie() = default;

	// constructor class
	Movie(const string title, const string genre, const int year, const string actor);

	// getters
	string get_title() const {
		return title;
	}

	string get_genre() const {
		return genre;
	}

	int get_year() const {
		return year;
	}

	string get_actor() const {
		return actor;
	}

	// setters
	/*void set_title(const string& title);
	void set_genre(const string& genre);
	void set_year(const int &year);
	void set_actor(const string& actor);*/
};