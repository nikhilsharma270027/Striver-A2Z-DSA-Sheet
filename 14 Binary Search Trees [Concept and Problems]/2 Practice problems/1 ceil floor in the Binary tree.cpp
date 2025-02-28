#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    public :
        int findCeil(TreeNode* root, int key) {
            int ceil = -1;
            while(root) {
                if(root->val == key) { 
                    ceil = root->val;
                    return ceil;
                }
                
                if(key > root->val) { 8 > 10 false
                    root = root->right;
                } else {
                    ceil = root->val; -1 -> 10
                    root = root->left;
                }
            }
            return ceil;
        }
};

// Function to perform an in-order traversal
// of a binary tree and print its nodes
void printInOrder(TreeNode* root) {
    // Check if the current node
    // is null (base case for recursion)
    if (root == nullptr) {
        // If null, return and
        // terminate the function
        return;
    }

    // Recursively call printInOrder
    // for the left subtree
    printInOrder(root->left);

    // Print the value of the current node
    cout << root->val << " ";

    // Recursively call printInOrder
    // for the right subtree
    printInOrder(root->right);
}

int main() {
    // Creating a BST
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(13);
    root->left->left = new TreeNode(3);
    root->left->left->left = new TreeNode(2);
    root->left->left->right = new TreeNode(4);
    root->left->right = new TreeNode(6);
    root->left->right->right = new TreeNode(9);
    root->right->left = new TreeNode(11);
    root->right->right = new TreeNode(14);
    
    cout << "Binary Search Tree: "<< endl;
    printInOrder(root);
    cout << endl;

    Solution solution;
    
    // Searching for a value in the BST
    int target = 8;
    int ciel = solution.findCeil(root, target);
    
    if(ciel != -1){
        cout << "Ceiling of " << target << " is: " << ciel << endl;
    }
    else{
        cout << "No ceiling found!";
    }
    
    return 0;
}

// Binary Search Tree: 
// 2 3 4 5 6 9 10 11 13 14 
// Ceiling of 8 is: 9

 // Floor
 int findFloor(TreeNode* root, int key) {
    int floor = -1;
    while(root) {
        if(root->val == key) { 
            floor = root->val;
            return floor;
        }
        
        if(key > root->val) { //8 > 10 false
            root = root->right;
            floor = root->val; 
        } else {
            root = root->left;
        }
    }
    return ceil;
}