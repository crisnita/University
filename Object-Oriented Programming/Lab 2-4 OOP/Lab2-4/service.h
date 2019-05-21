#include "VectorDinamic.h"

/*typedef struct {
	VectorDinamic allStudents;
} StudentList;*/



/*
Add a student to the list
*/
int addStudent(VectorDinamic* lst, char* name1, char* name2, float score);


VectorDinamic createStudentList();


/*
Update a student from the list
*/
int updateStud(VectorDinamic* lst, int id, char* name1, char* name2, float score);

/*
Get all the elements from the list
*/
VectorDinamic getAllStudents(VectorDinamic* lst);

/*
Destroys all students and frees the memory
*/
//void destroyAllStudents(StudentList* lst);

/*
Deletes a student
*/
int deleteStud(VectorDinamic* lst, int id);

/*
Sorts by name
*/
void sortName(VectorDinamic* lst);

/*
Sorts by score
*/
void sortScore(VectorDinamic* lst);


/*
Reverses the list
*/
void sortReverse(VectorDinamic* lst);

