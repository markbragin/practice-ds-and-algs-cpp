#include <iostream>
#include <random>
#include <queue>
#include <algorithm>
#include <cassert>

#include "MaxHeap.h"
#include "PriorityQueue.h"

void testBuildMaxHeap();
void testPriorityQueue();
void testHeapSort();
void testHeap();
void interactive();


int main()
{
	testHeap();
	testPriorityQueue();
	testHeapSort();
	/* interactive(); */
	return 0;
}

void testHeap()
{
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<std::mt19937::result_type> range(100, 1000);

	for(int i = 0; i < 100; i++)
	{
		MaxHeap heap;
		std::priority_queue<int> pq;
		int heapSize = range(rng);

		for(int j = 0; j < heapSize; j++){
			int value = range(rng);
			heap.push(value);
			pq.push(value);
			assert(heap.top() == pq.top());
		}

		for(int j = 0; j < heapSize; j++){
			assert(heap.pop() == pq.top());
			pq.pop();
			assert(heap.isEmpty() == pq.empty());
			assert(heap.getSize() == static_cast<int>(pq.size()));
		}
	}
	std::cout << "[Heap test] PASSED" << std::endl;
}

void testPriorityQueue()
{
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<std::mt19937::result_type> range(100, 1000);

	for(int i = 0; i < 100; i++)
	{
		PriorityQueue myPq;
		std::priority_queue<int> pq;
		int pqSize = range(rng);

		for(int j = 0; j < pqSize; j++){
			int value = range(rng);
			myPq.push(value);
			pq.push(value);
			assert(myPq.top() == pq.top());
		}

		for(int j = 0; j < pqSize; j++){
			assert(myPq.pop() == pq.top());
			pq.pop();
			assert(myPq.isEmpty() == pq.empty());
			assert(myPq.getSize() == static_cast<int>(pq.size()));
		}
	}
	std::cout << "[PriorityQueue test] PASSED" << std::endl;
}

void testHeapSort()
{
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<std::mt19937::result_type> range(100, 1000);

	for(int i = 0; i < 100; i++){
		int arraySize = range(rng);
		int* array1 = new int[arraySize];
		int* array2 = new int[arraySize];
		for(int j = 0; j < arraySize; j++){
			array1[j] = range(rng);
			array2[j] = array1[j];
		}
		heapSort(array1, arraySize);
		std::sort(array2, array2 + arraySize);
		for(int j = 0; j < arraySize; j++)
			assert(array1[j] == array2[j]);
	}
	std::cout << "[HeapSort test] PASSED" << std::endl;
}

void interactive()
{
	MaxHeap heap;
	heap.printData();
	char key;
	int value;
	while(true){
		std::cin >> key;
		switch(key){
			case 'i':
				std::cin >> value;
				std::cout << "PUSH: " << value << std::endl;
				heap.push(value);
				break;
			case 'p':
				std::cout << "POP: " << heap.pop() << std::endl;
				break;
			case 't':
				std::cout << "TOP: " << heap.top() << std::endl;
				break;
			case 'd':
				heap.printData();
				break;
		}
	}
}
