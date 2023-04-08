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
#include <iostream>



int main()
{
    LinkedList intList;
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
	intList.print();
	std::cout << std::endl << std::endl;



}