#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

namespace DataStructures
{

template <class T>
class LinkedList 
{
	Node<T> *current = NULL;
	Node<T> *head = NULL;
	Node<T> *tail = NULL;

	// each position stores an element
	// positions are nodes
	public:
		void insert(T element);
		T element();
		T first(); // probably needs to be pointers, returns positions, first().element()
		int last();
		int before(int position);
		int after(int position);
		bool isEmpty();
		int size();
		void insertBefore(int position, T element); // should these be after nodes ???
		void insertAfter(int position, T element);
		void remove(int position);
		void set(int position, T element);
};

template <class T>
void LinkedList<T>::insert(T data)
{
	Node<T> element;
	element.set(data);

	element.next = NULL;
	
	current = &element;
	head    = &element;

	if (!tail) {
		tail = &element;
	}
}

template <class T>
T LinkedList<T>::element()
{
	// could use, ->
	return (*current).read();
}

}

#endif
