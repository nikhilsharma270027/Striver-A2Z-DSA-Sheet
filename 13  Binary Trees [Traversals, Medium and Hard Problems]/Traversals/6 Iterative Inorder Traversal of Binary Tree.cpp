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
        vector<int> inorder(TreeNode* root) {
            stack<TreeNode*> st;
            TreeNode* node = root;
            vector<int> inorder;
            while(true) {
                if(node != NULL) {
                    st.push(node);
                    node = node -> left;
                }
                else {
                    if(st.empty() == true) break;
                    node = st.top();
                    st.pop();
                    inorder.push_back(node->val);
                    node = node->right;
                }
            }
            return inorder;
    }
};

int main() {
    // Creating a binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(5);
    root->left->right->right = new TreeNode(6);

    // Initializing the Solution class
    Solution sol;

    // Getting the preorder traversal
    vector<int> result = sol.inorder(root);

    // Displaying the preorder traversal result
    cout << "Preorder Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}