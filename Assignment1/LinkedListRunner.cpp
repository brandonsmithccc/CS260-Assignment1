/*****************************************************************//**
 * \file   LinkedListRunner.cpp
 * \brief  Test my linked list
 * 
 * Sources: https://youtu.be/fw7yRDaiMww to get abstract idea of how 
 *			to implement the append; final implementation was not shown
 * \author Brandon Smith
 * \date   April 2023
 *********************************************************************/

#include "LinkedList.h"
#include "Student.h"
#include <iostream>
#include<string>

const std::string YOUR_NAME = "Brandon Smith";



int main()
{
 //   LinkedList<int> intList;
	//intList.prepend(10);
	//intList.prepend(20);
	//intList.prepend(20);
	//intList.print();
	//intList.prepend(5);
	//intList.append(15);
	//intList.append(15);
	//intList.print();
	//intList.append(25);
	//intList.print();

	//std::cout << "5 is in position " << intList.find(5) << std::endl;
	//std::cout << "15 is in position " << intList.find(15) << std::endl;
	//std::cout << "20 is in position " << intList.find(20) << std::endl;
	//std::cout << "8 is in position " << intList.find(8) << std::endl;

	//intList.remove(15);
	//intList.print();
	//intList.remove(5);
	//intList.print();
	//intList.remove(25);
	//intList.print();

	//intList.removeAll();
	////intList.print();
	//std::cout << "NEW LIST..." << std::endl << std::endl;

	//LinkedList<char> charList;
	//charList.prepend('a');
	//charList.prepend('b');
	//charList.print();

	std::cout << YOUR_NAME << std::endl;

	// test template with ints --------------------------------
	LinkedList<int> intList;
	intList.prepend(10);
	intList.prepend(20);
	intList.prepend(5);
	intList.append(15);
	intList.append(25);
	intList.print();

	std::cout << "5 is in position " << intList.find(5) << std::endl;
	std::cout << "15 is in position " << intList.find(15) << std::endl;
	std::cout << "20 is in position " << intList.find(20) << std::endl;
	std::cout << "8 is in position " << intList.find(8) << std::endl;

	intList.remove(15);
	intList.remove(5);
	intList.remove(25);
	intList.print();

	intList.removeAll();
	intList.append(2);
	intList.print();
	std::cout << std::endl << "Char List" << std::endl;

	// test on list of chars --------------------------------
	LinkedList<char>* charList = new LinkedList<char>;
	charList->append('k');
	charList->append('s');
	charList->prepend('r');
	charList->prepend('o');
	charList->prepend('w');
	charList->print();

	charList->remove('r');
	charList->remove('w');
	charList->remove('s');
	charList->print();

	charList->removeAll();
	charList->print();
	delete charList;

	std::cout << std::endl << "Student List" << std::endl;
	LinkedList<Student>* studentList = new LinkedList<Student>;
	Student Brandon("Brandon", 'A');
	studentList->append(Brandon);
	std::cout << Brandon << std::endl;
	std::cout << "Print list" << std::endl;
	studentList->print();
	Student John("John", 'B');
	studentList->prepend(John);
	std::cout << "Print list" << std::endl;
	studentList->print();
	studentList->remove(Brandon);
	std::cout << "Print list" << std::endl;
	studentList->print();
	std::cout << "Position of John is " << studentList->find(John) << std::endl;
	std::cout << "Position of Brandon is " << studentList->find(Brandon) << std::endl;
	Student JohnB("John", 'B');
	studentList->append(JohnB);
	Student AliceA("Alice", 'A');
	studentList->append(AliceA);
	std::cout << "Print list" << std::endl;
	studentList->print();
	std::cout << "John and JohnB are the same: " << std::boolalpha << (John == JohnB) << std::endl;
	std::cout << "John and AliceA are the same: " << std::boolalpha << (JohnB == AliceA) << std::endl;






}