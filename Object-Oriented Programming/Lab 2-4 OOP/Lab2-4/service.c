#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

#include "service.h"
#include "validator.h"

/*
Add a Student to the list
*/
int addStudent(VectorDinamic* lst, char* name1, char* name2, float score) {
	Student s = createStudent(name1, name2, score);
	if (validate(&s) == 0) {
		destroyStudent(&s);
		return 0;
	}
	add(lst, s);
	return 1; // the program should get here if everything is gucci
}


/*
Updates an existing student
*/
int updateStud(VectorDinamic* lst, int id, char* name1, char* name2, float score) {
	Student s = createStudent(name1, name2, score);
	if (id > size(lst) || id < 1) {
		destroyStudent(&s);
		return 2;
	}
	if (validate(&s) == 0) {
		destroyStudent(&s);
		return 0;
	}
	
	set_stud(lst, id - 1, &s);
	return 1;
}

/*
Deletes a student
*/
int deleteStud(VectorDinamic* lst, int id) {
	if (id > size(lst) || id < 1)
		return 0;
	else {
		deleteFromVector(lst, id);
		return 1;
	}
}

/*
Swaps two students
*/
void swap(VectorDinamic* lst, int i, int j) {
	Student *s = malloc(sizeof(Student));
	*s = lst->elems[i];
	lst->elems[i] = lst->elems[j];
	lst->elems[j] = *s;
	free(s);
}

/*
Sorts by name
*/
void sortName(VectorDinamic* lst) {
	int ok = 0;
	while (ok == 0) {
		ok = 1;
		for (int i = 0; i < size(lst) - 1; i++) {
			if (strcmp(lst->elems[i].name1, lst->elems[i + 1].name1) > 0) {
				swap(lst, i, i + 1);
				ok = 0;
			}
		}
	}
}

void sortScore(VectorDinamic* lst) {
	int ok = 0;
	while (ok == 0) {
		ok = 1;
		for (int i = 0; i < size(lst) - 1; i++) {
			if (lst->elems[i].score > lst->elems[i + 1].score) {
				swap(lst, i, i + 1);
				ok = 0;
			}
		}
	}
}

void sortReverse(VectorDinamic* lst) {
	for (int i = 0; i < size(lst) / 2; i++)
		swap(lst, i, size(lst) - i - 1);
}
