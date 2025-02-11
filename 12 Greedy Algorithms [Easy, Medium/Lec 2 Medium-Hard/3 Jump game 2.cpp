#include <bits/stdc++.h>
using namespace std;

int func(int ind, vector<int>& arr, int jumps) {
    int n = arr.size();
    // Base case: If we reach or exceed the last index, return the number of jumps
    if (ind >= n - 1) {
        return jumps;
    }
    
    int mini = INT_MAX; // Initialize the minimum jumps to a large value
    // Try all possible jumps from the current position
    for (int i = 1; i <= arr[ind]; i++) {
        if (ind + i < n) { // Ensure we don't go out of bounds
            mini = min(mini, func(ind + i, arr, jumps + 1));
        }
    }
    return mini;
}

int jump(vector<int>& nums) {
    return func(0, nums, 0);
}

int main() {
    vector<int> arr = {2, 3, 1, 1, 4};
    cout << "Minimum jumps required: " << jump(arr) << endl;
    return 0;
}