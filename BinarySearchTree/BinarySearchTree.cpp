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
		// this function searches the currentNode of the specified Node as well as the current Node of ts parent
		currentNode = ROOT;
		parent = NULL;
		while ((currentNode != NULL) && (currentNode->info != element)) {
			parent = currentNode;
			if (element < currentNode->info)
				currentNode = currentNode->leftchild;
			else
				currentNode = currentNode->rightchild;
		}
	}

	void inorder(Node* ptr)
	{
		if (ROOT == NULL) {
			cout << " Tree is empty" << endl;
			return;
		}
		if (ptr != NULL) {
			inorder(ptr->leftchild);
			cout << ptr->info << " ";
			inorder(ptr->rightchild);

		}
	}

	void preorder(Node* ptr)
	{
		if (ROOT == NULL)
		{
			cout << "Tree is empty" << endl;
			return;
		}
		if (ptr != NULL)
		{
			cout << ptr->info << " ";
			preorder(ptr->leftchild);
			preorder(ptr->rightchild);
		}
	}

	void postorder(Node* ptr) {
		// performs the postorder traversal of the three
		if (ROOT == NULL)
		{
			cout << "Tree is empty" << endl;
			return;
		}
		if (ptr != NULL)
		{
			postorder(ptr->leftchild);
			postorder(ptr->rightchild);
			cout << ptr->info << " ";
		}
	}
};


int main()
{
	BinaryTree obj;
	while (true)
	{

		cout << "\nMenu" << endl;
		cout << "1. Implement insert operation" << endl;
		cout << "2. Perfom inorder traversal" << endl;
		cout << "3. Perform preorder traversal" << endl;
		cout << "4. Perform postorder traversal" << endl;
		cout << "5. Exit" << endl;
		cout << "\nEnter your choice (1-5) : ";

		char ch;
		cin >> ch;
		cout << endl;

		switch (ch) {
		case '1':
		{
			cout << "Enter a word: ";
			string word;
			cin >> word;
			obj.insert(word);
			break;
		}
		case '2':
		{
			obj.inorder(obj.ROOT);
			break;
		}
		case '3':
		{
			obj.preorder(obj.ROOT);
			break;
		}
		case '4':
		{
			obj.postorder(obj.ROOT);
			break;
		}
		case '5':
			return 0;
		default:
		{
			cout << "Invalid option" << endl;
			break;
		}
		}
	}
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
