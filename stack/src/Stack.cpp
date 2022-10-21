#include <iostream>
#include <stdexcept>

#include "Stack.h"


Stack::Stack() : Head{nullptr}, size{0}
{
}

Stack::Stack(int value) : Head{nullptr}, size{0}
{
	push(value);
}

Stack::~Stack()
{
	clear();
}

void Stack::push(int value)
{
	Node* newNode = new Node;
	newNode->data = value;
	newNode->next = Head;
	Head = newNode;
	size++;
}

int Stack::top()
{
	if(isEmpty())
		throw std::out_of_range("The stack is empty");
	return Head->data;
}

void Stack::pop()
{
	if(isEmpty())
		throw std::out_of_range("The stack is empty");
	Node* tmp = Head;
	Head = Head->next;
	delete tmp;
	size--;
}

bool Stack::isEmpty()
{
	return !size;
}

void Stack::clear()
{
	Node* tmp;
	while(Head){
		tmp = Head;
		Head = Head->next;
		delete tmp;
	}
	size = 0;
}

int Stack::getSize()
{
	return size;
}

void Stack::printData()
{
	if(isEmpty()){
		std::cout << "The stack is empty" << std::endl;
		return;
	}
	Node* trav = Head;
	while(trav){
		std::cout << trav->data << "<-";
		trav = trav->next;
	}
	std::cout << "BOTTOM" << std::endl;
	std::cout << "SIZE: " << getSize() << std::endl;
}
