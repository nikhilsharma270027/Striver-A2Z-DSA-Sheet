// Climbing Stairs Problem
// You are climbing a staircase with n steps. You can take 1 or 2 steps at a time. 
// Find the number of distinct ways to reach the top.

#include <bits/stdc++.h>
using namespace std;
// class Solution {
// public:
//     int dp[46];
//     int solve(int n) {
//         if(n < 0) return 0;

//         if(dp[n] != -1) {
//             return dp[n];
//         }

//         if(n == 0) return 1; // we have got 1 ways to cover all stairs

//         int one_step  = solve(n-1);
//         int two_step  = solve(n-2);
        
//         return dp[n] = one_step + two_step;
//     }
//     int climbStairs(int n) {
//         memset(dp, -1, sizeof(dp));
//         return solve(n);
//     }   
// };

// int main() {
//     Solution obj;
//     int n = 4;
//     int val  = obj.climbStairs(n);
//     cout << "The ways to Climb are " << val; 
//     return 0;
// }

// Bottom up
// state: 
//     "Array[i] = no of ways t0o climb i stairs"

// array [ 0, 1,  2, _, _]
// arr[0] = 0 means if 0 stairs =  0 steps
// arr[1] = 1 means if 1 stairs =  1 steps
// arr[2] = 2 means if 2 stairs =  2 steps

// for arr[3] = arr[2] + arr[1]

class Solution {
public:
    int climbStairs(int n) {

        if(n == 1 || n == 2 || n == 3)  return n;
        
        vector<int> dp(n+1, 0);
        dp[0] = 0; // 1 way to stay at ground
        dp[1] = 1; // 1 way to climb 1 stair
        dp[2] = 2; // 2 way to climb 2 stair

        for(int i = 3; i <= n ; i++) {
            dp[i] =  dp[i-1] + dp[i - 2];
        }

        return dp[n];
    }   
};

int main() {
    Solution obj;
    int n = 100;
    int val  = obj.climbStairs(n);
    cout << "The ways to Climb are " << val; 
    return 0;
}