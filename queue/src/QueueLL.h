struct Node
{
	int data;
	Node* next;
};


class QueueLL
{
private:
	Node* Head;
	Node* Tail;
	void init(int value);
public:
	QueueLL();
	QueueLL(int value);
	~QueueLL();
	void enqueue(int value);
	int dequeue();
	bool empty();
	void clear();
	int peek();
	void printData();
};
