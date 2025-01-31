                                
#include <iostream>
#include <vector>
using namespace std;

int findSingleNumber(vector<int>& nums) {
    int ans = 0;

    // Iterate through each bit
    // position (from 0 to 31)
    for (int bitIndex = 0; bitIndex < 32; bitIndex++) {
        // Counter to count the number of
        // set bits at the current bit position
        int cnt = 0; 

        // Iterate through each
        // number in the input array
        for (int i = 0; i < nums.size(); i++) {
            // Check if the bit at bitIndex is
            // set in the current number nums[i]
            if (nums[i] & (1 << bitIndex)) {
                // Increment the counter
                // if the bit is set
                cnt++; 
            }
        }

        // If the count of set bits at the current bit 
        // position is not divisible by 3 (i.e., cnt % 3 == 1)
        // Set the corresponding bit in the answer variable ans
        if (cnt % 3 == 1) {
            ans |= (1 << bitIndex);
        }
    }
    // Return the decimal
    // representation of the answer
    return ans; 
}

int main() {
    vector<int> nums = {4, 4, 4, 2, 5, 5, 5};
    cout << "Input Array: ";
    for (auto num: nums){
        cout << num << " ";
    }
    cout << endl;
    cout << "Element that appears only once: " << findSingleNumber(nums) << endl; 
    return 0;
}

                                
        // optimal approach
                                
function findSingleNumber(nums) {
    // Sort the input array
    nums.sort((a, b) => a - b);

    // Traverse the sorted array and check
    // middle elements of groups of three
    for (let i = 1; i < nums.length; i += 3) {
        // If the current element is not equal to
        // the previous one, it's the unique element
        if (nums[i] !== nums[i - 1]) {
            return nums[i - 1];
        }
    }

    // If the unique element is not found in the
    // loop then it has to be the last element
    return nums[nums.length - 1];
}

let nums = [1, 1, 1, 2, 2, 2, 3, 4, 4, 4];
console.log("Input Array: " + nums.join(" "));
console.log("Element that appears only once: " + findSingleNumber(nums));                 