#ifndef NODE_HPP
#define NODE_HPP

// Represents a single node in the binary tree
class Node {
private:
    int data;       // Value of the node
    Node* left;     // Pointer to the left child
    Node* right;    // Pointer to the right child

public:
    // Constructor to initialize the node with a value
    Node(int value) : data(value), left(nullptr), right(nullptr) {}

    // Getter for the node's value
    int getData() const {
        return data;
    }

    // Setter for the node's value
    void setData(int value) {
        data = value;
    }

    // Getter for the left child pointer
    Node* getLeft() const {
        return left;
    }

    // Setter for the left child pointer
    void setLeft(Node* node) {
        left = node;
    }

    // Getter for the right child pointer
    Node* getRight() const {
        return right;
    }

    // Setter for the right child pointer
    void setRight(Node* node) {
        right = node;
    }
};

#endif // NODE_HPP