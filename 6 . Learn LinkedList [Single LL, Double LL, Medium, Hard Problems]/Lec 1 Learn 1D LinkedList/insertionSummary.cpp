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

// Insert at the head/start
Node* insertHead(Node* head, int val){
    Node* temp = new Node(val, head);
    return temp;
}

//Insert at the tail/end
Node* insertTail(Node* head, int val){
    if(head == NULL) {
        return new Node(val);
    }
    Node* temp = head;
    while(temp->next != NULL) { 
        temp = temp->next; // we stop at the last element
    }
    Node* newNode = new Node(val);
    temp->next = newNode;
    return head;
}

// insert in Kth position
Node* insertKPosition(Node* head, int ele, int k ){
    if(head == NULL){ // empty list
        if(k == 1){
            return new Node(ele);
        } else {
            return head;
        }
    }
    if(k == 1){
        Node* newHead = new Node(ele, head); // pointing to new head cuz head is change
        return newHead;
    }
    int cnt = 0;
    Node* temp = head;
    while(temp != NULL) {
        cnt++;
        if(cnt == (k-1)) {
            Node* x = new Node(ele, temp->next); // 
            // ele->next = temp->next; same as x->next = temp->next;
            temp->next = x;
            break;
        }
        temp = temp->next;
    }
    return head;
}

// insert before the value
Node* insertBeforeValue(Node* head, int ele, int val ){
    if(head == NULL){ // empty list || 
        cout << "Not found" << endl;
        return NULL;
    }
    if(head->data == val){
        Node* newHead = new Node(ele, head); // pointing to new head cuz head is change
        return newHead;
    }
    
    Node* temp = head;
    bool found = false; // for message
    while(temp->next != NULL) {
        if(temp->next->data == val) {
            Node* x = new Node(ele, temp->next); // 
            // ele->next = temp->next; same as x->next = temp->next;
            temp->next = x;
            found = 1;
            break;
        }
        temp = temp->next;
    }
    if(found == false){
        cout << "Not found" << endl;
    }
    return head;
}

int main(){
    vector<int> arr = {12, 5, 8, 7};
    Node* head = convertArr2LL(arr);
    Node* newHead = convertArr2LL(arr);
    Node* newHead2 = convertArr2LL(arr);
    Node* newHead3 = convertArr2LL(arr);
    cout << "The Linked List : ";
    print(head);
    
    head = insertHead(head, 100); // using the insertHead function
    // head = new Node( 200, head); // directly insert node & val using construction in class
    cout << endl << "Insert start : ";
    print(head);
    
    newHead = insertTail(newHead, 100);
    cout << endl << "insert End :";
    print(newHead);
    
    newHead2 = insertKPosition(newHead2, 100, 3);
    cout << endl << "insert kth position : ";
    print(newHead2);
    
    newHead3 = insertBeforeValue(newHead3, 100, 7);
    cout << endl << "insert before value : ";
    print(newHead3);
}