/*****************************************************************************
 * AUTHOR 	  		: Nick Reardon
 * Assignment #3	: Stacks, Queues, Dequeus
 * CLASS			: CS1D
 * SECTION			: MW - 2:30p
 * DUE DATE			: 02 / 03 / 20
 *****************************************************************************/
#include "main.h"

using std::cout; using std::endl;


int main()
{

	/*
	 * HEADER OUTPUT
	 */
	PrintHeader(cout, "Prompt.txt");

	/********************************************************************/

	std::ifstream strFile;
	strFile.open("stringInput.txt");

	std::ifstream numFile;
	numFile.open("doubleInput.txt");

	std::stack<std::string> strStack_STL;
	std::stack<double> numStack_STL;

	linkedStackType<std::string> strStack;
	linkedStackType<double> numStack;

	linkedQueueType<std::string> strQueue;
	linkedQueueType<double> numQueue;

	DLinkedList<std::string> strDeque;
	DLinkedList<double> numDeque;

	cout << "Reading from file into string stacks/queue/deque" << endl;
	while (strFile)
	{
		string temp;
		getline(strFile, temp);
		if (temp != "")
		{
			strStack_STL.push(temp);
			strStack.push(temp);
			strQueue.addQueue(temp);
			strDeque.addFront(temp);
		}
	}

	cout << "Reading from file into double stacks/queue/deque" << endl;
	while (numFile)
	{
		double temp = -99999999999999;
		numFile >> temp;
		if (temp != -99999999999999)
		{
			numStack_STL.push(temp);
			numStack.push(temp);
			numQueue.addQueue(temp);
			numDeque.addFront(temp);
		}
	}

	//****************************************************


	cout << endl << "   --- PART A ---" << endl << endl;


	printStackSTL(strStack_STL);
	printStackSTL(numStack_STL);


	cout << endl << "   --- PART B ---" << endl << endl;


	cout << "Deleting Jordyn from the STL stack" << endl;
	std::string tempStr;
	while (tempStr != "Jordyn")
	{
		tempStr = strStack_STL.top();
		strStack_STL.pop();
		cout << "deleting " << tempStr << endl;
	}
	cout << endl;
	
	cout << "Deleting 200.12 from the STL stack" << endl;
	double tempNum = -99999999999999999;
	while (tempNum != 200.12)
	{
		tempNum = numStack_STL.top();
		numStack_STL.pop();
		cout << "deleting " << tempNum << endl;
	}
	cout << endl;

	printStackSTL(strStack_STL);
	printStackSTL(numStack_STL);


	cout << endl << "   --- PART C ---" << endl << endl;


	cout << "Printing singly linked list stacks: " << endl << endl;
	strStack.printStack();
	numStack.printStack();


	cout << endl << "   --- PART D ---" << endl << endl;


	cout << "Deleting Jordyn from the linked list stack" << endl;
	tempStr.clear();
	while (tempStr != "Jordyn")
	{
		strStack.pop(tempStr);
	}
	cout << endl;

	cout << "Deleting 200.12 from the linked list stack" << endl;
	tempNum = -99999999999999999;
	while (tempNum != 200.12)
	{
		numStack.pop(tempNum);
	}
	cout << endl;

	strStack.printStack();
	numStack.printStack();


	cout << endl << "   --- PART E ---" << endl << endl;

	cout << "Printing singly linked list queues: " << endl << endl;

	numQueue.printQueue();
	strQueue.printQueue();


	cout << endl << "   --- PART F ---" << endl << endl;


	cout << "Deleting Jordyn from the linked list queue" << endl;
	tempStr.clear();
	while (tempStr != "Jordyn")
	{
		strQueue.deQueue(tempStr);
	}
	cout << endl;

	cout << "Deleting 200.12 from the linked list queue" << endl;
	tempNum = -99999999999999999;
	while (tempNum != 200.12)
	{
		numQueue.deQueue(tempNum);
	}
	cout << endl;

	numQueue.printQueue();
	strQueue.printQueue();


	cout << endl << "   --- PART G ---" << endl << endl;

	cout << "Printing doubly linked list deques: " << endl << endl;

	strDeque.printDeque();
	numDeque.printDeque();


	cout << endl << "   --- PART H ---" << endl << endl;


	cout << "Deleting Jordyn, using pop front, from the doubly linked list deque" << endl;
	tempStr.clear();
	while (tempStr != "Jordyn")
	{
		tempStr = strDeque.front();
		strDeque.removeFront();
	}
	cout << endl;

	cout << "Deleting 200.12, using pop back, from the doubly linked list deque" << endl;
	tempNum = -99999999999999999;
	while (tempNum != 200.12)
	{
		tempNum = numDeque.back();
		numDeque.removeBack();
	}
	cout << endl;

	strDeque.printDeque();
	numDeque.printDeque();


	cout << endl << "   --- PART I ---" << endl << endl;

	cout << "Testing Parentheses Algorithm - using singly linked list stack " << endl << endl;
	
	tempStr = "(12x + 6) (2x - 4)";
	cout << endl << tempStr << endl;
	if (areParanthesisBalanced(tempStr))
		cout << "Balanced" << endl;
	else
		cout << "Not Balanced" << endl;

	tempStr = "{2x + 5} (6x+4)";
	cout << endl << tempStr << endl;
	if (areParanthesisBalanced(tempStr))
		cout << "Balanced" << endl;
	else
		cout << "Not Balanced" << endl;

	tempStr = "{2x + 7) (12x + 6)";
	cout << endl << tempStr << endl;
	if (areParanthesisBalanced(tempStr))
		cout << "Balanced" << endl;
	else
		cout << "Not Balanced" << endl;


	tempStr = "{{8x+5) - 5x[9x+3]})";
	cout << endl << tempStr << endl;
	if (areParanthesisBalanced(tempStr))
		cout << "Balanced" << endl;
	else
		cout << "Not Balanced" << endl;


	tempStr = "(((4x+8) - x[4x+3])))";
	cout << endl << tempStr << endl;
	if (areParanthesisBalanced(tempStr))
		cout << "Balanced" << endl;
	else
		cout << "Not Balanced" << endl;


	tempStr = "[(5x - 5) - 4x[6x + 2]]";
	cout << endl << tempStr << endl;
	if (areParanthesisBalanced(tempStr))
		cout << "Balanced" << endl;
	else
		cout << "Not Balanced" << endl;


	tempStr = "{(8x+5) - 6x[9x+3]]";
	cout << endl << tempStr << endl;
	if (areParanthesisBalanced(tempStr))
		cout << "Balanced" << endl;
	else
		cout << "Not Balanced" << endl;


	system("pause");
	return 0;




}

bool areParanthesisBalanced(const string& expression)
{
	linkedStackType<char> s;
	char x;

	for (int i = 0; i < expression.length(); i++)
	{
		if (expression[i] == '(' || 
			expression[i] == '[' || 
			expression[i] == '{')
		{
			s.push(expression[i]);
		}
		else
		{
			if (!s.isEmptyStack())
			{
				switch (s.top())
				{
				case '(':
					if (expression[i] == ')')
					{
						s.pop();
					}
					else if (expression[i] == ']' ||
						expression[i] == '}')
					{
						return false;
					}
					break;

				case '[':
					if (expression[i] == ']')
					{
						s.pop();
					}
					else if (expression[i] == ')' ||
						expression[i] == '}')
					{
						return false;
					}
					break;

				case '{':
					if (expression[i] == '}')
					{
						s.pop();
					}
					else if (expression[i] == ')' ||
						expression[i] == ']')
					{
						return false;
					}
					break;
				}
			}
			else
			{
				if (expression[i] == ')' ||
					expression[i] == ']' ||
					expression[i] == '}')
				{
					return false;
				}
			}
		}
	}
	return s.isEmptyStack();
}