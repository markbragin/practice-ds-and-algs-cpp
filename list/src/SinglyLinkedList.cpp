#include <iostream>
#include <stdexcept>

#include "SinglyLinkedList.h"


SinglyLinkedList::SinglyLinkedList() : Head{nullptr}, Tail{nullptr}, size{0}
{
}

SinglyLinkedList::SinglyLinkedList(int value) : Head{nullptr},
	Tail{nullptr}, size{0}
{
	Node* newNode = new Node;
	newNode->data = value;
	newNode->next = nullptr;
	Head = newNode;
	Tail = newNode;
	size++;
}

SinglyLinkedList::~SinglyLinkedList()
{
	clear();
}

int SinglyLinkedList::getSize()
{
	return size;
}

bool SinglyLinkedList::isEmpty()
{
	return size == 0;
}

int SinglyLinkedList::valueAt(int index)
{
	if(!isValidIndex(index))
		throw std::out_of_range("List index is out of range");
	Node* trav = Head;
	while(index--)
		trav = trav->next;
	return trav->data;
}

bool SinglyLinkedList::isValidIndex(int index)
{
	if(index >= 0 && index < size)
		return true;
	return false;
}

void SinglyLinkedList::pushFront(int value)
{
	Node* newNode = new Node;
	newNode->data = value;
	newNode->next = Head;
	Head = newNode;
	if(isEmpty())
		Tail = newNode;
	size++;
}

int SinglyLinkedList::popFront()
{
	if(isEmpty())
		throw std::out_of_range("The list is empty");
	Node* tmp = Head;
	int value = tmp->data;
	Head = Head->next;
	delete tmp;
	size--;
	if(isEmpty())
		Tail = nullptr;
	return value;
}

void SinglyLinkedList::pushBack(int value)
{
	Node* newNode = new Node;
	newNode->data = value;
	newNode->next = nullptr;
	if(isEmpty())
		Head = newNode;
	else
		Tail->next = newNode;
	Tail = newNode;
	size++;
}

int SinglyLinkedList::popBack()
{
	if(isEmpty())
		throw std::out_of_range("The list is empty");
	Node* prev = nullptr;
	Node* cur = Head;
	while(cur != Tail){
		prev = cur;
		cur = cur->next;
	}
	Tail = prev;
	int value = cur->data;
	delete cur;
	size--;
	if(isEmpty())
		Head = nullptr;
	else
		Tail->next = nullptr;
	return value;
}

int SinglyLinkedList::front()
{
	if(isEmpty())
		throw std::out_of_range("The list is empty");
	return Head->data;
}

int SinglyLinkedList::back()
{
	if(isEmpty())
		throw std::out_of_range("The list is empty");
	return Tail->data;
}

void SinglyLinkedList::insert(int index, int value)
{
	if(index == size)
		pushBack(value);
	else if(index == 0)
		pushFront(value);
	else{
		Node* prev = Head;
		for(int i = 0; i < index - 1; i++)
			prev = prev->next;
		Node* newNode = new Node;
		newNode->data = value;
		newNode->next = prev->next;
		prev->next = newNode;
		size++;
	}
}

int SinglyLinkedList::pop(Node* node)
{
	if(node == Head)
		return popFront();
	if(node == Tail)
		return popBack();

	Node* prev = nullptr;
	Node* cur = Head;
	while(cur != node){
		prev = cur;
		cur = cur->next;
	}
	prev->next = cur->next;
	int value = cur->data;
	delete cur;
	return value;
}

void SinglyLinkedList::erase(int index)
{
	if(!isValidIndex(index))
		throw std::out_of_range("List index out of range");
	if(index == 0)
		popFront();
	else if(index == size - 1)
		popBack();
	else{
		Node* prev = nullptr;
		Node* cur = Head;
		while(index--){
			prev = cur;
			cur = cur->next;
		}
		prev->next = cur->next;
		delete cur;
		size--;
	}
}

int SinglyLinkedList::valueNFromEnd(int n)
{
	if(!isValidIndex(n - 1))
		throw std::out_of_range("List index out of range");
	Node* trav = Head;
	for(;n != size; n++)
		trav = trav->next;
	return trav->data;
}

void SinglyLinkedList::removeValue(int value)
{
	Node* prev = nullptr;
	Node* cur = Head;
	while(cur){
		if(cur->data == value){
			if(prev == nullptr)
				Head = cur->next;
			else
				prev->next = cur->next;
			if(cur == Tail)
				Tail = prev;
			delete cur;
			size--;
			break;
		}
		prev = cur;
		cur = cur->next;
	}
}

void SinglyLinkedList::reverse()
{
	if(size < 2)
		return;
	Node* prev = nullptr;
	Node* cur = Head;
	Node* next = nullptr;
	while(cur){
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	Tail = Head;
	Head = prev;
}

void SinglyLinkedList::clear()
{
	Node* trav = Head;
	Node* tmp = nullptr;
	while(trav){
		tmp = trav;
		trav = trav->next;
		delete tmp;
	}
	Head = Tail = nullptr;
	size = 0;
}

void SinglyLinkedList::printData()
{
	Node* trav = Head;
	while(trav){
		std::cout << trav->data << "->";
		trav = trav->next;
	}
	std::cout << "null" << std::endl;
}
