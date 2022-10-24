#include <cstdlib>
#include <ctime>
#include <iostream>

#include "quickSort.h"


void quickSort(int* array, int left, int right)
{
	if(left >= right)
		return;
	int p = partition(array, left, right);
	quickSort(array, left, p - 1);
	quickSort(array, p + 1, right);
}

int partition(int* array, int left, int right)
{
	srand(time(NULL));
	swap(array[left + rand() % (right - left + 1)], array[right]);
	int i = left - 1;
	for(int j = left; j < right; j++)
		if(array[j] < array[right]){
			i++;
			swap(array[j], array[i]);
		}
	swap(array[++i], array[right]);
	return i;
}

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
