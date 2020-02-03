#ifndef H_linkedQueue
#define H_linkedQueue

#include <iostream>

using namespace std;


template<class Type>
class linkedQueueType
{
public:
	const linkedQueueType<Type>& operator=
		(const linkedQueueType<Type>&);
	// overload the assignment operator
	bool isEmptyQueue();
	bool isFullQueue();
	void destroyQueue();
	void initializeQueue();
	void addQueue(const Type& newElement);
	void deQueue(Type& deqElement);
	linkedQueueType(); //default constructor
	linkedQueueType(const linkedQueueType<Type>& otherQueue);
		//copy constructor

	void printQueue();

	~linkedQueueType(); //destructor

private:
	nodeType<Type>* front; //pointer to the front of the queue
	nodeType<Type>* rear;  //pointer to the rear of the queue
};


template<class Type>
linkedQueueType<Type>::linkedQueueType() //default constructor
{
	front = NULL; // set front to null
	rear = NULL;  // set rear to null
}


template<class Type>
bool linkedQueueType<Type>::isEmptyQueue()
{
	return(front == NULL);
}

template<class Type>
bool linkedQueueType<Type>::isFullQueue()
{
	return false;
}

template<class Type>
void linkedQueueType<Type>::destroyQueue()
{
	nodeType<Type>* temp;

	while (front != NULL)  //while there are elements left in the queue
	{
		temp = front;         // set temp to point to the current node
		front = front->link; // advance front to the next node
		delete temp;          // deallocate memory occupied by temp
	}

	rear = NULL;  // set rear to null
}

template<class Type>
void linkedQueueType<Type>::initializeQueue()
{
	destroyQueue();
}

template<class Type>
void linkedQueueType<Type>::addQueue(const Type& newElement)
{
	nodeType<Type>* newNode;

	newNode = new nodeType<Type>;	//create the node
	newNode->info = newElement;		//store the info
	newNode->link = NULL;			//initialize the link field to null

	if (front == NULL)				//if initially queue is empty
	{
		front = newNode;
		rear = newNode;
	}
	else				//add newNode at the end
	{
		rear->link = newNode;
		rear = rear->link;
	}
}//end addQueue

template<class Type>
void linkedQueueType<Type>::deQueue(Type& deqElement)
{
	nodeType<Type>* temp;

	deqElement = front->info;  //copy the info of the first element

	cout << "deQueued item is " << deqElement << endl;

	temp = front;              //make temp point to the first node
	front = front->link;       //advance front to the next node
	delete temp;               //delete the first node

	if (front == NULL)          //if after deletion the queue is empty
		rear = NULL;		   //set rear to NULL
}//end deQueue



template<class Type>
linkedQueueType<Type>::~linkedQueueType() //destructor
{
	nodeType<Type>* temp;

	while (front != NULL)	  //while there are elements left in the queue
	{
		temp = front;         //set temp to point to the current node
		front = front->link; //advance first to the next node
		delete temp;          //deallocate memory occupied by temp
	}

	rear = NULL;  // set rear to null
}

template<class Type>
const linkedQueueType<Type>& linkedQueueType<Type>::operator=
(const linkedQueueType<Type>& otherQueue)
{
	//Write the definition of to overload the assignment operator

}

//copy constructor
template<class Type>
linkedQueueType<Type>::linkedQueueType(const linkedQueueType<Type>& otherQueue)
{
	//Write the definition of the copy constructor
}//end copy constructor


template<class Type>
inline void linkedQueueType<Type>::printQueue()
{
	cout << "Printing queue:" << endl;
	nodeType<Type>* tempPtr = front;
	for (nodeType<Type>* tempPtr = front; tempPtr != NULL; tempPtr = tempPtr->link)
	{
		cout << tempPtr->info << endl;
	}
	cout << endl;
}

#endif