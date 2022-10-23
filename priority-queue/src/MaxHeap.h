#ifndef MAX_HEAP_H
#define MAX_HEAP_H

#define HEAP_BASIC_SIZE 16


class MaxHeap
{
private:
	int* data;
	int capacity;
	int size;
	void resize(int newCapacity);
	void siftUp(int idx);
	void siftDown(int idx);
public:
	MaxHeap();
	MaxHeap(int capacity);
	~MaxHeap();
	void printData();
	void clear();
	void push(int value);
	int top();
	int getSize();
	int getCapacity();
	bool isEmpty();
	int pop();
	void remove(int idx);
};

void swap(int* ptr1, int* ptr2);
int getParentIdx(int idx);
int getLeftChildIdx(int idx);
int getRightChildIdx(int idx);

void buildMaxHeap(int* array, int len);
void heapify(int* array, int len, int idx);
void heapSort(int* array, int len);

#endif
