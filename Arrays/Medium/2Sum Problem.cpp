// Two Sum : Check if a pair with given sum exists in Array
// Brute Froce Approach
// #include <bits/stdc++.h>
// using namespace std;

// string twoSum(int n, vector<int> &arr, int target) {
//     for (int i = 0; i < n; i++) {
//         for (int j = i + 1; j < n; j++) {
//             if (arr[i] + arr[j] == target) return "YES";
//         }
//     }
//     return "NO";
// }

// int main()
// {
//     int n = 5;
//     vector<int> arr = {2, 6, 5, 8, 11};
//     int target = 14;
//     string ans = twoSum(n, arr, target);
//     cout << "This is the answer for variant 1: " << ans << endl;
//     return 0;
// }
// Output: This is the answer for variant 1: YES

// variant 2
#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(int n, vector<int> &arr, int target) {
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) {
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }
    return { -1, -1};
}

int main() {
    int n = 5;
    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 14;
    vector<int> ans = twoSum(n, arr, target);
    cout << "This is the answer for variant 2: [" << ans[0] << ", "
         << ans[1] << "]" << endl;
    return 0;
}
// Output: This is the answer for variant 2: [1, 3]

// Better Approach 
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSumBetter(vector<int>& nums, int target) {
        map<int, int> mpp; // Map to store the index of each number
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            int moreNeeded = target - num; // Calculate the complement
            if (mpp.find(moreNeeded) != mpp.end()) {
                // If complement exists in the map, return the indices
                return { mpp[moreNeeded], i };
            }
            // Store the index of the current number
            mpp[num] = i; 
            
            // Print the contents of the map
            cout << "Map contents after iteration " << i << ": ";
            for (const auto &pair : mpp) {
                cout << "{" << pair.first << ": " << pair.second << "} ";
            }
            cout << endl;
        }
        // Return -1, -1 if no solution is found
        return { -1, -1 };
    }
};

int main() {
    vector<int> nums = { 2, 6, 5, 8, 10 }; // Example input
    int target = 14; // Example target

    Solution obj;
    vector<int> ans = obj.twoSumBetter(nums, target);

    // Print the result
    cout << "Indices of the two numbers that add up to " << target << " are: ";
    if (ans[0] != -1) {
        cout << ans[0] << " and " << ans[1] << endl;
    } else {
        cout << "No solution found" << endl;
    }

    return 0;
}

// Output:
// Map contents after iteration 0: {2: 0} 
// Map contents after iteration 1: {2: 0} {6: 1} 
// Map contents after iteration 2: {2: 0} {5: 2} {6: 1} 
// Indices of the two numbers that add up to 14 are: 1 and 3

//The time complexity is O(n log n) and the space complexity is O(n).


// Optimal Approach (Greedy method)
#include <bits/stdc++.h>
using namespace std;

string twoSumOptimal(int n, vector<int> &arr, int target) {
    sort(arr.begin(), arr.end());
    int left = 0, right = n - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == target) {
            return "YES";
        }
        else if (sum < target) left++;
        else right--;
    }
    return "NO";
}

int main() {
    int n = 5;
    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 14;
    string ans = twoSumOptimal(n, arr, target);
    cout << "This is the answer for variant 1: " << ans << endl;
    return 0;
}

// Output: 
// This is the answer for variant 1: YES

// Time Complexity: O(N) + O(N*logN), where N = size of the array.
// Reason: The loop will run at most N times. And sorting the array will take N*logN time complexity.

// Space Complexity: O(1) as we are not using any extra space.

// Note: Here we are distorting the given array. So, if we need to consider this change, the space complexity will be O(N).

