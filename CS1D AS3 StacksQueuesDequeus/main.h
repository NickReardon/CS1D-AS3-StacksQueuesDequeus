/*****************************************************************************
 * AUTHOR 	  		: Nick Reardon
 * Assignment #3	: Stacks, Queues, Dequeus
 * CLASS			: CS1D
 * SECTION			: MW - 2:30p
 * DUE DATE			: 02 / 03 / 20
 *****************************************************************************/
#ifndef _MAIN_H_
#define _MAIN_H_

//Standard includes
#include <iostream>
#include <iomanip>
#include <string>
#include "PrintHeader.h"

//Program Specific
#include<stack>
#include "stackType.h"
#include "linkedQueue.h"
#include "dequeType.h"



//Prints the contents of an STL stack
//Makes a copy and outputs top, then pops in a loop until empty
template <class Type>
void printStackSTL(std::stack<Type> stack)
{
	std::stack<Type> copy = stack;

	cout << "Printing STL stack:" << endl;
	while (copy.size() > 0)
	{
		cout << copy.top() << endl;
		copy.pop();
	}
	cout << endl;
}

//Checks a given strings for parenthesis
bool areParanthesisBalanced(const string& expression);

#endif // _HEADER_H_
