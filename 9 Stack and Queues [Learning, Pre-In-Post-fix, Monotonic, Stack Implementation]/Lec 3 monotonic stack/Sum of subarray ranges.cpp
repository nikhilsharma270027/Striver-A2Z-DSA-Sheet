// #include<bits/stdc++.h>
// using namespace std;

// int SumOfSubarrayRange(std::vector<int> num){
//     int n = num.size();
//     int sum = 0;
//     for(int i = 0 ; i < n-1;i++) {
//         int longest = num[i], smallest = num[i];
//         for(int  j = i+1; j<n;j++) {
//             longest = max(longest, num[j]);
//             smallest = min(smallest, num[j]);
//             sum = sum + (longest - smallest);
//         }
//     }
//     return sum;
// }

// int main(){
//     vector<int> num = {1, 4, 3, 2};
//     int res = SumOfSubarrayRange(num);
//     cout << res << " ";
//     return 0;
// }

// Complexity
// TC -> o(n square)
// sc -> o(1)
// Output: 13



// Better Approach
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findNse(vector<int> &arr) {
        vector<int> nse(arr.size());
        // cout << arr.size() << " ";
        stack<int> st;
        for (int i = arr.size() - 1; i >= 0; --i) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            nse[i] = st.empty() ? arr.size() : st.top();
            cout << nse[i] << "\t";
            st.push(i);
        }
        cout << endl;
        return nse;
    }

    vector<int> findPsee(vector<int> &arr) {
        vector<int> pse(arr.size(), -1);
        stack<int> st;
        for (int i = 0; i < arr.size(); ++i) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
             cout << pse[i] << "\t";
            st.push(i);
        }
        cout << endl;
        return pse;
    }

    long long sumSubarrayMins(vector<int>& arr) {
        int MOD = (int)1e9 + 7;
        long long sum = 0;

        vector<int> nse = findNse(arr);
        vector<int> pse = findPsee(arr);

        for (int i = 0; i < arr.size(); ++i) {
            long long left = i - pse[i];
            long long right = nse[i] - i;
            sum = (sum + (left * right * 1LL * arr[i]));
        }
        return sum;
    }

    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(n, n); 
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }
            if (!st.empty()) {
                nge[i] = st.top();
            }
            cout << nge[i] << "\t";
            st.push(i);
        }
        cout << endl;
        return nge;
    }

    vector<int> previousGreater(vector<int> &nums) {
        int n = nums.size();
        vector<int> maxPrev(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }
            if (!st.empty()) {
                maxPrev[i] = st.top();
            }
            cout << maxPrev[i] << "\t";
            st.push(i);
        }
        cout << endl;
        return maxPrev;
    }

    long long sumSubarrayMaxs(vector<int> &nums) {
        int MOD = (int)1e9 + 7;
        long long sum = 0;

        vector<int> nge = nextGreaterElements(nums);
        vector<int> pge = previousGreater(nums);
        for (int i = 0; i < nums.size(); ++i) {
            long long left = i - pge[i];
            long long right = nge[i] - i;
            sum = (sum + (left * right * 1LL * nums[i]));
        }
        return sum;
    }

    long long subArrayRanges(vector<int>& nums) {
        long long mini = sumSubarrayMins(nums);
        long long maxi = sumSubarrayMaxs(nums);
        return maxi - mini;
    }
};


int main()
{
    Solution solution;
    vector<int> arr = {1, 4, 3, 2};
    long long result = solution.subArrayRanges(arr);
    cout << result;
    return 0;
}