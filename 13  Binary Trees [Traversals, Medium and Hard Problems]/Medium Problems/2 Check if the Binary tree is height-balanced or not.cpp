#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
    public: 
        bool isBalanced(Node* root) {
            if(root == NULL) {
                return true;
            }
            
            int leftHeight = getHeight(root->left);
            int rightHeight = getHeight(root->right);
            
            if(abs(leftHeight - rightHeight) <= 1 && isBalanced(root->left) && isBalanced(root->right) ) {
                return true;
            } 
        }
        
        int getHeight(Node* root){
            if(root == NULL){
                return 0;
            }
            
            int leftHeight = getHeight(root->left);
            int rightHeight = getHeight(root->left);
            
            return max(leftHeight, rightHeight) + 1;
        }
};

// Main function
int main() {
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    root->left->right->right->right = new Node(7);

    // Creating an instance of the Solution class
    Solution solution;

    // Checking if the tree is balanced
    if (solution.isBalanced(root)) {
        cout << "The tree is balanced." << endl;
    } else {
        cout << "The tree is not balanced." << endl;
    }

    return 0;
}