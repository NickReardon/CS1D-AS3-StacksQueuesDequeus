#ifndef H_dequeElem
#define H_dequeElem

#include <iostream>

using namespace std;
template <class Elem>
struct DNode
{
    Elem elem;
    DNode<Elem>* prev;
    DNode<Elem>* next;
};

template<class Elem>
class DLinkedList // doubly linked list
{				
public:
    DLinkedList();				// constructor
    ~DLinkedList();				// destructor
    bool empty() const;				// is list empty?
    const Elem& front() const;			// get front element
    const Elem& back() const;			// get back element
    void addFront(const Elem& e);		// add to front of list
    void addBack(const Elem& e);		// add to back of list
    void removeFront();				// remove from front
    void removeBack();				// remove from back
    void printDeque();
private:					// local type definitions
    DNode<Elem>* header;				// list sentinels
    DNode<Elem>* trailer;
protected:					// local utilities
    void add(DNode<Elem>* v, const Elem& e);		// insert new node before v
    void remove(DNode<Elem>* v);			// remove node v
};

template<class Elem>
DLinkedList<Elem>::DLinkedList() {			// constructor
    header = new DNode<Elem>;				// create sentinels
    trailer = new DNode<Elem>;
    header->next = trailer;			// have them point to each other
    trailer->prev = header;
}

template<class Elem>
DLinkedList<Elem>::~DLinkedList() {			// destructor
    while (!empty()) removeFront();		// remove all but sentinels
    delete header;				// remove the sentinels
    delete trailer;
}

template<class Elem>
bool DLinkedList<Elem>::empty() const		// is list empty?
{
    return (header->next == trailer);
}

template<class Elem>
const Elem& DLinkedList<Elem>::front() const	// get front element
{
    return header->next->elem;
}

template<class Elem>
const Elem& DLinkedList<Elem>::back() const		// get back element
{
    return trailer->prev->elem;
}

template<class Elem>                        
void DLinkedList<Elem>::add(DNode<Elem>* v, const Elem& e) // insert new node before v
{
    DNode<Elem>* u = new DNode<Elem>;  
    u->elem = e;		// create a new node for e
    u->next = v;				// link u in between v
    u->prev = v->prev;				// ...and v->prev
    u->prev->next = u;
    v->prev = u;
}

template<class Elem>
void DLinkedList<Elem>::addFront(const Elem& e)	// add to front of list
{
    add(header->next, e);
}

template<class Elem>
void DLinkedList<Elem>::addBack(const Elem& e)	// add to back of list
{
    add(trailer, e);
}

template<class Elem>
void DLinkedList<Elem>::remove(DNode<Elem>* v) {		// remove node v
    DNode<Elem>* u = v->prev;				// predecessor
    DNode<Elem>* w = v->next;				// successor
    u->next = w;				// unlink v from list
    w->prev = u;
    delete v;
}

template<class Elem>
void DLinkedList<Elem>::removeFront()		// remove from font
{
    cout << "removing from front: " << header->next->elem  << endl;
    remove(header->next);
}

template<class Elem>
void DLinkedList<Elem>::removeBack()		// remove from back
{
    cout << "removing from back: " << trailer->prev->elem << endl;
    remove(trailer->prev);
}

template<class Elem>
void DLinkedList<Elem>::printDeque()		// remove from back
{
    cout << "Printing deque front to back:" << endl;
    for (DNode<Elem>* tempPtr = header->next; tempPtr != trailer; tempPtr = tempPtr->next)
    {
        cout << tempPtr->elem << endl;
    }
    cout << endl;
}
#endif