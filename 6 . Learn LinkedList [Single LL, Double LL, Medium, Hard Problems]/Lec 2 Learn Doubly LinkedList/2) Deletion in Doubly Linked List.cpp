#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;       // Data stored in the node
    Node* next;     // Pointer to the next node in the list (forward direction)
    Node* back;     // Pointer to the previous node in the list (backward direction)

    // Constructor for a Node with both data, a reference to the next node, and a reference to the previous node
    Node(int data1, Node* next1, Node* back1) {
        data = data1;
        next = next1; // Similar to a singly linked list, but now with a 'back' pointer.
        back = back1; // Addition of 'back' pointer for the doubly linked list.
    }

    // Constructor for a Node with data, and no references to the next and previous nodes (end of the list)
    Node(int data1) {
        data = data1;
        next = nullptr; // Similar to a singly linked list.
        back = nullptr; // Addition of 'back' pointer initialization.
    }
};

Node* convertArr2DLL(vector<int> &arr){
    Node* head = new Node(arr[0], nullptr, nullptr);
    Node* prev = head;
    for(int i = 1;i<arr.size();i++){
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp; //prev = temp->next
    }
    return head;
}

void print(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
}

Node* deletionHead(Node* head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    Node* prev = head;           //3   ->   4  ->  5
    head = head->next;          //prev     head

    head->back = nullptr;
    prev->next = nullptr;

    delete prev;
    return head;
}

Node* deletionTail(Node* head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    Node* tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    Node* newTail = tail->back;
    newTail->next = nullptr;
    tail->back = nullptr;

    delete tail;
    return head;
}

int main(){
    vector<int> arr = {12, 5, 8, 7};
    Node* head = convertArr2DLL(arr);
    print(head);

    head = deletionHead(head);
    cout << endl << "Deletion of head DLL : " ;
    print(head);

    head = deletionTail(head);
    cout << endl << "Deletion of Tail DLL : " ;
    print(head);

    return 0;
}


// the Doubly linked List : 12 5 8 7 
// Deletion of head DLL : 5 8 7 
// Deletion of Tail DLL : 5 8 