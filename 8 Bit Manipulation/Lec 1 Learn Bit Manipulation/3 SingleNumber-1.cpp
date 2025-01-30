#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int singleNum(vector<int> &nums)
    {
        int n = nums.size();
        int XOR = 0;
        for (int i = 0; i < n; i++)
        {
            XOR = XOR ^ nums[i];
        }
        return XOR;
    }

    int usingMap(vector<int> &nums)
    {
        map<int, int> mpp;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            mpp[nums[i]]++;
        }
        for (auto it : mpp)
        {
            if (it.second == 1)
            {
                return it.first;
            }
        }

        return -1;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {4, 1, 2, 1, 2};
    int result = solution.singleNum(nums);
    int result1 = solution.singleNum(nums);
    cout << result << endl;
    ;
    cout << result1;
    return 0;
}
// O/P: 4