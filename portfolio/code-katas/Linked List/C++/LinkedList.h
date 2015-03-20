#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stack>
#include "Node.h"

namespace DataStructures
{

template <class T>
class LinkedList 
{
	Node<T> *active = NULL;
	Node<T> *head   = NULL; 
	Node<T> *tail   = NULL; // grow the tail

	std::stack<Node<T>*> stack;

	int listsize  = 0;
	int iteration = 0;
	bool stackset = false;

	public:
		LinkedList<T>* reset();
   		
   		bool isEmpty();
		int size();
   		
   		bool iterate();
   		bool reverse();

   		T read();
   		T first();
   		T last();

		void insertFirst(T element);
		void insertLast(T element);
		void removeFirst();
		void removeLast();

	private:
		void buildStack();
};

template <class T>
bool LinkedList<T>::iterate()
{
	if (!this->head || !this->active->next) {
		return false;
	}

	if (this->iteration == 0) {
		this->active = this->head;
	} else {
		this->active = this->active->next;
	}

	this->iteration++;

	return true;
}

template <class T>
bool LinkedList<T>::reverse()
{
	if (!this->stackset) {
		buildStack();
		this->stackset = true;
	}

	if (this->stack.empty()) {
		this->stackset = false;
		return false;
	}

	this->active = this->stack.top();
	this->stack.pop();
	
	return true;
}

template <class T> // private
void LinkedList<T>::buildStack()
{
	this->reset();

	while (this->iterate()) {
		this->stack.push(this->active);
	}
}

template <class T>
LinkedList<T>* LinkedList<T>::reset()
{
	if (!this->head) {
		throw false;
	}

	this->active    = head;
	this->iteration = 0;
	this->stackset  = false;

	while (!this->stack.empty()) {
		this->stack.pop();
	}

	return this;
}

template <class T>
T LinkedList<T>::read()
{
	if (!this->active) {
		throw false;
	}

	return this->active->read();
}

template <class T>
T LinkedList<T>::first()
{
	if (!this->head) {
		throw false;
	}

	return this->head->read();
}

template <class T>
T LinkedList<T>::last()
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
	element->next = head;

	this->active = element;
	this->head   = element;
	
	if (!this->tail) {
		this->tail = element;
	}

	this->listsize++;
}

template <class T>
void LinkedList<T>::insertLast(T data)
{
	Node<T> *element = new Node<T>;
	
	element->set(data);
	element->next = NULL;

	if (this->tail) {
		this->tail->next = element; 
	}
	
	if (!this->head) {
		this->head = element;
	}

	this->active = element;
	this->tail   = element;
	
	this->listsize++;
	// delete element; ??? needed
}

}

#endif
