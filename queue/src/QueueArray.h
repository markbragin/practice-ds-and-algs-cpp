#define BUF_SIZE 8

class QueueArray
{
private:
	int buf[BUF_SIZE] = {};
	int write_idx;
	int read_idx;
public:
	QueueArray();
	QueueArray(int value);
	void enqueue(int value);
	int dequeue();
	int peek();
	bool empty();
	bool full();
	void clear();
	void printData();
};
