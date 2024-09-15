#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;   
    
    Node* next; 
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

// Function to reverse the // linked list using a stack
Node* reverseLinkedList(Node* head) {
    // Create a temporary pointer
    // to traverse the linked list
    Node* temp = head;   
    // Create a stack to temporarily
    // store the data values
    stack<int> st;     
    // Step 1: Push the values of the
    // linked list onto the stack
    while (temp != nullptr) {
        // Push the current node's
        // data onto the stack
        st.push(temp->data); 
        
        // Move to the next node
        // in the linked list
        temp = temp->next;    
    }
    // Reset the temporary pointer to
    // the head of the linked list
    temp = head; 
    // Step 2: Pop values from the stack
    // and update the linked list
    while (temp != nullptr) {
        // Set the current node's data to
        // the value at the top of the stack
        temp->data = st.top();     
        // Pop the top element from the stack
        st.pop();                 
        // Move to the next node
        // in the linked list
        temp = temp->next;     
    }
    // Return the new head of
    // the reversed linked list
    return head;  
}

// Function to print the linked list
void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Create a linked list with
    // values 1, 3, 2, and 4
    Node* head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(2);
    head->next->next->next = new Node(4);

    // Print the original linked list
    cout << "Original Linked List: ";
    printLinkedList(head);

    // Reverse the linked list
    head = reverseLinkedList(head);

    // Print the reversed linked list
    cout << "Reversed Linked List: ";
    printLinkedList(head);

    return 0;
}


// Optimal Approach

// Function to reverse a linked list
// using the 3-pointer approach
Node* reverseLinkedList(Node *head)
{
   // Initialize'temp' at
   // head of linked list
   Node* temp = head;  
   // Initialize pointer 'prev' to NULL,
   // representing the previous node
   Node* prev = NULL;  
   // Traverse the list, continue till
   // 'temp' reaches the end (NULL)
   while(temp != NULL){  
       // Store the next node in
       // 'front' to preserve the reference
       Node* front = temp->next;  
       // Reverse the direction of the
       // current node's 'next' pointer
       // to point to 'prev'
       temp->next = prev;    
        // Move 'prev' to the current
        // node for the next iteration
       prev = temp;    
        // Move 'temp' to the 'front' node
        // advancing the traversal
       temp = front; 
   }
   // Return the new head of
   // the reversed linked list
   return prev;  
}
