// start with Brute force
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int sum = 0;
    int arr[] = {3, 1, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int mod = (int)(1e9 + 7);
    for (int i = 0; i < n; i++)
    {
        int mini = arr[i];
        for (int j = i; j < n; j++)
        {
            mini = min(mini, arr[j]);
            sum = (sum + mini) % mod;
        }
    }
    cout << sum << "";
    return 0;
}
// output: 17

// better approach
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> getNSL(vector<int> &arr, int n)
    {
        vector<int> result(n);
        std::stack<int> st;

        for (int i = 0; i < n; i++)
        {
            if (st.empty())
            {
                result[i] = -1;
            }
            else
            {
                while (!st.empty() && arr[st.top()] >= arr[i])
                    st.pop();

                result[i] = st.empty() ? -1 : st.top();
            }

            st.push(i);
        }
        return result;
    }

    vector<int> getNSR(vector<int> &arr, int n)
    {
        vector<int> result(n);
        std::stack<int> st;

        for (int i = n - 1; i >= 0; i--)
        {
            if (st.empty())
            {
                result[i] = n;
            }
            else
            {
                while (!st.empty() && arr[st.top()] > arr[i])
                    st.pop();

                result[i] = st.empty() ? n : st.top();
            }

            st.push(i);
        }
        return result;
    }

    int SumSubarrayMinimum(std::vector<int> &arr)
    {
        int n = arr.size();

        vector<int> NSL = getNSL(arr, n);
        vector<int> NSR = getNSR(arr, n);

        long long sum = 0;

        long long Mod = 1e9 + 7;

        for (int i = 0; i < n; i++)
        {
            long long ls = i - NSL[i]; // left me kitne elements honge
            long long rs = NSR[i] - i; // right me kitne elements honge

            long long totalWays = ls * rs;

            // totalWays subarrays honge jinka minimum arr[i]
            long long totalSum = arr[i] * totalWays;

            sum = (sum + totalSum) % Mod;
        }
        return sum;
    }
};

int main()
{
    Solution solution;
    vector<int> arr = {3, 1, 2, 4};
    long long result = solution.SumSubarrayMinimum(arr);
    cout << result;
    return 0;
}