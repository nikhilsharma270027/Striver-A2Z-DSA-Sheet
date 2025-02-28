/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    public:
            void inorder(TreeNode* root, vector<int>& arr) {
                if(root == NULL) {
                    return;
                }
                if(root->left){
    
                inorder(root->left, arr);
                }
                arr.push_back(root->val);
                if(root->right){
    
                inorder(root->right, arr);
                }
                // return ;
            }
            bool isValidBST(TreeNode* root)  {
                std::vector<int> arr ;
                inorder(root, arr);
                for(int i = 1;i<arr.size();i++) {
                    if(arr[i] <= arr[i-1]){
                        return false;
                    }
                }
                return true;
                
            }
    };