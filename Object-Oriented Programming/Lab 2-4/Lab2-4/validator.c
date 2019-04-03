#include "validator.h"

int validate(Student* s) {
	if (s->score > 100 || s->score < 0) return 0;
	return 1;
}
