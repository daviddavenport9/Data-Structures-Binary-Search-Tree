#include <iostream>
#include "BinaryTree.h"
using namespace std;

BinaryTree::BinaryTree() {
	root = NULL;
}

BinaryTree::~BinaryTree() {
	destroy(root);
}

void BinaryTree::destroy(Node* tree) {
	if (tree != NULL) { // if tree is created, delete all nodes in postorder
		destroy(tree->left);
		destroy(tree->right);
		delete tree;
	} // if
}

void BinaryTree::retrieve(ItemType& item, bool& found) {
  getItem(root, item, found);
}

void BinaryTree::getItem(Node* root, ItemType& item, bool& found) {
  if (root == NULL){
    found = false;
  }//if
  else if (item.compareTo(root->key) == LESS){
    getItem(root->left, item, found);
  }//else if
  else if (item.compareTo(root->key) == GREATER){
    getItem(root->right, item, found);
  }//else if
  else{
    item = root->key;
    found = true;
  }  
}

void BinaryTree::insert(ItemType key) {
	bool isFound = false;
	retrieve(key, isFound);
	if (isFound) {
		cout << "Item already exists" << endl;
	}
	else {
		putItem(root, key);
	}
}

void BinaryTree::putItem(Node*& root, ItemType key) {
  if (root == NULL){
    root = new Node;
    root->right = NULL;
    root->left = NULL;
    root->key = key;
  }//if
  else if (key.compareTo(root->key) == LESS){
    putItem(root->left, key);
  }//else if
  else{
    putItem(root->right, key);
  }
}//putItem

void BinaryTree::deleteStart(ItemType& key) {//start of delete function that calls 
	bool isFound = false;
	retrieve(key, isFound);
	if (isFound) {
		deleteItem(root, key);
	}
	else {
		cout << "Item not found" << endl;
	}
}

void BinaryTree::deleteItem(Node*& tree, ItemType key) {
	if (key.compareTo(tree->key) == LESS) {
		deleteItem(tree->left, key);
	}
	else if (key.compareTo(tree->key) == GREATER) {
		deleteItem(tree->right, key);
	}
	else { // once item is found, delete node
		deleteNode(tree);
	} // if
}

void BinaryTree::deleteNode(Node*& tree) {
	ItemType data;
	Node* temp;
	temp = tree;
	if (tree->left == NULL) { // only 1 child
		tree = tree->right;
		delete temp;
	}
	else if (tree->right == NULL) { // only 1 child
		tree = tree->left;
		delete temp;
	}
	else { // 2 children, must get logical predecessor
		getPredecessor(tree->left, data);
		tree->key.initialize(data.getValue());
		deleteItem(tree->left, data);
	} // if
}

void BinaryTree::getPredecessor(Node* root, ItemType& item) {//gets the logical predecessor of the tree
	while (root->right != NULL) {
		root = root->right;
	} // while
	item.initialize(root->key.getValue());
}

void BinaryTree::print(char command) {//prints the correct print function based on the command the user enters
	if (command == 'n') {
		inOrder(root);
	}
	else if (command == 'p') {
		preOrder(root);
	}
	else if (command == 'o') {
		postOrder(root);
	}
}

void BinaryTree::preOrder(Node* root) const {
	if (root != NULL) {
		root->key.print();
		preOrder(root->left);
		preOrder(root->right);
	} // if
}

void BinaryTree::inOrder(Node* root) const {
	if (root != NULL) {
		inOrder(root->left);
		root->key.print();
		inOrder(root->right);
	} // if
}

void BinaryTree::postOrder(Node* root) const {
	if (root != NULL) {
		postOrder(root->left);
		postOrder(root->right);
		root->key.print();
	} // if
}

int BinaryTree::getLength() {
	return countNodes(root);
}

int BinaryTree::countNodes(Node *root) {
	if (root == NULL) {
		return 0;
	}else {
		return countNodes(root->left) + countNodes(root->right) + 1;
	} // if
}
