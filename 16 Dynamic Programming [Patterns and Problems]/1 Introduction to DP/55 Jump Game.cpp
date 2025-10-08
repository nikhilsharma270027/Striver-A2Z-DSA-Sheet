// rescursion (TLE)
class Solution {
public:
    bool solve(vector<int>& nums, int n, int idx) {
        if (idx == n - 1) { // if idx reaches last step
            return true;
        }

        if (idx >= n)
            return false; // edge case if idx out of array

        for (int i = 1; i <= nums[idx]; i++) {
            // idx -> if 1   1+1
            // idx -> if 2   2+1  2+2
            // idx -> if 3   3+1  3+2 3+3
            if (solve(nums, n, idx + i) == true) {
                return true;
            }
        }

        return false;
    }

    bool canJump(vector<int>& nums) {
        int n = nums.size();
        return solve(nums, n, 0);
    }
};

// memoization
class Solution {
public:
    int dp[10001];
    bool solve(vector<int>& nums, int n, int idx) {
        if (idx == n - 1) { // if idx reaches last step
            return true;
        }

        if (dp[idx] != -1)
            return dp[idx];

        if (idx >= n)
            return false; // edge case if idx out of array

        for (int i = 1; i <= nums[idx]; i++) {
            // idx -> if 1   1+1
            // idx -> if 2   2+1  2+2
            // idx -> if 3   3+1  3+2 3+3
            if (solve(nums, n, idx + i) == true) {
                return dp[idx] = true;
            }
        }

        return dp[idx] = false;
    }

    bool canJump(vector<int>& nums) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(nums, n, 0);
    }
};
