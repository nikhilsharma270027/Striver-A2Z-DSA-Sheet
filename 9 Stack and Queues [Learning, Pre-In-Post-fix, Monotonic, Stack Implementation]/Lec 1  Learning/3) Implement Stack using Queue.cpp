Approach:

Take a single queue.
push(x): Push the element in the queue.
Use a for loop of size()-1, remove element from queue and again push back to the queue, hence the most recent element becomes the most former element and vice versa.
pop(): remove the element from the queue.
top(): show the element at the top of the queue.
size(): size of the current queue.
Repeat step3 at every insertion of the element.

#include<bits/stdc++.h>

using namespace std;

class Stack {
    std::queue<int> q;  //(3, 2, 4, 1)
public:
    void Push(int x) {
        int s = q.size();
        q.push(x);                  //pushed 3, now 3 is in front, next 2, 4, 1
        for (int i = 0; i < s; i++) {
            q.push(q.front());      //front is 3, so pushed at back
            q.pop();                //popped 3
        }
    }
    int Pop() {
        int n = q.front();
        q.pop();
        return n;
    }
    int Top() {
        return q.front();
    }
    int Size() {
        return q.size();
    }

    // Display function to print elements in the queue (acting as stack)
    void Display() {
        // Temporary queue to hold the elements
        std::queue<int> tempQueue = q;

        cout << "Stack elements: ";
        while (!tempQueue.empty()) {
            // Print front element of the queue
            cout << tempQueue.front() << " ";

            // Remove the front element from the temp queue
            tempQueue.pop();
        }
        cout << endl;
    }
};

int main() {
    Stack s;
    s.Push(3);
    s.Push(2);
    s.Push(4);
    s.Push(1);

    cout << "Top of the stack: " << s.Top() << endl;
    cout << "Size of the stack before removing element: " << s.Size() << endl;
    cout << "The deleted element is: " << s.Pop() << endl;
    cout << "Top of the stack after removing element: " << s.Top() << endl;
    cout << "Size of the stack after removing element: " << s.Size() << endl;

    // Display the stack
    s.Display();

    return 0;
}

Output:
Top of the stack: 1
Size of the stack before removing element: 4
The deleted element is: 1
Top of the stack after removing element: 4
Size of the stack after removing element: 3
Stack elements: 4 2 3 

Time Complexity: O(N)

Space Complexity: O(N)