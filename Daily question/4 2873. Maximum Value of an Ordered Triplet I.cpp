You are given a 0-indexed integer array nums.

Return the maximum value over all triplets of indices (i, j, k) such that i < j < k. If all such triplets have a negative value, return 0.

The value of a triplet of indices (i, j, k) is equal to (nums[i] - nums[j]) * nums[k].

 

Example 1:

Input: nums = [12,6,1,2,7]
Output: 77
Explanation: The value of the triplet (0, 2, 4) is (nums[0] - nums[2]) * nums[4] = 77.
It can be shown that there are no ordered triplets of indices with a value greater than 77. 


class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long  maxi = 0;
        long long result = 0;
        for (int i = 0; i < n-2; i++) {
            for (int j = i + 1; j < n-1; j++) {
                for (int k = j + 1; k < n; k++) {
                    result =(long long) (nums[i] - nums[j]) * nums[k];
                    maxi = max(maxi, result);
                }
            }
        }
        return maxi;
    }
};


class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();

        vector<int> leftMaxi(n);
        vector<int> rightMaxk(n);

        for (int j = 1; j < n; j++) {
            leftMaxi[j] = max(leftMaxi[j - 1], nums[j - 1]); // [0,12,12,12,12]
        }

        for (int j = n - 2; j >= 0; j--) {
            rightMaxk[j] = max(rightMaxk[j + 1], nums[j + 1]); // [7, 7, 7, 7, 0]
        }

        long long result = 0;
        for (int j = 1; j < n; j++) {
            result =
                max(result, (long long)(leftMaxi[j] - nums[j]) * rightMaxk[j]);
        }
        return result;
    }
};