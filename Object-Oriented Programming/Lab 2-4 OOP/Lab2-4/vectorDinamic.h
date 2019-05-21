#pragma once
#include "Student.h"
//typedef Student TElem;

typedef struct {
	Student* elems;
	int len;
	int capacity;
} VectorDinamic;

// create empty list
VectorDinamic createEmpty();

// destroy list
void destroy(VectorDinamic* lst);

// add Student
void add(VectorDinamic* lst, Student s);

// get an element from the list
Student get(VectorDinamic* v, int poz);

// get size
int size(VectorDinamic* v);

// modifies a student
void set_stud(VectorDinamic* lst, int id, Student* s);

// deletes an element from the vector
void deleteFromVector(VectorDinamic* lst, int id);

// suprascrie un element

void suprascrie(VectorDinamic* lst, int x, int y);

// swaps two elements

//void swap(VectorDinamic* lst, int x, int y);