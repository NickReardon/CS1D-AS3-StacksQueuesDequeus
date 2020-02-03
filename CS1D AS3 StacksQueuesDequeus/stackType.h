#ifndef H_StackType
#define H_StackType

#include <iostream>

using namespace std;

//Definition of the node
template <class Type>
struct nodeType
{
	Type info;
	nodeType<Type>* link;
};

template<class Type>
class linkedStackType
{
public:
	const linkedStackType<Type>& operator=
		(const linkedStackType<Type>&);
	//overload the assignment operator
	void initializeStack();
	//Initialize the stack to an empty state.
	//Post condition: Stack elements are removed; head = NULL
	bool isEmptyStack();
	//Function returns true if the stack is empty;
	//otherwise, it returns false
	bool isFullStack();
	//Function returns true if the stack is full;
	//otherwise, it returns false

	Type top();

	void push(const Type& newItem);
	//Add the newItem to the stack.
	//Pre condition: stack exists and is not full
	//Post condition: stack is changed and the newItem
	//     is added to the head of stack. head points to
	//     the updated stack
	void pop(Type& poppedElement);
	void pop();
	//Remove the head element of the stack.
	//Pre condition: Stack exists and is not empty
	//Post condition: stack is changed and the head
	//    element is removed from the stack. The head
	//    element of the stack is saved in poppedElement
	void destroyStack();
	//Remove all elements of the stack, leaving the
	//stack in an empty state.
	//Post condition: head = NULL
	linkedStackType();
	//default constructor
	//Post condition: head = NULL
	linkedStackType(const linkedStackType<Type>& otherStack);
	//copy constructor
	~linkedStackType();
	//destructor
	//All elements of the stack are removed from the stack

	void printStack();

private:
	nodeType<Type>* head; // pointer to the stack
};


template<class Type> //default constructor
linkedStackType<Type>::linkedStackType()
{
	head = NULL;
}

template<class Type>
void linkedStackType<Type>::destroyStack()
{
	nodeType<Type>* temp; //pointer to delete the node

	while (head != NULL)  //while there are elements in the stack
	{
		temp = head;      //set temp to point to the current node
		head = head->link; //advance head to the next node
		delete temp;     //deallocate memory occupied by temp
	}
}// end destroyStack



template<class Type>
void linkedStackType<Type>::initializeStack()
{
	destroyStack();
}

template<class Type>
bool linkedStackType<Type>::isEmptyStack()
{
	return(head == NULL);
}

template<class Type>
bool linkedStackType<Type>::isFullStack()
{
	return 0;
}

template<class Type>
Type linkedStackType<Type>::top()
{
	return head->info;
}

template<class Type>
void linkedStackType<Type>::push(const Type& newElement)
{
	nodeType<Type>* newNode; //pointer to create the new node

	newNode = new nodeType<Type>; //create the node
	newNode->info = newElement;   //store newElement in the node
	newNode->link = head;          //insert newNode before head
	head = newNode;            //set head to point to the head node
} //end push


template<class Type>
void linkedStackType<Type>::pop(Type& poppedElement)
{
	nodeType<Type>* temp;		//pointer to deallocate memory

	poppedElement = head->info;	//copy the head element into
								 //poppedElement
	cout << "Popped item is " << poppedElement << endl;
	temp = head;					//set temp to point to the head node
	head = head->link;				//advance head to the next node
	delete temp;					//delete the head node
}//end pop

template<class Type>
void linkedStackType<Type>::pop()
{
	nodeType<Type>* temp;		//pointer to deallocate memory
	temp = head;					//set temp to point to the head node
	head = head->link;				//advance head to the next node
	delete temp;					//delete the head node
}//end pop


template<class Type>   //copy constructor
linkedStackType<Type>::linkedStackType(const linkedStackType<Type>& otherStack)
{
	nodeType<Type>* newNode, * current, * last;

	if (otherStack.head == NULL)
		head = NULL;
	else
	{
		current = otherStack.head;	//set current to point to the
									//stack to be copied

			//copy the head element of the stack
		head = new nodeType<Type>;   //create the node
		head->info = current->info;  //copy the info
		head->link = NULL;     	    //set the link field of the
									//node to null
		last = head;                 //set last to point to the node
		current = current->link;    //set current to point to the
									//next node

			//copy the remaining stack
		while (current != NULL)
		{
			newNode = new nodeType<Type>;
			newNode->info = current->info;
			newNode->link = NULL;
			last->link = newNode;
			last = newNode;
			current = current->link;
		}//end while
	}//end else
}//end copy constructor


template<class Type> //destructor
linkedStackType<Type>::~linkedStackType()
{
	nodeType<Type>* temp;

	while (head != NULL)     //while there are elements in the stack
	{
		temp = head;        //set temp to point to the current node
		head = head->link;  //advance first to the next node
		delete temp;       //deallocate the memory occupied by temp
	}//end while
}
//end destructor

template<class Type>
inline void linkedStackType<Type>::printStack()
{
	cout << "Printing stack:" << endl;
	nodeType<Type>* tempPtr = head;
	for (nodeType<Type>* tempPtr = head; tempPtr != NULL; tempPtr = tempPtr->link)
	{
		cout << tempPtr->info << endl;
	}
	cout << endl;
}


template<class Type>   //overloading the assignment operator
const linkedStackType<Type>& linkedStackType<Type>::operator=
(const linkedStackType<Type>& otherStack)
{
	nodeType<Type>* newNode, * current, * last;

	if (this != &otherStack) //avoid self-copy
	{
		if (head != NULL)  //if the stack is not empty, destroy it
			destroyStack();

		if (otherStack.head == NULL)
			head = NULL;
		else
		{
			current = otherStack.head;	//set current to point to
										//the stack to be copied

				//copy the head element of otherStack
			head = new nodeType<Type>;	//create the node
			head->info = current->info;	//copy the info
			head->link = NULL;			//set the link field of the
										//node to null
			last = head;           		//make last point to the node
			current = current->link;	//make current point to
										//the next node

				//copy the remaining elements of the stack
			while (current != NULL)
			{
				newNode = new nodeType<Type>;
				newNode->info = current->info;
				newNode->link = NULL;
				last->link = newNode;
				last = newNode;
				current = current->link;
			}//end while
		}//end else
	}//end if

	return *this;
}//end operator=
#endif