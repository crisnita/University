#include "test.h"
#include <stdlib.h>
#include <stdio.h>


void test_add(VectorDinamic *lst) {
	Student s = createStudent("Alex", "Mihai", 12);
	destroyStudent(&s);
	assert(size(lst) == 0);
	addStudent(lst, "Alex", "Mihai", 12);
	assert(size(lst) == 1);
	addStudent(lst, "Popa", "Andrei", 89);
	assert(size(lst) == 2);
	addStudent(lst, "X", "Y", 120);
	destroy(lst);
}

void test_modify(VectorDinamic *lst) {
	addStudent(lst, "Creanga", "Ion", 99);
	addStudent(lst, "Eminescu", "Mihai", 10);
//	Student s = get(lst, 0);
	assert(updateStud(lst, 1, "Creanga", "Ion", 98.5) == 1); // adaugare cu succes
	assert(updateStud(lst, 3, "Puya", "Caniga", 1) == 2); // nu exista id-ul 3
	assert(updateStud(lst, 2, "Becali", "Gigi", 420) == 0); // scorul nu poate fi 420
	destroy(lst);
}

void test_delete(VectorDinamic *lst) {
	addStudent(lst, "Creanga", "Ion", 99);
	addStudent(lst, "Eminescu", "Mihai", 10);
	assert(size(lst) == 2);
	int ret;
	ret = deleteStud(lst, 2);
	assert(ret == 1);
	assert(size(lst) == 1);
	ret = deleteStud(lst, 1);
	assert(ret == 1);
	assert(size(lst) == 0);
	ret = deleteStud(lst, 1);
	assert(ret == 0);
	destroy(lst);
}

void test_sorts(VectorDinamic *lst) {
	addStudent(lst, "Creanga", "Ion", 99);
	addStudent(lst, "Eminescu", "Mihai", 10);
	addStudent(lst, "Andrei", "Vasile", 45);
	sortName(lst);
	assert((int)lst->elems[0].score == 45);
	sortScore(lst);
	assert((int)lst->elems[2].score == 99);
	sortReverse(lst);
	assert((int)lst->elems[0].score == 99);
	destroy(lst);
}



void testAll() {
	VectorDinamic lst_test = createEmpty();
	test_add(&lst_test);

	lst_test = createEmpty();
	test_modify(&lst_test);

	lst_test = createEmpty();
	test_delete(&lst_test);

	lst_test = createEmpty();
	test_sorts(&lst_test);

	//lst_test = createEmpty();
	//test_repo(&lst_test);
}