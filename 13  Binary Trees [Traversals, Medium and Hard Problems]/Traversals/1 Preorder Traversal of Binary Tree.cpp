#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
     // Constructor to initialize
    // the node with a value
    // Node(int val) : data(val), left(nullptr), right(nullptr) {}
    Node(int val) {
        data = val;       // Assign value to data
        left = nullptr;   // Initialize left child as nullptr
        right = nullptr;  // Initialize right child as nullptr
    }
}
void preorder(Node* root, vector<int> &arr) {
    if(root == nulptr){
        return;
    }
    arr.push_back(root->data);
    preorder(root->left, arr);
    preorder(root->right, arr);
}
vector<int> preOrder(Node* root){
    // Create an empty vector to
    // store preorder traversal values
    vector<int> arr;
    // Call the preorder traversal function
    preorder(root, arr);
    // Return the resulting vector
    // containing preorder traversal values
    return arr;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    vector<int> result = preOrder(root);

    // Displaying the preorder traversal result
    cout << "Preorder Traversal: ";
    // Output each value in the
    // preorder traversal result
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}

    // Preorder Traversal: 1 2 4 5 3 