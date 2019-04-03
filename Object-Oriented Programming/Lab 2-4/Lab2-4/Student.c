#include "Student.h"

#include <string.h>


// creates a student entity
Student createStudent(char* name1, char* name2, float score) {
	Student s;
	int nr_caractere = strlen(name1) + 1; // +1 de la \n
	s.name1 = malloc(nr_caractere * sizeof(char));
	strcpy(s.name1, name1);
	nr_caractere = strlen(name2) + 1;
	s.name2 = malloc(nr_caractere * sizeof(char));
	strcpy(s.name2, name2);
	s.score = score;
	return s;
}
/*
int get_name1(Student *s) {
	return s->name1;
}

int get_name2(Student *s) {
	return s->name2;
}

int get_score(Student *s) {
	return s->score;
}
void set_student(Student* s, Student* t) {
	s->name1 = t->name1;
	s->name2 = t->name2;
	s->score = t->score;
}*/
/*
void set_name1(Student* s, char *name1) {
	s->name1 = name1;
}

void set_name2(Student* s, char *name2) {
	s->name2 = name2;
}
	
void set_score(Student* s, float score) {
	s->score = score;
}*/

void destroyStudent(Student* s) {
	free(s->name1);
	free(s->name2);
	// we mark the destroyed student to avoid any accidental usage
	s->score = -1;
	s->name1 = NULL;
	s->name2 = NULL;
}