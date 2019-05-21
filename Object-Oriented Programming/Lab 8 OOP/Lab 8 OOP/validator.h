#pragma once
#include <string>
#include <vector>
#include "movies.h"
using namespace std;

class ValidateException {
	vector<string> exceptions;
public:
	explicit ValidateException(const vector<string>& exceptions) :exceptions{ exceptions } {}

	// getter
	const vector<string> get_errors() const { return exceptions; }
};


class Validator {
public:
	void validate(const Movie& m);
};