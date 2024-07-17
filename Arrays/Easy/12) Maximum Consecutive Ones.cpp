#include <bits/stdc++.h>
using namespace std;

// Define a class named Solution
class Solution {
  public:
    // Method to find the maximum number of consecutive 1s in the vector
    int findMaxConsecutiveOnes(vector<int> &nums) {
      int cnt = 0; // Counter to keep track of current streak of 1s
      int maxi = 0; // Variable to store the maximum streak of 1s found

      // Iterate through each element in the vector
      for (int i = 0; i < nums.size(); i++) {
        // If the current element is 1, increment the counter
        if (nums[i] == 1) {
          cnt++;
        } else {
          // If the current element is not 1, reset the counter
          cnt = 0;
        }

        // Update maxi to be the maximum of current maxi and cnt
        maxi = max(maxi, cnt);
      }

      // Return the maximum streak of 1s found
      return maxi;
    }
};

int main() {

  vector<int> nums = { 1, 1, 0, 1, 1, 1 };
  // Create an object of the Solution class
  Solution obj;

  // Call the method to find the maximum consecutive 1s and store the result in ans
  int ans = obj.findMaxConsecutiveOnes(nums);
  cout << "The maximum consecutive 1's are " << ans << endl;

  return 0;
}
