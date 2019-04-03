#include "vectorDinamic.h"
#include <string.h>
#include <stdlib.h>
#define INIT_CAPACITY (2)

// creates an empty list
VectorDinamic createEmpty() {
	VectorDinamic v;
	v.capacity = INIT_CAPACITY;
	v.len = 0;
	v.elems = malloc(INIT_CAPACITY * sizeof(Student));
	return v;
}

// destroys the dynamic vector
void destroy(VectorDinamic* v) {
	int i = 0;
	if (size(v) != 0) //am pus acest 'if' pentru ca uneori se intampla sa stergem toate elementele din vector, deci nu putem elibera componentele lui
		for (; i < v->len; i++)
			destroyStudent(&v->elems[i]);
	
	free(v->elems);
	v->elems = NULL;
	v->len = 0;
}

// get an element from the list
Student get(VectorDinamic* v, int poz) {
	return v->elems[poz];
}

// returns the size of the vector
int size(VectorDinamic* v) {
	return v->len;
}

// se aloca memorie aditionala pt vector
void resize(VectorDinamic* v) {
	int new_cap = 2 * v->capacity;
	Student* new_elems = malloc(new_cap * sizeof(Student));
	int i;
	for (i = 0; i < v->len; i++) {
		new_elems[i] = v->elems[i];
	}
	free(v->elems);
	v->elems = new_elems;
	v->capacity = new_cap;
}

// adaugam un element in vector
void add(VectorDinamic* v, Student elem) {
	if (v->capacity == v->len) {
		resize(v);
	}
	v->elems[v->len] = elem;
	v->len++;
}

/*
Updates a student
*/
void set_stud(VectorDinamic* lst, int id, Student* s) {
	destroyStudent(&lst->elems[id]);
	lst->elems[id].name1 = s->name1;
	lst->elems[id].name2 = s->name2;
	lst->elems[id].score = s->score;
}

/*
Suprascrie un element
*/
void suprascrie(VectorDinamic* lst, int x, int y) {
	lst->elems[x].name1 = lst->elems[y].name1;
	lst->elems[x].name2 = lst->elems[y].name2;
	lst->elems[x].score = lst->elems[y].score;
}

/*
Deletes an element from the vector and moves all the elements from its right one position to the left
*/
void deleteFromVector(VectorDinamic* lst, int id) {
	destroyStudent(&lst->elems[id - 1]);
	for (int i = id - 1; i < size(lst); i++) {
		suprascrie(lst, i, i + 1);
	}
	lst->len--;
	if (size(lst) == 0) {
		destroy(lst);
		*lst = createEmpty();
	}
}