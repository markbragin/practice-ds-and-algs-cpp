#include <iostream>
#include <random>
#include <cassert>

#include "BinarySearchTree.h"


void testRemoval();
void testHeight();
void interactive();


int main()
{
	testRemoval();
	testHeight();
	/* interactive(); */
	return 0;
}

void testHeight()
{
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<std::mt19937::result_type> range(100, 1000);

	BinarySearchTree bst;
	for(int j = 0; j < 10; j++){
		int sz = range(rng);
		for(int i = 0; i < sz; i++){
			bst.insert(range(rng));
			assert(bst.getHeight() == bst.getHeightRec());
		}
		bst.clear();
	}
	std::cout << "[HEIGHT TEST] PASSED" << std::endl;
}

void testRemoval()
{
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<std::mt19937::result_type> range(100, 1000);

	BinarySearchTree bst;
	for(int j = 0; j < 10; j++){
		int sz = range(rng);
		int* array = new int[sz];
		for(int i = 0; i < sz; i++){
			array[i] = range(rng);
			bst.insert(array[i]);
		}
		std::uniform_int_distribution<std::mt19937::result_type> r(0, sz);
		for(int i = 0; i < sz; i++){
			int rand_idx = r(rng);
			bst.deleteValue(array[rand_idx]);
			assert(!bst.find(array[rand_idx]));
		}
		bst.clear();
	}
	std::cout << "[REMOVAL TEST] PASSED" << std::endl;
}

void interactive()
{
	BinarySearchTree bst;
	char key;
	int value;
	while(true){
		std::cin >> key;
		switch(key){
			case 'i':
				std::cin >> value;
				std::cout << "insert: " << value << std::endl;
				bst.insert(value);
				break;
			case 'd':
				std::cin >> value;
				bst.deleteValue(value);
				break;
			case 'p':
				std::cin >> value;
				switch(value){
					case 1:
						bst.printValues(PRE_OREDER);
						break;
					case 2:
						bst.printValues(IN_ORDER);
						break;
					case 3:
						bst.printValues(POST_ORDER);
						break;
					case 4:
						bst.printValues(LEVEL_ORDER);
						break;

				}
				break;
			case 'c':
				bst.clear();
				break;
			case 'h':
				std::cout << "HEIGHT: " << bst.getHeight() << std::endl;
				break;
			case 'H':
				std::cout << "HEIGHT: " << bst.getHeightRec()
					<< std::endl;
				break;
			case 'm':
				std::cout << "MIN: " << bst.getMin() << std::endl;
				break;
			case 'M':
				std::cout << "MAX: " << bst.getMax() << std::endl;
				break;
			case 's':
				std::cin >> value;
				std::cout << "SUCCESSOR OF " << value << ":"
					<< bst.getSuccessor(value)->data << std::endl;
				break;
		}
	}
}
