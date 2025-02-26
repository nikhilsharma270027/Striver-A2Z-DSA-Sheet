#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    private:
        void inorder(TreeNode* node, vector<int>& arr) {
            if(!node){
                return ;
            }
            
            inorder(node->left, arr);
            arr.push_back(node->val);
            inorder(node->right, arr);
            return;
        }
    public: 
        pair<int, int> findKth(TreeNode* node, int k) {
            vector<int> arr;
            inorder(node, arr);
            
            //largest
            int kLargest = arr[arr.size() - k];
            //Smallest
            int kSmallest = arr[k-1];
            
            
            return make_pair(kSmallest, kLargest);
        }
};

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

    // Find the Kth smallest and largest elements
    int k = 3; 
    cout << "k: "<< k <<endl;
    pair<int, int> kthElements = solution.findKth(root, k);

    cout << "Kth smallest element: " << kthElements.first << endl;
    cout << "Kth largest element: " << kthElements.second << endl;

    return 0;
}
    // Binary Search Tree: 
    // 2 3 4 5 6 9 10 11 13 14 
    // k: 3
    // Kth smallest element: 4
    // Kth largest element: 11
    
// Optimal approach
class Solution {
    public:
    void reverseInorder(TreeNode* node, int& counter, int& k, int& largest) {
         if(!node || counter >= k) return;
        
        reverseInorder(node->right, counter, k, largest);
        
        counter++;
        
        if(counter == k){
            largest = node->val;
            return;
        }
        
        reverseInorder(node->left, counter, k, largest);
    }
    public:
    void inorder(TreeNode* node, int& counter, int& k, int& smallest){
        if(!node || counter >= k) return;
        
        inorder(node->left, counter, k, smallest);
        
        counter++;
        
        if(counter == k){
            smallest = node->val;
            return;
        }
        
        inorder(node->right, counter, k, smallest);
    }
    public:
        pair<int, int> findKth(TreeNode* node, int k) {
            int smallest = INT_MIN, largest = INT_MIN;
            int counter = 0;
            
            inorder(node, counter, k, smallest);
            
            counter = 0;
            
            reverseInorder(node, counter, k, largest);
            
            return make_pair(smallest, largest);
    }
};