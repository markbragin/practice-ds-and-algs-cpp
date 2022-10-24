#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H


enum TRAVERSAL_ORDER
{
	PRE_OREDER,
	IN_ORDER,
	POST_ORDER,
	LEVEL_ORDER
};

struct Node
{
	int data;
	Node* left;
	Node* right;
};


class BinarySearchTree
{
private:
	Node* root;
	int size;
	Node* getNewNode(int value);
	void printPreorder();
	void printInorder();
	void printPostorder();
	void printLevelorder();
	void searchValue(Node*& node, Node*& parent, int value);
	void removeLeaf(Node* node, Node* parent);
	void removeTwoChildrenNode(Node* node);
	void removeOneChildNode(Node* node, Node* parent);
public:
	BinarySearchTree();
	BinarySearchTree(int value);
	~BinarySearchTree();
	bool empty();
	bool insert(int value);
	int getSize();
	void clear();
	void printValues(TRAVERSAL_ORDER order);
	Node* find(int value);
	int getHeight();
	static int getHeight(Node* node);
	int getHeightRec();
	static int getHeightRec(Node* node);
	int getMin();
	static Node* getMinNode(Node* node);
	int getMax();
	static Node* getMaxNode(Node* node);
	void deleteValue(int value);
	Node* getSuccessor(int value);
};

#endif
