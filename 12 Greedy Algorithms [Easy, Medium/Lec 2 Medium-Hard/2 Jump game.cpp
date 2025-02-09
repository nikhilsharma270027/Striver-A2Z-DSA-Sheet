#include <vector>   
#include <algorithm>
#include <iostream>
using namespace std;

bool canJump(vector<int>& nums) {
    int n = nums.size();
    int maxIndex = 0;
    for(int i = 0;i<n;i++){
      if(i > maxIndex) return false;
      maxIndex = max(maxIndex, i + nums[i]);
    }
    return true;
}

int main() {
    vector<int> arr = {2, 3 , 1, 0, 4}; // true
    // vector<int> arr = {3, 2 , 1, 0, 4}; /// false
    if(canJump(arr)) 
        cout << "True";
    else 
        cout << "false";
}