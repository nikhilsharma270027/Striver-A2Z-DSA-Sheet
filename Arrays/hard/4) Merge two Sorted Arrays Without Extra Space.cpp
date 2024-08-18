// Brute Force Approach
#include <bits/stdc++.h>
using namespace std;

void merge(long long arr1[], long long arr2[], int n, int m) {

    //Declare a 3rd array and 2 pointers:
    long long arr3[n + m];
    int left = 0;
    int right = 0;

    int index = 0;

    //Insert the elements from the 2 arrays
    // into the 3rd array using left and right
    // pointers:

    while (left < n && right < m) {
        if (arr1[left] <= arr2[right]) {
            arr3[index] = arr1[left];
            left++, index++;
        }
        else {
            arr3[index] = arr2[right];
            right++, index++;
        }
    }

    // If right pointer reaches the end:
    while (left < n) {
        arr3[index++] = arr1[left++];
    }

    // If left pointer reaches the end:
    while (right < m) {
        arr3[index++] = arr2[right++];
    }

    // Fill back the elements from arr3[]
    // to arr1[] and arr2[]:
    for (int i = 0; i < n + m; i++) {
        if (i < n) arr1[i] = arr3[i];
        else arr2[i - n] = arr3[i];
    }
}

int main() {
    long long arr1[] = {1, 4, 8, 10};
    long long arr2[] = {2, 3, 9};
    int n = 4, m = 3;
    merge(arr1, arr2, n, m);
    cout << "The merged arrays are: " << "\n";
    cout << "arr1[] = ";
    for (int i = 0; i < n; i++) {
        cout << arr1[i] << " ";
    }
    cout << "\narr2[] = ";
    for (int i = 0; i < m; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    return 0;
}

// Output: The merged arrays are: arr1[] = 1 2 3 4 
//                                arr2[] = 8 9 10 

// Complexity Analysis
// Time Complexity: O(n+m) + O(n+m), where n and m are the sizes of the given arrays.
// Reason: O(n+m) is for copying the elements from arr1[] and arr2[] to arr3[]. And another O(n+m) is for filling back the two given arrays from arr3[].

// Space Complexity: O(n+m) as we use an extra array of size n+m.


// Optimal Approach 1
#include <bits/stdc++.h>
using namespace std;

void merge(long long arr1[], long long arr2[], int n, int m) {
    //Declare 2 pointers:
    int left = n - 1;
    int right = 0;

    //Swap the elements until arr1[left] is
    // smaller than arr2[right]:
    while (left >= 0 && right < m) {
        if (arr1[left] > arr2[right]) {
            swap(arr1[left], arr2[right]);
            left--, right++;
        }
        else {
            break;
        }
    }
    // Sort arr1[] and arr2[] individually:
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
}

int main() {
    long long arr1[] = {1, 4, 8, 10};
    long long arr2[] = {2, 3, 9};
    int n = 4, m = 3;
    merge(arr1, arr2, n, m);
    cout << "The merged arrays are: " << "\n";
    cout << "arr1[] = ";
    for (int i = 0; i < n; i++) {
        cout << arr1[i] << " ";
    }
    cout << "\narr2[] = ";
    for (int i = 0; i < m; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    return 0;
}

// Output: The merged arrays are: arr1[] = 1 2 3 4 
                             //   arr2[] = 8 9 10 

// Complexity Analysis
// Time Complexity: O(min(n, m)) + O(n*logn) + O(m*logm), where n and m are the sizes of the given arrays.
// Reason: O(min(n, m)) is for swapping the array elements. And O(n*logn) and O(m*logm) are for sorting the two arrays.

// Space Complexity: O(1) as we are not using any extra space.



// Optimal Approach 2
#include <bits/stdc++.h>
using namespace std;

void swapIfGreater(long long arr1[], long long arr2[], int ind1, int ind2) {
    if (arr1[ind1] > arr2[ind2]) {
        swap(arr1[ind1], arr2[ind2]);
    }
}

void merge(long long arr1[], long long arr2[], int n, int m) {
    // len of the imaginary single array:
    int len = n + m;

    // Initial gap:
    int gap = (len / 2) + (len % 2);

    while (gap > 0) {
        // Place 2 pointers:
        int left = 0;
        int right = left + gap;
        while (right < len) { // until len reaches 9(arr is 8 index)
            // case 1: left in arr1[]
            //and right in arr2[]:
            if (left < n && right >= n) {
                // to know the position in right arr
                // gap - len(arr1)= 5 - 4  =1
                swapIfGreater(arr1, arr2, left, right - n);
            }
            // case 2: both pointers in arr2[]:
            else if (left >= n) {
                swapIfGreater(arr2, arr2, left - n, right - n);
            }
            // case 3: both pointers in arr1[]:
            else {
                swapIfGreater(arr1, arr1, left, right);
            }
            left++, right++;
        }
        // break if iteration gap=1 is completed:
        if (gap == 1) break;

        // Otherwise, calculate new gap:
        gap = (gap / 2) + (gap % 2);
    }
}

int main() {
    long long arr1[] = {1, 4, 8, 10};
    long long arr2[] = {2, 3, 9};
    int n = 4, m = 3;
    merge(arr1, arr2, n, m);
    cout << "The merged arrays are: " << "\n";
    cout << "arr1[] = ";
    for (int i = 0; i < n; i++) {
        cout << arr1[i] << " ";
    }
    cout << "\narr2[] = ";
    for (int i = 0; i < m; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    return 0;
}

// Complexity Analysis
// Time Complexity: O((n+m)*log(n+m)), where n and m are the sizes of the given arrays.
// Reason: The gap is ranging from n+m to 1 and every time the gap gets divided by 2. So, the time complexity of the outer loop will be O(log(n+m)). Now, for each value of the gap, the inner loop can at most run for (n+m) times. So, the time complexity of the inner loop will be O(n+m). So, the overall time complexity will be O((n+m)*log(n+m)).

// Space Complexity: O(1) as we are not using any extra space.