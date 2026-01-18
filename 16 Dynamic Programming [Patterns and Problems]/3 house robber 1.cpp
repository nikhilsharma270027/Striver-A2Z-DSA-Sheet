// #include <bits/stdc++.h>
// using namespace std;
// class Solution
// {
// public:
//     int dp[101];
//     int solve(vector<int> &nums, int i, int n){

//         if(i >= n) return 0;
//         if(dp[i] != -1) return dp[i];

//         int steal = nums[i] + solve(nums, i + 2, n);
//         int skip = solve(nums, i + 1, n);

//         return dp[i] = max(steal , skip);
//     }
//     int rob(vector<int> &nums)
//     {
//         int n = nums.size();
//         memset(dp, -1, sizeof(dp));
//         return solve(nums, 0, n);
//     }
// };

// int
// main()
// {
//     Solution sol;
//     vector<int> nums = {1, 2, 3, 1};
//     cout << sol.rob(nums) << endl;
//     return 0;
// }


// Bottom up approach
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    int rob(vector<int> &nums){

    }
}

int
main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 1};
    cout << sol.rob(nums) << endl;
    return 0;
}
