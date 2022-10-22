#include <iostream>
#include <stdexcept>

#include "MaxHeap.h"


MaxHeap::MaxHeap() : data{nullptr}, capacity{HEAP_BASIC_SIZE}, size{0}
{
	data = new int[capacity];
}

MaxHeap::MaxHeap(int cap) : data{nullptr}, capacity{HEAP_BASIC_SIZE},
	size{0}
{
	capacity = cap;
	data = new int[capacity];
}

MaxHeap::~MaxHeap()
{
	clear();
}

void MaxHeap::printData()
{
	std::cout << "DATA: \n";
	for(int i = 0; i < size; i++)
		std::cout << data[i] << " ";
	std::cout << std::endl;
}

void MaxHeap::clear()
{
	delete[] data;
}

void MaxHeap::push(int value)
{
	if(size == capacity)
		resize(capacity * 2);
	data[size] = value;
	size++;
	siftUp(size - 1);
}

void MaxHeap::resize(int newCapacity)
{
	capacity = newCapacity;
	int* tmp = data;
	data = new int[capacity];
	for(int i = 0; i < size; i++)
		data[i] = tmp[i];
	delete[] tmp;
}

void MaxHeap::siftUp(int idx)
{
	int parentIdx = getParentIdx(idx);
	while(idx && data[idx] > data[parentIdx]){
		swap(&data[idx], &data[parentIdx]);
		idx = parentIdx;
		parentIdx = getParentIdx(idx);
	}
}

int getParentIdx(int idx)
{
	return (idx - 1)/2;
}

void swap(int* ptr1, int* ptr2)
{
	int tmp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = tmp;
}

int getLeftChildIdx(int idx)
{
	return 2*idx + 1;
}

int getRightChildIdx(int idx)
{
	return 2*idx + 2;
}

int MaxHeap::top()
{
	if(isEmpty())
		throw std::out_of_range("The heap is empty");
	return data[0];
}

bool MaxHeap::isEmpty()
{
	return !size;
}

int MaxHeap::getSize()
{
	return size;
}

int MaxHeap::getCapacity()
{
	return capacity;
}

int MaxHeap::pop()
{
	if(isEmpty())
		throw std::out_of_range("The heap is empty");
	size--;
	int maxValue = data[0];
	swap(&data[0], &data[size]);
	siftDown(0);
	return maxValue;
}

void MaxHeap::siftDown(int idx)
{
	while(true){
		int left = getLeftChildIdx(idx);
		int right = getRightChildIdx(idx);
		int max = idx;
		if(left < size && data[left] > data[max])
			max = left;
		if(right < size && data[right] > data[max])
			max = right;
		if(max == idx)
			break;
		swap(&data[max], &data[idx]);
		idx = max;
	}
}

void MaxHeap::remove(int idx)
{
	swap(&data[idx], &data[size - 1]);
	size--;
	siftDown(idx);
}

void buildMaxHeap(int* array, int len)
{
	for(int i = len/2 - 1; i >= 0; i--)
		heapify(array, len, i);
}

void heapify(int* array, int len, int idx)
{
	while(true){
		int left = getLeftChildIdx(idx);
		int right = getRightChildIdx(idx);
		int max = idx;
		if(left < len && array[left] > array[max])
			max = left;
		if(right < len && array[right] > array[max])
			max = right;
		if(max == idx)
			break;
		swap(&array[max], &array[idx]);
		idx = max;
	}
}

void heapSort(int* array, int len)
{
	buildMaxHeap(array, len);
	while(len){
		len--;
		swap(&array[0], &array[len]);
		heapify(array, len, 0);
	}
}
