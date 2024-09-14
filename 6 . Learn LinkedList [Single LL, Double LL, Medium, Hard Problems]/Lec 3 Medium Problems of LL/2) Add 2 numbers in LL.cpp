#include <iostream>
using namespace std;

// Definition for a singly-linked list node
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

Node* addTwoNumbers(Node *num1, Node *num2){
    Node*  dummyhead = new Node(-1);
    Node* curr = dummyhead;
    Node* temp1 = num1;
    Node* temp2 = num2;
    int carry = 0;
    while(temp1 != NULL || temp2 != NULL){
        int sum = carry;
        if(temp1) sum = sum + temp1->data;
        if(temp2) sum = sum + temp2->data;
        cout << sum << " ";
        Node* newNode = new Node(sum % 10);
        carry = sum / 10;
        
        curr->next = newNode;
        curr = curr -> next;
        
        if(temp1) temp1 = temp1->next;
        if(temp2) temp2 = temp2->next;
    }
    if(carry) {
        Node* newNode = new Node(carry);
        curr->next = newNode;
    }
    return dummyhead->next;
}

// Function to print a linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Function to create a linked list from an array
Node* createList(int arr[], int size) {
    Node* head = new Node(arr[0]);
    Node* temp = head;
    for (int i = 1; i < size; i++) {
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }
    return head;
}


int main() {
    // Example of lists with different sizes
    int arr1[] = {2, 4, 3};  // represents 7432 (reversed in linked list)
    int arr2[] = {5, 6, 4, 5, 5};     // represents 465 (reversed in linked list)

    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    
    Node* num1 = createList(arr1, size1);
    Node* num2 = createList(arr2, size2);
    
    cout << "First number: ";
    printList(num1);
    cout << "Second number: ";
    printList(num2);
    
    Node* result = addTwoNumbers(num1, num2);
    
    cout << "Sum: ";
    printList(result);
    
    return 0;
}


// First number: 2 4 3 
// Second number: 5 6 4 5 5 
// 7 10 8 5 5 
// Sum: 7 0 8 5 5 
