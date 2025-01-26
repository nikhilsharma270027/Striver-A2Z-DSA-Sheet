// brute force
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size() - k;
    vector<int> final;
    
    for(int i = 0;i <= n;i++){
        int maxi = nums[i];
        for(int j = i; j <= i+k-1;j++){
            maxi = max(maxi, nums[j]);
        }
         final.push_back(maxi);
    }
    return final;
    }
};

int main(){
    Solution solution;
    vector<int> arr = {1, 3, -1, -3, 5, 3, 2, 1, 6};
    int k = 3;
    vector<int> result = solution.maxSlidingWindow(arr, k);
    for(int i = 0; i < result.size();i++)
    cout << result[i] << " ";
    return 0;
}

// o/p : 3 3 5 5 5 3 6

// better force
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::deque<int> dq ;
        vector<int> ans;
        for(int i  = 0;i<nums.size();i++) {
            
            if(!dq.empty() && dq.front() == i - k) {
                dq.pop_front(); // make sure its maintaining current window ele
            }
            
            while(!dq.empty() && nums[dq.back()] < nums[i]) {
                // if greater elemnt comes disrupting the decreaing flow remove them
                dq.pop_back();
            }
            
            dq.push_back(i);
            // first window start at 2, means k - 1 = 3 -1 =2
            // thats is 0 1 2
            if(i >= k - 1) ans.push_back(nums[dq.front()]);
            // last elemt in the dequeue is the ans for all windows
        }
        return ans;
    }
};

int main(){
    Solution solution;
    vector<int> arr = {1,3,-1,-3,5,3,7,1,6};
    int k = 3;
    vector<int> result = solution.maxSlidingWindow(arr, k);
    for(int i = 0; i < result.size();i++)
    cout << result[i] << " ";
    return 0;
}
// O/P : 3 3 5 5 7 7 7 