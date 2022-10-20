#include <iostream>
#include <stdexcept>

#include "Array.h"

Array::Array(int capacity)
{
	if(capacity <= 0)
		throw std::invalid_argument("Capacity must be > 0");
	this->capacity = capacity;
	data = new int[capacity]{};
}

int Array::getSize()
{
	return this->size;
}

int Array::getCapacity()
{
	return this->capacity;
}

bool Array::isEmpty()
{
	return this->size == 0;
}

int Array::at(int index)
{
	if(!this->isValidIndex(index))
		throw std::out_of_range("Array index out of range");
	return *(this->data + index);
}

bool Array::isValidIndex(int index)
{
	return index >= 0 && index < this->size;
}

void Array::set(int index, int value)
{
	if(!this->isValidIndex(index))
		throw std::out_of_range("Array index out of range");
	*(this->data + index) = value;
}

void Array::push(int value)
{
	if(this->size == this->capacity){
		this->resize(this->capacity * 2);
	}
	*(this->data + this->size) = value;
	this->size++;
}

void Array::resize(int new_capacity)
{
	this->capacity = new_capacity;
	int* tempData = this->data;
	this->data = new int[this->capacity];
	for(int i = 0; i < this->size; i++)
		*(this->data + i) = *(tempData + i);
	delete[] tempData;
}

void Array::insert(int index, int value)
{
	if(!this->isValidIndex(index))
		throw std::out_of_range("Array index out of range");
	if(this->size == this->capacity)
		this->resize(this->capacity * 2);
	for(int i = size; i > index; i--)
		*(this->data + i) = *(this->data + i - 1);
	*(this->data + index) = value;
	this->size++;
}

void Array::prepend(int value)
{
	this->insert(0, value);
}

int Array::pop()
{
	if(this->size == this->capacity / 4)
		this->resize(this->capacity / 2);
	if(this->size == 0)
		throw std::out_of_range("Array is empty");
	this->size--;
	return *(this->data + size);
}

void Array::deletee(int index)
{
	if(!this->isValidIndex(index))
		throw std::out_of_range("Array index out of range");
	for(int i = index; i < this->size - 2; i++)
		*(this->data + i) = *(this->data + i + 1);
	this->size--;
}

int Array::find(int value)
{
	for(int i = 0; i < this->size; i++)
		if(*(this->data + i) == value)
			return i;
	return -1;
}

void Array::printInfo()
{
	std::cout << "Capacity: " << this->capacity << " "
		      << "Size: " << this->size << std::endl;
}

void Array::printData()
{
	if(this->size == 0)
		std::cout << "The array is empty!";
	else
		for(int i = 0; i < this->size; i++)
			std::cout << this->data[i] << " ";
	std::cout << std::endl;
}
