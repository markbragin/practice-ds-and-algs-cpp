#define BASIC_ARRAY_CAPACITY 16

class Array
{
private:
	int capacity = BASIC_ARRAY_CAPACITY;
	int size = 0;
	int* data = nullptr;
	void resize(int new_capacity);
	bool isValidIndex(int index);
public:
	Array(int capacity = BASIC_ARRAY_CAPACITY);
	int getSize();
	int getCapacity();
	bool isEmpty();
	int at(int index);
	void set(int index, int value);
	void push(int value);
	void insert(int index, int value);
	void prepend(int value);
	int pop();
	int find(int value);
	void deletee(int index);
	void printInfo();
	void printData();
};

