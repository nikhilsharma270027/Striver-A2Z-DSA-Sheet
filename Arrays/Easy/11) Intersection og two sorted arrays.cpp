// Brute Force Approach
#include <bits/stdc++.h>
using namespace std;

vector<int> findArrayIntersection(vector<int> &A, vector<int> &B, int m) {
    vector<int> ans;
    vector<int> vis(m, 0);  // Using vector instead of array for visibility
    
    int n = A.size();  // Added missing definition of n
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (A[i] == B[j] && vis[j] == 0)  // Corrected the assignment operator to equality operator
            {
                ans.push_back(A[i]);
                vis[j] = 1;
                break;
            }
            if (B[j] > A[i])
                break;
        }
    }
    return ans;
}

int main() {
    vector<int> A = {1, 2, 2, 3, 3, 4, 5, 6};  // Example input
    vector<int> B = {2, 3, 3, 5, 6, 6, 7};    // Example input
    int m = B.size();

    vector<int> result = findArrayIntersection(A, B, m);
    // Print the result
    cout << "Intersection: ";
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}

// Output:
// Intersection: 2 3 3 5 6 

// TC -> O( n1 x n2 )
// SC -> O( n2 )

// Optimal Approach
// two pointer method
#include <bits/stdc++.h>
using namespace std;

vector<int> findArrayIntersection(vector<int> &A, vector<int> &B, int m) {
    int i = 0;
    int j = 0;
    vector<int> ans;
    while(i<A.size() && j<B.size()) {
        if(A[i] < B[j]) {
            i++;
        }
        else if(B[j] < A[i]) {
            j++;
        }
        else {
            ans.push_back(A[i]);
            i++;
            j++;
        }
    }
    return ans;
}

int main() {
    vector<int> A = {1, 2, 2, 3, 3, 4, 5, 6};  // Example input
    vector<int> B = {2, 3, 3, 5, 6, 6, 7};    // Example input
    int m = B.size();

    vector<int> result = findArrayIntersection(A, B, m);
    // Print the result
    cout << "Intersection: ";
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}

// Output:
// Intersection: 2 3 3 5 6

// TC -> O( n1 + n2 )
// SC -> O( 1 )