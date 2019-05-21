#include "MySort.h"
#include "ServiceMed.h"
#include <assert.h>

/*
Sortare 
*/

void sortare(MyList *l, FunctieComparare fct, int reversed) {
	int ok = 0;
	while (ok == 0) {
		ok = 1;
		for (int i = 0; i < dim(l) - 1; i++) {
			Medicament *m1 = get(l, i);
			Medicament *m2 = get(l, i + 1);
			if (fct(m1,m2) > 0 && reversed == 0) {
				set(l, i, m2);
				set(l, i + 1, m1);
				ok = 0;

			}
			else if (fct(m2,m1) > 0 && reversed == 1) {
				set(l, i, m2);
				set(l, i + 1, m1);
				ok = 0;
			}
		}
	}
}

