#include <bits/stdc++.h>
using namespace std;

void leftRotate(int arr[], int n, int d) {
    d = d % n;   // finding the distance/ places
    if (n == 0)  // valiating if n is equal to 0
        return;
    if (d > n)   // valiating if places 
        return;

    int temp[n];
    for (int i = 0; i<d; i++) {
        temp[i] = arr[i];
    }
    for (int i = d; i<n; i++) {
        arr[i - d] = arr[i];
    }
    for (int i = n - d; i<n; i++) {
        arr[i] = temp[i - (n - d)];
    }
}

int main()
{
    int n = 7;
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int d = 3;
    leftRotate(arr, n, d);
    cout << "After Rotating the elements to left " << endl;
    for (int i = 0; i<n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}

// Output:
// After Rotating the elements to left 
// 4 5 6 7 1 2 3 

// Optimal Approach
//using reverse function
#include <bits/stdc++.h>
using namespace std;

void leftRotate(int arr[], int n, int d){
    reverse(arr,arr+d);
    reverse(arr+d,arr+n);
    reverse(arr,arr+n);
}

int main()
{
    int n = 7;
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int d = 3;
    leftRotate(arr,n, d);
    cout << "After Rotating the elements to left " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}