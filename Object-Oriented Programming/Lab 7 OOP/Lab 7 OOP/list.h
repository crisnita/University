#pragma once
#include <utility>
#include <string>
#include <sstream>
#include "movies.h"

using namespace std;

// Nodes
template <class T>
class MyNode {
	private:
		T data;
	public:
		MyNode* next;
		MyNode* previous;
		MyNode(T data);
		T getData();
		string toString();
		~MyNode();
	};

// constructor
template <class T>
MyNode<T>::MyNode(T data) {
	this->data = data;
}

template <class T>
T MyNode<T>::getData() {
	return this->data;
}

template <class T>
string MyNode<T>::toString() {
	stringstream s;
	s >> this->getData();
	return s.str();
}

template <class T>
MyNode<T>::~MyNode() {}


// Doubly Linked List

template <class T>
class MyList {
	private:
		T* head, tail;
		int list_size;
	public:
		MyList();
		T* getHead() const;
		T* getTail() const;
		int size(bool update = false) const;
		//T* MyList<T>::next(T* node);
		void addNodeAsTail(T* new_node);
		void addNodeAsHead(T* new_node);
		void push(T* new_node);
		void del(int index);
		T* pop();
		T* peek() const;
		void enqueue(T* new_node);
		T* dequeue();
		T* get(int index) const;
		
		//void printList();
		//void printListBackwards();
		~MyList();
};

// list constructor
template <class T>
MyList<T>::MyList() {
	this->head = NULL;
	this->tail = NULL;
	this->list_size = 0;
}

// returns the head of the list
template <class T>
T* MyList<T>::getHead() const {
	return this->head;
}

// returns the tail of the list
template <class T>
T* MyList<T>::getTail() const {
	return this->tail;
}

// returns the size of the list (the number of elements in the list)
template <class T>
int MyList<T>::size(bool update) const {
	if (!update) {
		return this->list_size;
	}
	int size = 0;
	T* temp = this->head;
	while (temp) {
		size++;
		temp = temp->next;
	}
	//this->list_size = size;
	return this->list_size;
}

// adds a node in the tail, which becomes the new tail
template <class T>
void MyList<T>::addNodeAsTail(T* new_node) {
	new_node->next = NULL;
	new_node->previous = NULL;

	if (this->head == NULL) { // in case we have no nodes in the list yet
		this->head = new_node;
		this->tail = this->head;
		this->list_size = this->list_size + 1;
	}
	else {
		this->tail->next = new_node;
		new_node->previous = this->tail;
		this->tail = new_node;
		this->list_size = this->list_size + 1;
	}
}

// adds a node in the head, which becomes the new head
template <class T>
void MyList<T>::addNodeAsHead(T* new_node) {
	new_node->next = NULL;
	new_node->previous = NULL;

	if (this->head == NULL) { // in case we have no nodes in the list yet
		this->head = new_node;
		this->tail = this->head;
		this->list_size = this->list_size + 1;
	}
	else {
		this->head->previous = new_node;
		new_node->next = this->head;
		this->head = new_node;
		this->list_size = this->list_size + 1;
	}
}


// adds a new element as the new head
template <class T>
void MyList<T>::push(T* new_node) {
	this->addNodeAsHead(new_node);
}

// pops the element from the head
template <class T>
T* MyList<T>::pop() {
	T* temp = this->head;
	this->head = this->head->next;
	this->head->previous = NULL;
	this->list_size = this->list_size - 1;
	return temp;
}

// returns the head of the list
template <class T>
T* MyList<T>::peek() const {
	return this->head;
}

// adds node to the end of the list
template <class T>
void MyList<T>::enqueue(T* new_node) {
	this->addNodeAsTail(new_node);
}

// deletes the node from the start of the list
template <class T>
T* MyList<T>::dequeue() {
	return this->pop();
}


// deletes a node from a certain index
template <class T>
void MyList<T>::del(int index) {
	if (index == 0) {
		this->pop();
		this->list_size--;
		return;
	}
	if (index == this->list_size - 1) {
		this->tail = this->tail->previous;
		this->tail->next = NULL;
		this->list_size--;
		return;
	}
	T* temp = this->head;
	int i = 0;
	while (temp) {
		if (i == index) {
			temp->previous->next = temp->next;
			temp->next->previous = temp->previous;
			this->list_size--;
			return;
		}
		i++;
		temp = temp->next;
	}
}

// get an element from a certain index
template <class T>
T* MyList<T>::get(int index) const {
	if (index == 0) {
		return this->head;
	}
	else if (index == this->list_size - 1) {
		return this->tail;
	}
	else if (index < 0 || index >= this->list_size) {
		return NULL;
	}

	if (index < this->list_size / 2) {
		T* temp = this->head;
		int i = 0;
		while (temp) {
			if (i == index) {
				return temp;
			}
			i++;
			temp = temp->next;
		}
	}
	return NULL;
}

// destructor
template <class T>
MyList<T>::~MyList() {
	while (this->head) {
		T* next = this->head->next;
		delete this->head;
		this->list_size = this->list_size - 1;
		this->head = next;
	}
}










