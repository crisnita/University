#include "MyList.h"

#include <string.h>


// creates an empty list
MyList createEmpty() {
	MyList lst;
	lst.len = 0;
	return lst;
}


// destroys the list
void destroy(MyList* lst) {
	lst->len = 0;
}


// adds an element to the list
void add(MyList* lst, TElem elem) {
	lst->elems[lst->len] = elem;
	lst->len++;
}

// get size
int size(MyList* lst) {
	return lst->len;
}


// get an element
Student getElem(MyList* lst, int poz) {
	return lst->elems[poz];
}
