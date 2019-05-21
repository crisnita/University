#include <stdio.h>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include "test.h"
#include "service.h"
//#include "MyList.h"


/*void testAll() {
	test_addStudent();
}*/


/*
Adds a participant
*/
void readStudent(VectorDinamic* lst) {
	char name1[100], name2[100];
	float score;
	printf("Scrie nume: ");
	scanf("%s", name1);
	printf("Scrie prenume: ");
	scanf("%s", name2);
	printf("Scrie scor: ");
	scanf("%f", &score);

	int ret = addStudent(lst, name1, name2, score);
	if (ret == 1)
		printf("Studentul a fost adaugat.\n");
	else
		printf("Date invalide!\n");
}


/*
Updates a participant
*/
void updateStudent(VectorDinamic* lst) {
	char name1[100], name2[100];
	float score;
	int id;
	printf("Scrie ID-ul participantului: ");
	scanf("%d", &id);
	printf("Scrie noul nume: ");
	scanf("%s", name1);
	printf("Scrie noul prenume: ");
	scanf("%s", name2);
	printf("Scrie noul scor: ");
	scanf("%f", &score);

	int ret = updateStud(lst, id, name1, name2, score);
	if (ret == 1)
		printf("Studentul a fost modificat.\n");
	else if (ret == 2)
		printf("Studentul nu exista.\n");
	else
		printf("Date invalide!\n");
}

void deleteStudent(VectorDinamic* lst) {
	printf("Introduceti ID-ul studentului: ");
	int id;
	scanf("%d", &id);
	int ret = deleteStud(lst, id);
	if (ret == 1)
		printf("Studentul a fost sters!\n");
	else
		printf("Nu exista un student cu acest ID!\n");
}

/*
Shows all participants
*/
void printStudents(VectorDinamic* lst) {
	printf("Studentii sunt:\n");
	for (int i = 0; i < size(lst); i++) {
		Student s = get(lst, i);
		printf("Studentul %d: %s %s, %0.2f\n", i + 1, s.name1, s.name2, s.score);
	}
}

void filterStudents(VectorDinamic* lst) {
	printf("1 - Toti studentii cu scorul mai mic decat o suma data\n2 - Toti studentii cu numele incepand cu o anumita litera\n");
	float nr;
	scanf("%f", &nr);
	if (nr == 1) {
		printf("Dati un scor: ");
		int sc;
		scanf("%d", &sc);
		printf("Studentii sunt:\n");
		int poz = 0;
		for (int i = 0; i < size(lst); i++) {
			Student s = get(lst, i);
			if (s.score < sc)
				printf("Studentul %d: %s %s, %0.2f\n", ++poz, s.name1, s.name2, s.score);
		}
	}
	if (nr == 2){
		printf("Dati o litera: ");
		char c;
		scanf(" %c", &c);
		printf("Studentii sunt:\n");
		int poz = 0;
		for (int i = 0; i < size(lst); i++) {
			Student s = get(lst, i);
			if (s.name1[0] == c)
				printf("Studentul %d: %s %s, %0.2f\n", ++poz, s.name1, s.name2, s.score);
		}
	}
}

// sorts students
void sortStudents(VectorDinamic* lst) {
	printf("1 - Sortare dupa nume\n2 - Sortare dupa scor\n");
	int nr;
	scanf("%d", &nr);
	printf("1 - Crescator\n2 - Descrescator\n");
	int desc;
	scanf("%d", &desc);
	if ((desc != 2 && desc != 1) || (nr != 2 && nr != 1)){
		printf("Date invalide!\n");
		return;
	}

	if (nr == 1) {
		sortName(lst);
	}
	else if (nr == 2) {
		sortScore(lst);
	}
	if (desc == 2) {
		sortReverse(lst);
	}
	printStudents(lst);
}

void run() {
	VectorDinamic allStudents = createEmpty();
	int ruleaza = 1;
	while (ruleaza == 1) {
		printf("0 - Afiseaza toti participantii\n1 - Adaugare participant\n2 - Actualizare participant existent\n3 - Stergere participanti\n4 - Afisare participanti filtrati\n5 - Sortare participanti\n6 - Iesire din aplicatie\n");
		int cmd = 0;
		scanf("%d", &cmd);
		switch(cmd) {
		case 0:
			printStudents(&allStudents);
			break;
		case 1:
			readStudent(&allStudents);
			break;
		case 2:
			updateStudent(&allStudents);
			break;
		case 3:
			deleteStudent(&allStudents);
			break;
		case 4:
			filterStudents(&allStudents);
			break;
		case 5:
			sortStudents(&allStudents);
			break;
		case 6:
			ruleaza = 0;
			break;
		default:
			printf("Comanda invalida!\n");
		// TO BE ADDED - the other cases
		}
		printf("\n-------------------------------------------------\n\n");
	}
	destroy(&allStudents);
}



// main function
int main() {
	testAll();
	run();
	_CrtDumpMemoryLeaks();
	return 0;
}