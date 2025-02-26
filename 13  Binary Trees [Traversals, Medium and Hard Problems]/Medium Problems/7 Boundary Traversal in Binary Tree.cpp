#include <bits/stdc++.h>
using namespace std;
struct Node {
    int val;       
    Node* left;   
    Node* right;   
    Node(int val) : val(val), left(nullptr), right(nullptr) {} // Constructor
};

class Solution {
    // Helper function to check if a node is a leaf
    bool isLeaf(Node* root) {
        // A node is a leaf if it has no left or right child
        if(!root->left && !root->right) return true;
        else return false;
    }

    // Function to add the left boundary of the tree (excluding leaves) to the result
    void addLeftBoundary(Node* root, vector<int> &res) {
        Node* current = root->left; // Start with the left child of the root
        while(current) {
            // If the current node is not a leaf, add its value to the result
            if(!isLeaf(current)) res.push_back(current->val);
            // Move to the left child if it exists, otherwise move to the right child
            if(current->left) 
                current = current->left;
            else 
                current = current->right;
        }
    }

    // Function to add the right boundary of the tree (excluding leaves) to the result
    void addRightBoundary(Node* root, vector<int> &res) {
        Node* current = root->right; // Start with the right child of the root
        vector<int> temp; // Temporary vector to store the right boundary in reverse order
        while(current) {
            // If the current node is not a leaf, add its value to the temporary vector
            if(!isLeaf(current)) temp.push_back(current->val);
            // Move to the right child if it exists, otherwise move to the left child
            if(current->right) 
                current = current->right;
            else
                current = current->left;
        }
        // Add the right boundary nodes in reverse order to the result
        for(int i = temp.size()-1; i >= 0; i--){
            res.push_back(temp[i]);
        } 
    }

    // Function to add all leaf nodes of the tree to the result
    void addLeaves(Node* root, vector<int> & res) {
        // If the current node is a leaf, add its value to the result
        if(isLeaf(root)) {
            res.push_back(root->val);
            return;
        }
        // Recursively add leaves from the left subtree
        if(root->left) addLeaves(root->left, res);
        // Recursively add leaves from the right subtree
        if(root->right) addLeaves(root->right, res);
    }

public:
    // Main function to perform the boundary traversal of the binary tree
    vector<int> printBoundary(Node* root) {
        vector<int> res; // Result vector to store the boundary traversal
        if(!root){ 
            return res; // If the tree is empty, return an empty result
        }
        // If the root is not a leaf, add its value to the result
        if(!isLeaf(root)) res.push_back(root->val);
        // Add the left boundary (excluding leaves)
        addLeftBoundary(root, res);
        // Add all leaf nodes
        addLeaves(root, res);
        // Add the right boundary (excluding leaves)
        addRightBoundary(root, res);
        return res; // Return the final result
    }
};

// Helper function to print the result
void printResult(const vector<int>& result) {
    for (int val : result) {
        cout << val << " "; // Print each value in the result vector
    }
    cout << endl; // Print a newline at the end
}

int main() {
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution solution;

    // Get the boundary traversal of the tree
    vector<int> result = solution.printBoundary(root);

    // Print the result
    cout << "Boundary Traversal: ";
    printResult(result);

    return 0;
}