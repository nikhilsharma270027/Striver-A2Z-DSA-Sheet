#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val; 
    TreeNode* left; 
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
    public:
    vector<int> postOrder(TreeNode* root) {
        // Vector to store
        // postorder traversal
        vector<int> postorder;
    
        // If the tree is empty,
        // return an empty traversal
        if(root == NULL){
            return postorder;
        }
    
        // Two stacks for
        // iterative traversal
        stack<TreeNode*> st1, st2;
    
        // Push the root node
        // onto the first stack
        st1.push(root);
    
        // Iterative traversal to populate
        // st2 with nodes in postorder
        while(!st1.empty()){
            // Get the top node from st1
            root = st1.top();
            st1.pop();
    
            // Push the node onto st2
            st2.push(root);
    
            // Push left child onto st1 if exists
            if(root->left != NULL){
                st1.push(root->left);
            }
    
            // Push right child onto st1 if exists
            if(root->right != NULL){
                st1.push(root->right);
            }
        }
    
        // Populate the postorder traversal 
        // vector by popping st2
        while(!st2.empty()){
            postorder.push_back(st2.top()->val);
            st2.pop();
        }
    
        // Return the
        // postorder traversal
        return postorder;
    }
};

int main() {
    // Creating a binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Initializing the Solution class
    Solution sol;

    // Getting the preorder traversal
    vector<int> result = sol.postOrder(root);

    // Displaying the preorder traversal result
    cout << "postorder Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

// Output Postorder traversal: 4 5 2 3 1