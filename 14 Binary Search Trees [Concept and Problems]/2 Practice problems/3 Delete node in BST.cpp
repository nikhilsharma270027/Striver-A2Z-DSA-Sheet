#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	TreeNode* deleteNode(TreeNode* root, int key) {
		if(root == NULL) {
			return NULL;
		}
		if(root->val == key) {
			return helper(root);
		}
		TreeNode* dummy = root;
		while(root != NULL) {
			if(root->val > key) { //8 > 5 true
				if(root->left != NULL && root->left->val == key ) { // checking if null && if next node is del_node
					root->left = helper(root->left);
					break;
				} else {
					root = root->left; // moving to nextnode
				}
			} else {
				if(root->right != NULL && root->right->val == key) {
					root->right = helper(root->right);
					break;
				} else {
					root = root->right;
				}
			}
		}
		return dummy;
	}
	TreeNode* helper(TreeNode* root) {
		if(root->left == NULL) { // suppos the left part doesnt not exist tuen it to right side only
			return root->right;
		}
		else if (root->right == NULL) {
			return  root->left;
		}
		// if above condition are both false
		TreeNode* rightChild = root->right;
		TreeNode* lastRight = findLastRight(root->left);
		lastRight->right = rightChild;
		return root->left;

	}
	TreeNode* findLastRight(TreeNode* root) {
		if(root->right == NULL) {
			return root;
		}
		return findLastRight(root->right);
	}
};

// Function to perform an in-order traversal
// of a binary tree and print its nodes
void printInOrder(TreeNode* root) {
	// Check if the current node
	// is null (base case for recursion)
	if (root == NULL) {
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
	Solution solution;

	// Creating a sample tree for testing purposes
	TreeNode* root = new TreeNode(5);
	root->left = new TreeNode(3);
	root->right = new TreeNode(7);
	root->left->left = new TreeNode(2);
	root->left->right = new TreeNode(4);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(8);

	// Printing the original tree
	cout << "Original Tree (Inorder Traversal): ";
	printInOrder(root);
	cout << endl;

	// Testing the deleteNode function
	int keyToDelete = 3;
	TreeNode* updatedTree = solution.deleteNode(root, keyToDelete);
	// Printing the tree after deletion
	cout << "Tree After Deletion (Inorder Traversal): ";
	printInOrder(updatedTree);
	cout << endl;

	return 0;
}

    // Original Tree (Inorder Traversal): 2 3 4 5 6 7 8 
    // Tree After Deletion (Inorder Traversal): 2 4 5 6 7 8 
    