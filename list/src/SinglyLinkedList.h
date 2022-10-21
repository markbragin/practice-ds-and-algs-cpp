struct Node
{
	int data;
	Node* next;
};


class SinglyLinkedList
{
private:
	Node* Head;
	Node* Tail;
	int size;
	bool isValidIndex(int index);
public:
	SinglyLinkedList();
	SinglyLinkedList(int value);
	int getSize();
	bool isEmpty();
	int valueAt(int index);
	void pushFront(int value);
	void printData();
	int popFront();
	void pushBack(int value);
	int popBack();
	int front();
	int back();
	void insert(int index, int value);
	int pop(Node* node);
	void erase(int index);
	int valueNFromEnd(int n);
	void removeValue(int value);
	void reverse();
};
