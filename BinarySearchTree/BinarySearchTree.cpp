#include <iostream>
#include <string>

using namespace std;

class Node {
public:
	string info;
	Node* leftchild;
	Node* rightchild;

	// Constructor for the node class
	Node(string i, Node* l, Node* r)
	{
		info = i;
		leftchild = l;
		rightchild = r;
	}
};

class BinaryTree {
public:
	Node* ROOT;

	BinaryTree() {
		ROOT = NULL; // metode root menjadi null
	}
	
	void insert(string element) {
		Node* newNode = new Node(element, NULL, NULL); // alokasi memori untuk new node
		newNode->info = element; // data dengan nama element
		newNode->leftchild = NULL; // menjadi nilai null
		newNode->rightchild = NULL;

		Node* parent = NULL;
		Node* currentNode = NULL;
		Search(element, parent, currentNode); // lokasi node dimana akan menjadi kepala dari node menjadi insert

		if (parent == NULL) {// if the parent is NULL(empty)
			ROOT = newNode; // membuat newnode = root
			return; // exit
		}

		if (element < parent->info)// if the value in the data field of the new node is less than that of the parent
		{
			parent->leftchild = newNode; // membuat leftchild of the parents point to the newnode
		}
		else if (element > parent->info) // if the value in the data field of the new node is greater than that of the parent
		{
			parent->rightchild = newNode; // membuat leftchild of the parents point to the newnode
		}
	}

	void Search(string element, Node*& parent, Node*& currentNode) {

	}
};
int main()
{

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
