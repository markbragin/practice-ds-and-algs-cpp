#include <iostream>
#include <stdexcept>

#include "QueueArray.h"


QueueArray::QueueArray() : write_idx{0}, read_idx{0}
{
}

QueueArray::QueueArray(int value) : write_idx{0}, read_idx{0}
{
	enqueue(value);
}

void QueueArray::enqueue(int value)
{
	if(full())
		throw std::out_of_range("The queue is full");
	buf[write_idx] = value;
	write_idx = (write_idx + 1) % BUF_SIZE;
}

int QueueArray::dequeue()
{
	if(empty())
		throw std::out_of_range("The queue is empty");
	int value = buf[read_idx];
	read_idx = (read_idx + 1) % BUF_SIZE;
	return value;
}

int QueueArray::peek()
{
	if(empty())
		throw std::out_of_range("The queue is empty");
	return buf[read_idx];
}

bool QueueArray::full()
{
	return (write_idx + 1) % BUF_SIZE == read_idx;
}

bool QueueArray::empty()
{
	return write_idx == read_idx;
}

void QueueArray::clear()
{
	write_idx = read_idx = 0;
}

void QueueArray::printData()
{
	if(empty()){
		std::cout << "The queue is empty" << std::endl;
		return;
	}
	for(int i = read_idx; i % BUF_SIZE != write_idx % BUF_SIZE; i++)
		std::cout << buf[i % BUF_SIZE] << "<-";
	std::cout << "END" << std::endl;
}
