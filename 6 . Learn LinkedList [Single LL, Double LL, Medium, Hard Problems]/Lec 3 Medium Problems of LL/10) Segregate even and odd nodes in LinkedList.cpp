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

// Brute forece Approach
// Node* oddEven(struct Node* head){
//     vector<int> arr;
//     Node* temp = head;
//     while(temp != NULL && temp->next != NULL){
//         arr.push_back(temp->data);
//         temp = temp->next->next;
//     }
//     if(temp) arr.push_back(temp->data);
//     temp = head->next;
//     while(temp != NULL && temp->next != NULL){
//         arr.push_back(temp->data);
//         temp = temp->next->next;
//     }
//     if(temp) arr.push_back(temp->data);

//     temp = head;
//     int  i =0;
//     while(temp != NULL){
//         temp->data = arr[i];
//         i++;
//         temp = temp->next;
//     }
//     return head;
// }

//Optimal Approach
Node* oddEvenOptimal(struct Node* head) {
	Node* odd = head;
	Node* even = head->next;
	Node* evenhead = head->next;
	while(even != NULL && even->next != NULL) {
			odd->next = odd->next->next;
		even->next = even->next->next;

		odd = odd->next;
		even = even->next;
	}
	odd->next = evenhead;
	return head;
}

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
	Node* head = new Node(1);
	head->next = new Node(5);
	head->next->next = new Node(2);
	head->next->next->next = new Node(5);
	head->next->next->next->next = new Node(1);

	// Print the original linked list
	cout << "Original Linked List: ";
	printLinkedList(head);

	// Node* newHead = oddEven(head);
	Node* newHead = oddEvenOptimal(head);
	printLinkedList(newHead);

	return 0;
}