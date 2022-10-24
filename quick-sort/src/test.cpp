#include <iostream>
#include <random>
#include <cassert>
#include <algorithm>

#include "quickSort.h"


void testQuicksort();


int main()
{
	testQuicksort();
	return 0;
}

void testQuicksort()
{
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<std::mt19937::result_type> range(100, 10000);

	for(int j = 0; j < 100; j++){
		int sz = range(rng);
		int* array1 = new int[sz];
		int* array2 = new int[sz];
		for(int i = 0; i < sz; i++){
			array1[i] = range(rng);
			array2[i] = array1[i];
		}

		quickSort(array1, 0, sz - 1);
		std::sort(array2, array2 + sz);

		for(int i = 0; i < sz; i++)
			assert(array1[i] == array2[i]);

		delete[] array1;
		delete[] array2;
	}
	std::cout << "[QUICKSORT TEST] PASSED" << std::endl;
}
