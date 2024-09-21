// Brute Force Approach
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

Node *deleteMiddle(Node *head) {
    Node* temp = head;
    int n = 0;
    
    // Loop to count the number of
    // nodes in the linked list
    while(temp!=NULL){
        n++;
        temp = temp->next;
    }
    
    // Calculate the index of the middle node
    int res = n/2;
    
    // Reset the temporary node to
    // the beginning of the linked list
    temp = head;
    
    // Loop to find the
    // middle node to delete
    while(temp!=NULL){
        
        res --;
        
        // If the middle node is found
        if(res==0){
            
            // Create a pointer
            // to the middle node
            Node* middle = temp->next;
            
            // Adjust pointers to
            // skip the middle node
            temp->next = temp->next->next;
            
            // Free the memory allocated
            // to the middle node
            free(middle);
            
            // Exit the loop after
            // deleting the middle node
            break;
        }
        // Move to the next node
        // in the linked list
        temp = temp->next;
    }
    // Return the head of the
    // modified linked list
    return head;
}


void printLL(Node* head){
    
    Node *temp = head;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
 }

int main() {
    // Creating a sample linked list: 
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    
    // Display the orignal linked list
    cout << "Orginal Linked List: ";
    printLL(head);

    // Deleting the middle node
    head = deleteMiddle(head);

    // Displaying the updated linked list
    cout << "Orginal Linked List: ";
    printLL(head);

    return 0;
}
// Complexity Analysis
// Time Complexity: O(N + N/2) The loop traverses the entire linked list once to count the total number of nodes then the loop iterates halfway through the linked list to reach the middle node. Hence, the time complexity is O(N + N/2) ~ O(N).

// Space Complexity : O(1) The algorithm uses a constant amount of extra space regardless of the size of the input (linked list). It doesn't use any additional data structures in proportion to the input size. Thus, the space complexity is O(1) (constant space). 


//Optimal Approach
Node *deleteMiddle(Node *head) {
    // If the list is empty or has only one node,
    // return NULL as there is no middle node to delete
    if (head == NULL || head->next == NULL) {
        return NULL;
    }

    // Initialize slow and fast pointers
    Node* slow = head;
    Node* fast = head;
    fast = head->next->next;

    // Move 'fast' pointer twice as fast as 'slow'
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Delete the middle node by skipping it
    slow->next = slow->next->next;
    return head;
}
// Complexity Analysis
// Time Complexity: O(N/2) The algorithm traverses the linked list using the Tortoise and Hare approach. The code increments both 'slow' and 'fast' pointers at different rates, effectively covering about half the list before reaching the midpoint, hence the time complexity of the algorithm is O(N/2) ~ O(N).

// Space Complexity: O(1) The algorithm uses a constant amount of extra space regardless of the size of the input (linked list). It doesn't use any additional data structures in proportion to the input size. Thus, the space complexity is O(1) (constant space). 