#ifndef BTREE_HPP
#define BTREE_HPP

#include "Node.hpp"
#include <vector>
#include <iostream>

// Represents the binary tree structure
class BTree {
private:
    Node* root; // Pointer to the root of the tree

    // Helper function for inserting a value into the tree
    void insert(Node*& current, int value) {
        if (!current) {
            current = new Node(value); // Create a new node if current is null
        } else if (value < current->getData()) {
            insert(current->getLeft(), value); // Insert into the left subtree
            if (!current->getLeft()) {
                current->setLeft(new Node(value));
            }
        } else {
            insert(current->getRight(), value); // Insert into the right subtree
            if (!current->getRight()) {
                current->setRight(new Node(value));
            }
        }
    }

    // Helper function for inorder traversal
    void inorderTraversalHelper(Node* current, std::vector<int>& result) const {
        if (current) {
            inorderTraversalHelper(current->getLeft(), result); // Visit left subtree
            result.push_back(current->getData());               // Visit root
            inorderTraversalHelper(current->getRight(), result);// Visit right subtree
        }
    }

    // Helper function for preorder traversal
    void preorderTraversalHelper(Node* current, std::vector<int>& result) const {
        if (current) {
            result.push_back(current->getData());               // Visit root
            preorderTraversalHelper(current->getLeft(), result);// Visit left subtree
            preorderTraversalHelper(current->getRight(), result);// Visit right subtree
        }
    }

    // Helper function for postorder traversal
    void postorderTraversalHelper(Node* current, std::vector<int>& result) const {
        if (current) {
            postorderTraversalHelper(current->getLeft(), result);// Visit left subtree
            postorderTraversalHelper(current->getRight(), result);// Visit right subtree
            result.push_back(current->getData());                // Visit root
        }
    }

    // Helper function to clear the tree
    void clear(Node* current) {
        if (current) {
            clear(current->getLeft());
            clear(current->getRight());
            delete current; // Free memory for the node
        }
    }

public:
    // Constructor to initialize the tree as empty
    BTree() : root(nullptr) {}

    // Destructor to clean up the tree
    ~BTree() {
        clear(root);
    }

    // Inserts a value into the binary tree
    void insert(int value) {
        insert(root, value);
    }

    // Performs an inorder traversal of the tree
    void inorderTraversal(Node* current, std::vector<int>& result) const {
        inorderTraversalHelper(current, result);
    }

    // Performs a preorder traversal of the tree
    void preorderTraversal(Node* current, std::vector<int>& result) const {
        preorderTraversalHelper(current, result);
    }

    // Performs a postorder traversal of the tree
    void postorderTraversal(Node* current, std::vector<int>& result) const {
        postorderTraversalHelper(current, result);
    }

    // Returns the root node of the tree
    Node* getRoot() const {
        return root;
    }
};

#endif // BTREE_HPP