#include "ItemType.h"
#ifndef BINARYTREE_H
#define BINARYTREE_H
struct Node{
  public:
  ItemType key;
  Node* left;
  Node* right;
}; // Node
class BinaryTree{

public:
	BinaryTree();
	~BinaryTree();
	void destroy(Node* root);
	void insert(ItemType key);
	void putItem(Node*& root, ItemType item);
	void deleteStart(ItemType& key); // this will call the other delete helper functions
	void deleteItem(Node*& tree, ItemType key);
	void deleteNode(Node *&tree);
	void getPredecessor(Node *root, ItemType &item);
	void retrieve(ItemType &item, bool &found);
	void getItem(Node* root, ItemType &item, bool &found);
	void print(char input);
	void preOrder(Node* root) const;
	void inOrder(Node* root) const;
	void postOrder(Node* root) const;
	int getLength(); 
	int countNodes(Node* root);

private:
	Node* root;
};
#endif
