#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

namespace DataStructures
{

template <class T>
class LinkedList 
{
	Node<T> *current = NULL;
	Node<T> *head = NULL; // last, freshest, element
	Node<T> *tail = NULL; // first, oldest, element

	int listsize = 0;

	// each position stores an element
	// positions are nodes
	public:
		// LinkedList<T>* first(); // can return this
		// LinkedList<T>* last();
   		
   		bool isEmpty();
		int size();
   		T first();
   		T last();
		void insertFirst(T element);
		void insertLast(T element);
		void removeFirst();
		void removeLast();
		
		void test();

		// int before(int position);
		// int after(int position);
		// void insertBefore(int position, T element); // should these be after nodes ???
		// void insertAfter(int position, T element); // after a node, insert this node
};

template <class T>
bool LinkedList<T>::isEmpty()
{
	return this->listsize == 0 ? true : false;
}

template <class T>
int LinkedList<T>::size()
{
	return this->listsize;	
}

template <class T>
T LinkedList<T>::first()
{
	if (!this->tail) {
		throw false;
	}

	return this->tail->read();
}

template <class T>
void LinkedList<T>::insertFirst(T data)
{
	Node<T> *element = new Node<T>;
	
	element->set(data);
	element->next = tail;

	this->current = element;
	this->tail    = element;
	
	if (!this->head) {
		this->head = element;
	}

	this->listsize++;

	// investigate implication of needing to delete pointer
	// delete element;
}

template <class T>
T LinkedList<T>::last()
{
	if (!this->head) {
		throw false;
	}

	return this->head->read();
}

template <class T>
void LinkedList<T>::insertLast(T data)
{
	Node<T> *element = new Node<T>;
	
	element->set(data);
	element->next = NULL;

	this->head->next = element;

	this->current = element;
	this->head    = element;
	
	this->listsize++;

	// investigate implication of needing to delete pointer
	// delete element;
}

template <class T>
void LinkedList<T>::test()
{
	std::cout << this->tail->read() << "\n";

	Node<T> *next1 = this->tail->next;
	std::cout << next1->read() << "\n";

	Node<T> *next2 = next1->next;
	std::cout << next2->read() << "\n";

	Node<T> *next3 = next2->next;
	std::cout << next3->read() << "\n";

	Node<T> *next4 = next3->next;
	std::cout << next4->read() << "\n";

	Node<T> *next5 = next4->next;
	std::cout << next5->read() << "\n";

	/*
	for (int i=0; i<this->listsize; i++) {
		Node<T> *next = this->tail->next;
		std::cout << next->read() << "\n";
		delete next;
	}
	*/
}

/*
template <class T>
T LinkedList<T>::element()
{
	// could use, ->
	return (*current).read();
}

template <class T>
LinkedList<T>* LinkedList<T>::first()
{
	if (!tail) {
		throw false;
	}

	current = tail;
	return this;
}

template <class T>
LinkedList<T>* LinkedList<T>::last()
{
	if (!head) {
		throw false;
	}

	current = head;
	return this;
}

template <class T>
void LinkedList<T>::insert(T data)
{
	Node<T> *element = new Node<T>;
	
	element->set(data);
	element->next = NULL;

	this->current = element;
	this->head    = element;
	
	if (!tail) {
		this->tail = element;
	}

	this->listsize++;

	// investigate implication of needing to delete pointer
	// delete element;
}
*/

}


#endif
