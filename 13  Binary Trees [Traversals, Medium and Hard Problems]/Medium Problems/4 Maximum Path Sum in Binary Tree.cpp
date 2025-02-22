#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};  

class Solution {
    public:
        int maxPathSum(TreeNode* root) {
            int maxi = INT_MIN;
            maxpathdown(root,maxi);
            return maxi;
        }
        int maxpathdown(TreeNode* root, int &maxi){
            if(root == NULL) return 0;
    
            int left = max(0, maxpathdown(root->left, maxi));
            int right = max(0, maxpathdown(root->right, maxi));
    
            maxi = max(maxi, left + right + root->val);
            return max(left,right) + root->val;
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
    int diameter = solution.maxPathSum(root);

    cout << "The diameter of the binary tree is: " << diameter << endl;

    return 0;
}
                                
// TC: O(N)
// SC: O(1)                   