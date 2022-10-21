struct Node
{
	int data;
	Node* next;
};

class Stack
{
private:
	Node* Head;
	int size;
public:
	Stack();
	Stack(int value);
	~Stack();
	int getSize();
	void push(int value);
	int top();
	void pop();
	bool isEmpty();
	void clear();
	void printData();
};
