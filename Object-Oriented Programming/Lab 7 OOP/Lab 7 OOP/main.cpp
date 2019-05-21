#include "service.h"
#include "validator.h"
#include "repository.h"
#include "console.h"
//#include <assert.h>
//#include "tests.h"

int main() {
	// Validator validator;
	//testAll();
	Repository repository;
	Validator validator;
	Service service{ repository, validator };
	UI console{ service };
	console.show_ui();
	return 0;
}
