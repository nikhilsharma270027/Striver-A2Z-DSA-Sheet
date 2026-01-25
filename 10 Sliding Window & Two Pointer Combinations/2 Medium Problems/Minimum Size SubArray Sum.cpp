// 209. Minimum Size Subarray Sum
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

 

// Example 1:

// Input: target = 7, nums = [2,3,1,2,4,3]
// Output: 2
// Explanation: The subarray [4,3] has the minimal length under the problem constraint.
// Example 2:

// Input: target = 4, nums = [1,4,4]
// Output: 1
// Example 3:

// Input: target = 11, nums = [1,1,1,1,1,1,1,1]
// Output: 0

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();

        int i = 0, j = 0;
        int len = INT_MAX;
        int sum = 0;
        while (j < n) {
            sum += nums[j];

            // check if it mets the target
            // chota karna chah rahe hain window ko
            while (sum >= target) {
                sum -= nums[i];
                // i++;
            // } else if (sum == target) {
                len = min(len, j - i + 1);
                i++;
            }
            j++;
        }

        return len == INT_MAX ? 0 : len;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {2,3,1,2,4,3};
    int target1 = 7;
    cout << sol.minSubArrayLen(target1, nums1) << endl; // Output: 2

    vector<int> nums2 = {1,4,4};
    int target2 = 4;
    cout << sol.minSubArrayLen(target2, nums2) << endl; // Output: 1

    vector<int> nums3 = {1,1,1,1,1,1,1,1};
    int target3 = 11;
    cout << sol.minSubArrayLen(target3, nums3) << endl; // Output: 0

    return 0;
}