#include "service.h"
#include "validator.h"
#include "repo.h"
#include "cart.h"
#include "console.h"
//#include <assert.h>
#include "tests.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

int main() {
	{
		//testAll();
		Repository repository;
		Cart cart;
		Validator validator;
		Service service{ repository, cart, validator };
		UI console{ service };
		console.show_ui();
	}
	_CrtDumpMemoryLeaks();
	return 0;
}
