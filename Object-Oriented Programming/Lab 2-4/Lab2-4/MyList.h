#pragma once
#include "Student.h"
typedef Student TElem;

typedef struct {
	TElem elems[100];
	int len;
} MyList;

// create empty list
MyList createEmpty();

// destroy list
void destroy(MyList* lst);

// add Student
void add(MyList* lst, TElem elem);

// get size
int size(MyList* lst);

// get an element
Student getElem(MyList* lst, int poz);