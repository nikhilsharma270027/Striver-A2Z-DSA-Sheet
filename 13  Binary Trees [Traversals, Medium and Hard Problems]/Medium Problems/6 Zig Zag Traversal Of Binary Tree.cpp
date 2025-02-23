#include <bits/stdc++.h>
using namespace std;
struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int val) : val(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<vector<int>> ZigZagLevelOrder(Node* root) {
        vector<vector<int>> result;
        if( root ==  NULL) {
            return result;
        }
        
        std::queue<Node*> nodesQueue;
        nodesQueue.push(root);
        bool leftToRight = true;
        
        while(!nodesQueue.empty()) {
            int size = nodesQueue.size();
            vector<int> row(size);
            for(int  i =0;i< size; i++) {
                Node* node = nodesQueue.front(); // take front ele
                nodesQueue.pop();                // pop it out then check its left adn right
                
                // find position to fill node's value
                int index = (leftToRight) ? i : (size- 1 - i);  
                cout << index << endl;
                
                row[index] = node->val; // [0]true : [1, 0]false 
                if(node->left) {
                    nodesQueue.push(node->left);
                }
                if(node->right){
                    nodesQueue.push(node->right);
                }
            }
            // after the level
            leftToRight = !leftToRight;
            result.push_back(row);
            
            }
    
        return result;
    }
    
};

void printResult(const vector<vector<int>>& result) {
    for(const auto& row : result) {
        cout << "[";
        for(int val : row){
            cout << val << " ";
        }
        cout << "]";
        cout << endl;
    }
}


int main() {
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution solution;

    // Get the zigzag level order traversal
    vector<vector<int>> result = solution.ZigZagLevelOrder(root);

    // Print the result
    printResult(result);

    return 0;
}