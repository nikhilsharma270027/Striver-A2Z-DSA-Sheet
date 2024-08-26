// Brute Force Approach
#include <bits/stdc++.h>
using namespace std;

int floorSqrt(int n) {
    int ans = 0;
    //linear search on the answer space:
    for (long long i = 1; i <= n; i++) {
        long long val = i * i;
        if (val <= n * 1ll) { //1ll is long long
            ans = i;
        } else {
            break;
        }
    }
    return ans;
}

int main() {
    int n = 28;
    int ans = floorSqrt(n);
    cout << "The floor of square root of " << n
         << " is: " << ans << "\n";
    return 0;
}

// Output: The floor of square root of 28 is: 5

// Complexity Analysis
// Time Complexity: O(N), N = the given number.
// Reason: Since we are using linear search, we traverse the entire answer space.

// Space Complexity: O(1) as we are not using any extra space.


// Optimal Approach
#include <bits/stdc++.h>
using namespace std;

int floorSqrt(int n) {
    int low = 1, high = n;
    //Binary search on the answers:
    while (low <= high) {
        long long mid = (low + high) / 2;
        long long val = mid * mid;
        if (val <= (long long)(n)) {
            //eliminate the left half:
            low = mid + 1;
        }
        else {
            //eliminate the right half:
            high = mid - 1;
        }
    }
    return high;
}

int main() {
    int n = 28;
    int ans = floorSqrt(n);
    cout << "The floor of square root of " << n
         << " is: " << ans << "\n";
    return 0;
}

// Complexity Analysis
// Time Complexity: O(logN), N = size of the given array.
// Reason: We are basically using the Binary Search algorithm.

// Space Complexity: O(1) as we are not using any extra space.