// Brute Force approach
class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            int n = nums.size();
            set<vector<int>> st;
            for (int i = 0; i < n; i++) {
                set<int> hashset;
                for (int j = i + 1; j < n; j++) {
                        int third  = -(nums[i]+nums[j]);
                        if (hashset.find(third) != hashset.end()) {
                            vector<int> temp = {nums[i], nums[j], third};
                            sort(temp.begin(), temp.end());
                            st.insert(temp);
                        }
                        hashset.insert(nums[j]);
                
                }
            }
            vector<vector<int>> ans(st.begin(), st.end());
            return ans;
        }
    };

// Better approach
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size(); //size of the array
    set<vector<int>> st;

    //checking all possible quadruplets:
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            set<long long> hashset;
            for (int k = j + 1; k < n; k++) {
                // taking bigger data type
                // to avoid integer overflow:
                long long sum = nums[i] + nums[j];
                sum += nums[k];
                long long fourth = target - sum;
                if (hashset.find(fourth) != hashset.end()) {
                    vector<int> temp = {nums[i], nums[j], nums[k], (int)(fourth)};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                // put the kth element into the hashset:
                hashset.insert(nums[k]);
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

int main()
{
    vector<int> nums = {4, 3, 3, 4, 4, 2, 1, 2, 1, 1};
    int target = 9;
    vector<vector<int>> ans = fourSum(nums, target);
    cout << "The quadruplets are: \n";
    for (auto it : ans) {
        cout << "[";
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    return 0;
}


