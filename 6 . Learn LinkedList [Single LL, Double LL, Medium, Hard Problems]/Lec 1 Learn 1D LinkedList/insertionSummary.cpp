#include<bits/stdc++.h>
using namespace std;

// Deletion of Head in LinkedList
class Node {
public:
    int data;         // Data of the node
    Node* next;       // Pointer to the next node in the list
    // Constructor for a node with both data and next node provided
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }
    // Constructor for a node with only data provided, next initialized to nullptr
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

// Convert LL to array
Node* convertArr2LL(vector<int> arr){// returning pointer to the head{
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1;i<arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next=temp;
        // mover=mover->next;
        mover=temp;
        // cout << temp->next << endl;;
    }
    return head;
}

// Function to print the linked list starting from the given head
void print(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main(){
    vector<int> arr = {12, 5, 8, 7};
    Node* head = convertArr2LL(arr);
    cout << "The Linked List : ";
    print(head);