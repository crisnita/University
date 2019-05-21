#include "validator.h"

void Validator::validate(const Movie& m) {
	vector<string> msgs;
	if (m.get_year() < 0) msgs.push_back("An negativ!!!");
	if (msgs.size() > 0) {
		throw ValidateException(msgs);
	}
}