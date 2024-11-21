#define CATCH_CONFIG_MAIN // defines main() automatically
#include "catch.hpp"
#include "BTree.hpp"
// tests for exercise 1

TEST_CASE("Ex1 ", "[Test 1]")
{
	BTree tree;
	vector<int> values = {10, 15, 20, 3, 5, 30, 17};
	for (int value : values) {
		tree.insert(value);
	}
	REQUIRE(tree.getRoot()->getData() == 10);
	REQUIRE(tree.getRoot()->getLeft()->getData() == 3);	
	REQUIRE(tree.getRoot()->getRight()->getData() == 15);
	REQUIRE(tree.getRoot()->getLeft()->getRight()->getData() == 5);
	REQUIRE(tree.getRoot()->getRight()->getRight()->getData() == 20);
	REQUIRE(tree.getRoot()->getRight()->getRight()->getLeft()->getData() == 17);
	REQUIRE(tree.getRoot()->getRight()->getRight()->getRight()->getData() == 30);
}


TEST_CASE("Ex2 ", "[Test 1]")
{
	BTree tree;
	vector<int> values = {8, 3, 10, 1, 6, 14, 9};
	for (int value : values) {
		tree.insert(value);
	}
	REQUIRE(tree.getRoot()->getData() == 8);
	REQUIRE(tree.getRoot()->getLeft()->getData() == 3);
	REQUIRE(tree.getRoot()->getRight()->getData() == 10);
	REQUIRE(tree.getRoot()->getLeft()->getLeft()->getData() == 1);
	REQUIRE(tree.getRoot()->getLeft()->getRight()->getData() == 6);
	REQUIRE(tree.getRoot()->getRight()->getLeft()->getData() == 9);
	REQUIRE(tree.getRoot()->getRight()->getRight()->getData() == 14);
	vector<int> result;
	tree.inorderTraversal(tree.getRoot(), result);
	REQUIRE(result == vector<int>({1, 3, 6, 8, 9, 10, 14}));
	result.clear();
	tree.preorderTraversal(tree.getRoot(), result);
	REQUIRE(result == vector<int>({8, 3, 1, 6, 10, 9, 14}));
	result.clear();
	tree.postorderTraversal(tree.getRoot(), result);
	REQUIRE(result == vector<int>({1, 6, 3, 9, 14, 10, 8}));
}
