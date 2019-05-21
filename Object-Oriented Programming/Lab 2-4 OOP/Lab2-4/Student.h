#pragma once

#include <stdlib.h>
#include <string.h>

typedef struct {
	char* name1;
	char* name2;
	float score;
} Student;

/*
Create a new Student
*/
Student createStudent(char* name1, char* name2, float score);


void destroyStudent(Student* s);

/*
Getteri si setteri
*/
int get_name1(Student *s);

int get_name2(Student *s);

int get_score(Student *s);

void set_name1(Student* s, char *name1);

void set_name2(Student* s, char *name2);

void set_score(Student* s, float score);

// replaces a Student in the list
void set_student(Student* s, Student* t);


