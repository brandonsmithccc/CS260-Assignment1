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

struct Node {
	int data;
	Node* next;
};

class LinkedList {
public:

	/**
	 * \brief Constructor for the linked list.
	 * 
	 */
	LinkedList() {
		head = nullptr;
	}

	/**
	 * \brief Destructor for the linked list.
	 * 
	 */
	~LinkedList() {
		removeAll();
	}

	/**
	 * Inserts the given integer at the beginning of the linked list.
	 * 
	 * \param n integer to insert
	 * \return true if the item is unique and was inserted, false if not
	 */
	bool prepend(const int n) {
		
		if (find(n) == 0) { //item not found in list
			Node* newNode = new Node;
			newNode->data = n;
			newNode->next = head;
			head = newNode;
			return true;
		}
		else {
			return false;
		}
	}

		

	/**
	 * \brief Inserts the given integer at the end of the linked list.
	 * 
	 * \param n integer to insert
	 * \return true if the item is unique and was inserted, false otherwise
	 */
	bool append(const int n) {
		Node* current = head;
		Node* newNode = new Node;

		newNode->data = n;
		newNode->next = nullptr;

		if (head == nullptr) {
			prepend(n);
		}

		else {
			while(current->next != nullptr) { //have to stop one before the final node
				current = current->next;
			}
			current->next = newNode;
			return true;
		}
		return false;
	}

	/**
	 * \brief Removes the given integer from the list.
	 * 
	 * \param n integer to remove
	 * \return true if integer was found and removed, false otherwise
	 */
	bool remove(const int n) {
		Node* current = head;
		Node* previous = nullptr;

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

	/**
	 * Prints the number of items in the list followed by the items in the list.
	 * 
	 */
	void print() {
		int length = count();
		if (head == nullptr) {
			std::cout << "The list contains 0 elements." << std::endl;
			exit(0);
		}
		else if (count() == 1) {
			std::cout << "The list contains 1 element." << std::endl;
		}
		else {
			std::cout << "The list contains " << length << " elements." << std::endl;

		}

		Node* current = head;
		Node* nextNode = current->next;
		for (int i = 0; i < length - 1; i++) {
			std::cout << current->data << ", ";
			current = current->next;
		}
		std::cout << current->data << std::endl;
	}

	/**
	 * 
	 * \return the number of integers in the list
	 */
	int count() {
		Node* current = head;
		int count = 0;
		while (current != nullptr) {
			count++;
			current = current->next;
		}
		return count;
	}

	/**
	 * Find the given integer in the linked list.
	 * 
	 * \param n the integer to find
	 * \return the position of the integer in the list (1 indexed), -1 if not found
	 */
	int find(const int n) {
		Node* current = head;

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

	/**
	 * Removes all items in the linked list.
	 * 
	 */
	void removeAll() {
		Node* current = head;
		while (current != nullptr) {
			Node* nodeToDelete = current;
			current = current->next;
			delete nodeToDelete;
		}
		head = nullptr;
	}

	
private:
	Node* head;
};
