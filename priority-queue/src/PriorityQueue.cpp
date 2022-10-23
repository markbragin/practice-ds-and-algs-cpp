#include "PriorityQueue.h"


PriorityQueue::PriorityQueue()
{
}

PriorityQueue::PriorityQueue(int cap) : heap{cap}
{
}

void PriorityQueue::printData()
{
	heap.printData();
}

void PriorityQueue::clear()
{
	heap.clear();
}

void PriorityQueue::push(int value)
{
	heap.push(value);
}

int PriorityQueue::pop()
{
	return heap.pop();
}

int PriorityQueue::top()
{
	return heap.top();
}

int PriorityQueue::getSize()
{
	return heap.getSize();
}

bool PriorityQueue::isEmpty()
{
	return heap.isEmpty();
}
