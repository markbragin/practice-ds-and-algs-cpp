#include <iostream>
#include <cassert>
#include <stack>
#include <queue>

#include "BinarySearchTree.h"


BinarySearchTree::BinarySearchTree() : root{nullptr}, size{0}
{
}

BinarySearchTree::BinarySearchTree(int value) : root{nullptr}, size{0}
{
	root = getNewNode(value);
}

Node* BinarySearchTree::getNewNode(int value)
{
	return (Node*) new Node{value, nullptr, nullptr};
}

BinarySearchTree::~BinarySearchTree()
{
	clear();
}

void BinarySearchTree::clear()
{
	std::stack<Node*> stack;
	Node* current = root;
	Node* lastVisitedNode = nullptr;
	while(!stack.empty() || current){
		if(current){
			stack.push(current);
			current = current->left;
		}
		else{
			Node* top = stack.top();
			if(top->right && lastVisitedNode != top->right)
				current = top->right;
			else{
				lastVisitedNode = top;
				stack.pop();
				delete top;
			}
		}
	}
	root = nullptr;
	size = 0;
}

bool BinarySearchTree::insert(int value)
{
	if(!root){
		root = getNewNode(value);
		size++;
		return true;
	}

	Node* current = root;
	while(true){
		if(value < current->data){
			if(!current->left){
				current->left = getNewNode(value);
				break;
			}
			current = current->left;
		}
		else if(value > current->data){
			if(!current->right){
				current->right = getNewNode(value);
				break;
			}
			current = current->right;
		}
		else
			return false;
	}
	size++;
	return true;
}

bool BinarySearchTree::empty()
{
	return !root;
}

int BinarySearchTree::getSize()
{
	return size;
}

void BinarySearchTree::printValues(TRAVERSAL_ORDER order)
{
	switch(order){
		case PRE_OREDER:
			printPreorder();
			break;
		case IN_ORDER:
			printInorder();
			break;
		case POST_ORDER:
			printPostorder();
			break;
		case LEVEL_ORDER:
			printLevelorder();
			break;
	}
}

void BinarySearchTree::printPreorder()
{
	if(empty())
		return;

	std::stack<Node*> stack;
	stack.push(root);
	while(!stack.empty()){
		Node* current = stack.top();
		std::cout << current->data << " ";
		stack.pop();
		if(current->right)
			stack.push(current->right);
		if(current->left)
			stack.push(current->left);
	}
	std::cout << std::endl << std::endl;
}

void BinarySearchTree::printInorder()
{
	std::stack<Node*> stack;
	Node* current = root;
	while(!stack.empty() || current){
		if(current){
			stack.push(current);
			current = current->left;
		}
		else{
			current = stack.top();
			std::cout << current->data << " ";
			stack.pop();
			current = current->right;
		}
	}
	std::cout << std::endl << std::endl;

}

void BinarySearchTree::printPostorder()
{
	std::stack<Node*> stack;
	Node* current = root;
	Node* lastVisitedNode = nullptr;
	while(!stack.empty() || current){
		if(current){
			stack.push(current);
			current = current->left;
		}
		else{
			Node* top = stack.top();
			if(top->right && lastVisitedNode != top->right)
				current = top->right;
			else{
				lastVisitedNode = top;
				stack.pop();
				std::cout << top->data << " ";
			}
		}
	}
	std::cout << std::endl << std::endl;
}

void BinarySearchTree::printLevelorder()
{
	if(empty())
		return;
	std::queue<Node*> queue;
	queue.push(root);
	while(!queue.empty()){
		Node* top = queue.front();
		std::cout << top->data << " ";
		if(top->left)
			queue.push(top->left);
		if(top->right)
			queue.push(top->right);
		queue.pop();
	}
	std::cout << std::endl << std::endl;
}

Node* BinarySearchTree::find(int value)
{
	Node* current = root;
	while(current){
		if(value == current->data)
			return current;
		else if(value < current->data)
			current = current->left;
		else
			current = current->right;
	}
	return nullptr;
}

int BinarySearchTree::getHeight()
{
	return getHeight(root);
}

int BinarySearchTree::getHeight(Node* node)
{
	Node* lastVisitedNode = nullptr;
	int height = 0;
	std::stack<Node*> stack;
	while(!stack.empty() || node){
		if(node){
			stack.push(node);
			node = node->left;
		}
		else{
			Node* top = stack.top();
			if(top->right && lastVisitedNode != top->right)
				node = top->right;
			else{
				if(static_cast<int>(stack.size()) > height)
					height = stack.size();
				stack.pop();
				lastVisitedNode = top;
			}
		}
	}
	return height - 1;
}

int BinarySearchTree::getHeightRec()
{
	return getHeightRec(root);
}

int BinarySearchTree::getHeightRec(Node* node)
{
	if(!node)
		return -1;
	int leftHeight = getHeightRec(node->left);
	int rightHeight = getHeightRec(node->right);
	if(leftHeight > rightHeight)
		return leftHeight + 1;
	else
		return rightHeight + 1;

}

int BinarySearchTree::getMin()
{
	return getMinNode(root)->data;
}

Node* BinarySearchTree::getMinNode(Node* node)
{
	assert(node);
	while(node->left)
		node = node->left;
	return node;
}

int BinarySearchTree::getMax()
{
	return getMaxNode(root)->data;
}

Node* BinarySearchTree::getMaxNode(Node* node)
{
	assert(node);
	while(node->right)
		node = node->right;
	return node;
}

void BinarySearchTree::deleteValue(int value)
{
	Node* parent = nullptr;
	Node* current = root;

	searchValue(current, parent, value);

	if(!current)
		return;

	if(!(current->left || current->right))
		removeLeaf(current, parent);
	else if(current->left && current->right)
		removeTwoChildrenNode(current);
	else
		removeOneChildNode(current, parent);
}

void BinarySearchTree::searchValue(Node*& node, Node*& parent, int value)
{
	while(node && value != node->data){
		parent = node;
		if(value < node->data)
			node = node->left;
		else
			node = node->right;
	}
}

void BinarySearchTree::removeLeaf(Node* node, Node* parent)
{
	if(node == root)
		root = nullptr;
	else{
		if(parent->left == node)
			parent->left = nullptr;
		else
			parent->right = nullptr;
	}
	delete node;
}

void BinarySearchTree::removeTwoChildrenNode(Node* node)
{
	Node* successor = getMinNode(node->right);
	int value = successor->data;
	deleteValue(successor->data);
	node->data = value;
}

void BinarySearchTree::removeOneChildNode(Node* node, Node* parent)
{
	Node* child = node->left ? node->left : node->right;
	if(node == root)
		root = child;
	else{
		if(node == parent->left)
			parent->left = child;
		else
			parent->right = child;
	}
	delete node;
}

Node* BinarySearchTree::getSuccessor(int value)
{
	if(!find(value))
		return nullptr;
	Node* current = root;
	Node* successor = nullptr;
	while(current){
		if(current->data > value){
			successor = current;
			current = current->left;
		}
		else
			current = current->right;
	}
	return successor;
}
