#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include "MaxHeap.h"


class PriorityQueue
{
private:
	MaxHeap heap;
public:
	PriorityQueue();
	PriorityQueue(int capacity);
	void printData();
	void clear();
	void push(int value);
	int pop();
	int top();
	int getSize();
	bool isEmpty();
};

#endif
