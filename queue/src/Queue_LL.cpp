#include <iostream>
#include <stdexcept>

#include "Queue_LL.h"

Queue::Queue() : Head{nullptr}, Tail{nullptr}
{
}

Queue::Queue(int value) : Head{nullptr}, Tail{nullptr}
{
	init(value);
}

Queue::~Queue()
{
	clear();
}

void Queue::init(int value)
{
	Node* newNode = new Node;
	newNode->data = value;
	newNode->next = nullptr;
	Head = Tail = newNode;
}

void Queue::enqueue(int value)
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

int Queue::dequeue()
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

bool Queue::empty()
{
	return !Head;
}


void Queue::clear()
{
	Node* tmp = nullptr;
	while(Head){
		tmp = Head;
		Head = Head->next;
		delete tmp;
	}
	Tail = nullptr;
}

int Queue::peek()
{
	if(empty())
		throw std::out_of_range("Queue is empty");
	return Head->data;
}

void Queue::printData()
{
	Node* trav = Head;
	while(trav){
		std::cout << trav->data << "<-";
		trav = trav->next;
	}
	std::cout << "END" << std::endl;
}
