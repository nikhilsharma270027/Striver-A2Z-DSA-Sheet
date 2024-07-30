// Brute Force Approach
#include <bits/stdc++.h>
using namespace std;

vector<int> printLeadersBruteForce(int arr[], int n) {
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        bool leader = true;
        // Checking whether arr[i] is greater than all
        // the elements in its right side
        for (int j = i + 1; j < n; j++)
            if (arr[j] > arr[i]) {
                // If any element found is greater than current leader
                // curr element is not the leader.
                leader = false;
                break;
            }
        // Push all the leaders in ans array.
        if (leader)
            ans.push_back(arr[i]);
    }
    return ans;
}

int main() {
    int n = 6;
    int arr[n] = {10, 22, 12, 3, 0, 6};

    vector<int> ans = printLeadersBruteForce(arr, n);

    for (int i = 0; i < ans.size(); i++) {
        cout << "The Leaders are : " << ans[i] << " ";
    }

    cout << endl;
    return 0;
}

// Output : 22 12 6

// Complexity Analysis
// Time Complexity: O(N^2) { Since there are nested loops being used, at the worst case n^2 time would be consumed }.

// Space Complexity: O(N) { There is no extra space being used in this approach. But, a O(N) of space for ans array will be used in the worst case }.