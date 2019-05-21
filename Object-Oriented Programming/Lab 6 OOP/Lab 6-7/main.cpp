#include "service.h"
#include "validator.h"
#include "repo.h"
#include "console.h"
//#include <assert.h>
#include "tests.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

int main() {
	
	testAll();
	Repository repository;
	Validator validator;
	Service service{ repository, validator };
	UI console{service};
	console.show_ui();	

	_CrtDumpMemoryLeaks();
	return 0;
}
