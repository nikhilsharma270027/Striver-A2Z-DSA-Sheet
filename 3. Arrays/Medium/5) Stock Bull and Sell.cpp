// Brute Force Approach
#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &arr) {
    int mini = arr[0]; 
    int maxProfit = 0; 
    int n = arr.size(); 
    
    for(int i = 0; i < n; i++) {
        int cost = arr[i] - mini; // Calculate the current profit by subtracting the minimum price so far from the current price
        maxProfit = max(maxProfit, cost); // Update the maximum profit if the current profit is greater than the previous maximum profit
        mini = min(mini, arr[i]); // Update the minimum price if the current price is lower than the previous minimum price
    }
    return maxProfit;
}

int main() {
    vector<int> arr = {7, 1, 5, 3, 6, 4}; 
    int maxPro = maxProfit(arr); 
    cout << "Max profit is: " << maxPro << endl; 
}

// Output: Max profit is: 5

// Complexity Analysis
// Time complexity: O(n)

// Space Complexity: O(1)
