#include <bits/stdc++.h>
using namespace std;

// Binary tree node structure
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Function to create a binary tree recursively
Node* createTree() {
    int val;
    cout << "Enter node value (-1 for NULL): ";
    cin >> val;

    if (val == -1) return nullptr;

    Node* newNode = new Node(val);

    cout << "Enter left child of " << val << ":\n";
    newNode->left = createTree();

    cout << "Enter right child of " << val << ":\n";
    newNode->right = createTree();

    return newNode;
}

int main() {
    Node* root = nullptr;

    cout << "Create the Binary Tree:\n";
    root = createTree();

    cout << "\nBinary Tree created successfully.\n";

    return 0;
}
