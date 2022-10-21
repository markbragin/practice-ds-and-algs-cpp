struct Node
{
	int data;
	Node* next;
};


class Queue
{
private:
	Node* Head;
	Node* Tail;
	void init(int value);
public:
	Queue();
	Queue(int value);
	~Queue();
	void enqueue(int value);
	int dequeue();
	bool empty();
	void clear();
	int peek();
	void printData();
};
