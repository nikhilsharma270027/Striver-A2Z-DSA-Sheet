#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};  

class Solution {
public:
        int diameterOfBinaryTree(TreeNode* root) {
            int diameter = 0;
            height(root, diameter);
            return diameter;
        }
        int height(TreeNode* root, int& diameter) {
            if(root == NULL) {
                return 0;
            }
            int lh = height(root->left, diameter);
            int rh = height(root->right, diameter);
            diameter = max(diameter, lh + rh);
            return 1 + max(lh, rh);
        }
    
};

int main() {
    // Creating a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->right = new TreeNode(6);
    root->left->right->right->right = new TreeNode(7);

    // Creating an instance of the Solution class
    Solution solution;

    // Calculate the diameter of the binary tree
    int diameter = solution.diameterOfBinaryTree(root);

    cout << "The diameter of the binary tree is: " << diameter << endl;

    return 0;
}
                                
// TC: O(N)
// SC: O(1)                   