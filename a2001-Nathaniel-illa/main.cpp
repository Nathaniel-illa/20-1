#include "Node.hpp"
#include "BTree.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{

	// Test 1: Insertion and traversal of a tree with a known structure
	vector<int> tree_values = {10, 15, 20, 3, 5, 30, 17};
	vector<int> result;

	BTree tree;
	for (int value : tree_values) {
		tree.insert(value);
		cout << value << " inserted" << endl;
	}
	cout << "----------------------------------------" << endl;
	cout << "Test 1: Inorder traversal of the tree" << endl;
	tree.inorderTraversal(tree.getRoot(), result);
	for (int value : result) 
		cout << value << " ";
	cout << endl;
	result.clear();

	tree.preorderTraversal(tree.getRoot(), result);
	for (int value : result) 
		cout << value << " ";
	cout << endl;
	result.clear();

	tree.postorderTraversal(tree.getRoot(), result);
	for (int value : result) 
		cout << value << " ";
	cout << endl;
	result.clear();

	cout << "----------------------------------------" << endl;
	cout << "Test 2: Insertion and traversal of a tree with random values" << endl;
	// Test 2: Insertion and traversal of a tree with random values
	srand(time(0));
	for (int i = 0; i < 32; i++) {
		int value = rand() % 100;
		tree.insert(value);
		cout << value << " inserted" << endl;
	}

	tree.inorderTraversal(tree.getRoot(), result);
	for (int value : result) 
		cout << value << " ";
	cout << endl;
	result.clear();

	tree.preorderTraversal(tree.getRoot(), result);
	for (int value : result) 
		cout << value << " ";
	cout << endl;
	result.clear();

	tree.postorderTraversal(tree.getRoot(), result);
	for (int value : result) 
		cout << value << " ";
	cout << endl;
}
