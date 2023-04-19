/*****************************************************************//**
 * \file   LinkedList.h
 * \brief  Function prototypes for my linked list class
 * 
 * \author Brandon Smith
 * \date   April 2023
 *********************************************************************/

#pragma once

#include <iostream>
#include <stdlib.h>

template<typename Type>
struct Node {
	Type data;
	Node<Type>* next;
};

template<class Type>
class LinkedList {
public:
	/**
	 * \brief Constructor for the linked list.
	 * 
	 */
	LinkedList();

	/**
	 * \brief Destructor for the linked list.
	 * 
	 */
	~LinkedList();

	/**
	 * Inserts the given integer at the beginning of the linked list.
	 * 
	 * \param n integer to insert
	 * \return true if the item is unique and was inserted, false if not
	 */
	bool prepend(const Type& n);

	/**
	 * \brief Inserts the given item at the end of the linked list.
	 * 
	 * \param n item to insert
	 * \return true if the item is unique and was inserted, false otherwise
	 */
	bool append(const Type& n);

	/**
	 * \brief Removes the given item from the list.
	 * 
	 * \param n datatype item to remove
	 * \return true if item was found and removed, false otherwise
	 */
	bool remove(const Type& n);

	/**
	 * Prints the number of items in the list followed by the items in the list.
	 * 
	 */
	void print();

	/**
	 * 
	 * \return the number of integers in the list
	 */
	int count();

	/**
	 * Find the given integer in the linked list.
	 * 
	 * \param n the integer to find
	 * \return the position of the integer in the list (1 indexed), -1 if not found
	 */
	int find(const Type& n);

	/**
	 * Removes all items in the linked list.
	 * 
	 */
	void removeAll();

private:
	Node<Type>* head;
};

template<class Type>
LinkedList<Type>::LinkedList() {
	head = nullptr;
}

template<class Type>
LinkedList<Type>::~LinkedList() {
	removeAll();
}

template<class Type>
bool LinkedList<Type>::prepend(const Type& n) {
	if (find(n) == 0) { //item not found in list
		Node<Type>* newNode = new Node<Type>;
		newNode->data = n;
		newNode->next = head;
		head = newNode;
		return true;
	}
	else {
		return false;
	}
}

template<class Type>
bool LinkedList<Type>::append(const Type& n) {
	if (find(n) == 0) {
		Node<Type>* current = head;
		Node<Type>* newNode = new Node<Type>;

		newNode->data = n;
		newNode->next = nullptr;

		if (head == nullptr) {
			prepend(n);
		}

		else {
			while (current->next != nullptr) { //have to stop one before the final node
				current = current->next;
			}
			current->next = newNode;
			return true;
		}
	}

	return false;
}

template<class Type>
bool LinkedList<Type>::remove(const Type& n) {
	Node<Type>* current = head;
	Node<Type>* previous = head;

	if (head == nullptr) { //if the list is empty
		return false;
	}

	if (find(n) == 1) { //if item to remove is first
		head = head->next;
		delete current;
		return true;
	}

	while (current != nullptr) { //could I use a for loop here since I have the find function?
		if (current->data == n) {
			previous->next = current->next;
			delete current;
			return true;
		}
		previous = current;
		current = current->next;
	}
	return false;
}

template<class Type>
void LinkedList<Type>::print() {
	int length = this->count();

	if (length == 0) {
		std::cout << "The list contains 0 elements." << std::endl;
	}
	else if (length == 1) {
		std::cout << "The list contains 1 element." << std::endl;
	}
	else {
		std::cout << "The list contains " << length << " elements." << std::endl;

	}

	Node<Type>* current = this->head;
	while(current != nullptr) {
		std::cout << current->data;
		if (current->next != nullptr) {
			std::cout << ", ";
		}
		current = current->next;
	}
	std::cout << std::endl;
}

template<class Type>
int LinkedList<Type>::count() {
	Node<Type>* current = head;
	int count = 0;
	while (current != nullptr) {
		count++;
		current = current->next;
	}
	return count;
}

template<class Type>
int LinkedList<Type>::find(const Type& n) {
	Node<Type>* current = head;

	int position = 1;
	while (current != nullptr) {
		if (current->data == n) {
			return position;
		}
		position++;
		current = current->next;
	}
	return 0;
}

template<class Type>
void LinkedList<Type>::removeAll() {
	Node<Type>* current = head;
	while (current != nullptr) {
		Node<Type>* nodeToDelete = current;
		current = current->next;
		delete nodeToDelete;
	}
	head = nullptr;
}
