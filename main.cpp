#include <iostream>
#include "BinaryTree.h"
#include "ItemType.h"
#include <fstream>
#include <string>

using namespace std;

int main(const int argc, const char* argv[])
{
	BinaryTree tree;
	ItemType item;
	fstream fs;
	int input;
	fs.open(argv[1], fstream::in);
	if (fs.is_open()) {
		fs >> input;
		while (!fs.eof()) {
			item.initialize(input);
			tree.insert(item);
			fs >> input;
		} // while
	}//if
	else {
		cout << "Failed to open the input file" << endl;
		return 0;
	} // else
 cout << "Commands - insert (i), delete (d), retrieve (r), length (l), in-order (n), pre-order (p), post-order (o), quit(q)" << endl;
 char command; 
 while (true){
 cout << "Enter a command: ";
 cin >> command;
 if (command == 'i'){
   int numInsert;
   cout << "Number to insert: ";
   cin >> numInsert;
   item.initialize(numInsert);
   tree.insert(item);
   char inOrder = 'n'; //to pass into print function
   cout << "" << endl;
   cout << "In-Order: ";
   tree.print(inOrder);
   cout << "" << endl;
 }//if i
 else if (command == 'd'){
	 bool flag = false;
	 int input;
	 cout << "Item to delete: ";
	 cin >> input;
	 item.initialize(input);
	 tree.deleteStart(item);
   char inOrder = 'n';
   cout << "" << endl;
   cout << "In-Order: ";
   tree.print(inOrder);
   cout << "" << endl;
 }//else if d
 else if (command == 'r'){
	 bool flag = false;
	 int input;
	 cout << "Item to be retrieved: ";
	 cin >> input;
	 item.initialize(input);
	 tree.retrieve(item, flag);
	 if (flag) {
		 cout << "Item found in tree" << endl;
	 }
	 else {
		 cout << "Item not found" << endl;
	 } // if
 }//else if r
 else if (command == 'l'){
   cout << "List length: " << tree.getLength() << endl;
 }//else if l
 else if (command == 'n'){
   cout << "In-Order: ";
	 tree.print(command);
   cout << "" << endl;
 }//else if n
 else if (command == 'p'){
   cout << "Pre-Order: ";
	 tree.print(command);
   cout << "" << endl;
 }//else if p
 else if (command == 'o'){
	 cout << "Post-Order: ";
   tree.print(command);
   cout << "" << endl;
 }//else if o
 else if (command == 'q'){
   cout << "Quitting program..." << endl;
   exit(0);
 }//else if q
 else{
    cout << "Command not recognized. Try again." << endl;
 }//else
 }
}//main

