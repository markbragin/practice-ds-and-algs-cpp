#include <iostream>
#include <stdexcept>

#include "QueueLL.h"

QueueLL::QueueLL() : Head{nullptr}, Tail{nullptr}
{
}

QueueLL::QueueLL(int value) : Head{nullptr}, Tail{nullptr}
{
	init(value);
}

QueueLL::~QueueLL()
{
	clear();
}

void QueueLL::init(int value)
{
	Node* newNode = new Node;
	newNode->data = value;
	newNode->next = nullptr;
	Head = Tail = newNode;
}

void QueueLL::enqueue(int value)
{
	if(empty())
		init(value);
	else{
		Node* newNode = new Node;
		newNode->data = value;
		newNode->next = nullptr;
		Tail->next = newNode;
		Tail = Tail->next;
	}
}

int QueueLL::dequeue()
{
	if(empty())
		throw std::out_of_range("The queue is empty");
	Node* tmp = Head;
	Head = Head->next;
	int value = tmp->data;
	delete tmp;
	if(empty())
		Tail = nullptr;
	return value;
}

bool QueueLL::empty()
{
	return !Head;
}


void QueueLL::clear()
{
	Node* tmp = nullptr;
	while(Head){
		tmp = Head;
		Head = Head->next;
		delete tmp;
	}
	Tail = nullptr;
}

int QueueLL::peek()
{
	if(empty())
		throw std::out_of_range("QueueLL is empty");
	return Head->data;
}

void QueueLL::printData()
{
	Node* trav = Head;
	while(trav){
		std::cout << trav->data << "<-";
		trav = trav->next;
	}
	std::cout << "END" << std::endl;
}
