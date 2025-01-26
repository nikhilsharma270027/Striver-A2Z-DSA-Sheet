#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findNse(vector<int> &arr)
    {
        vector<int> nse(arr.size());
        // cout << arr.size() << " ";
        stack<int> st;
        for (int i = arr.size() - 1; i >= 0; --i)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            nse[i] = st.empty() ? arr.size() : st.top();
            cout << nse[i] << "\t";
            st.push(i);
        }
        cout << endl;
        return nse;
    }

    vector<int> findPsee(vector<int> &arr)
    {
        vector<int> pse(arr.size(), -1);
        stack<int> st;
        for (int i = 0; i < arr.size(); ++i)
        {
            while (!st.empty() && arr[st.top()] > arr[i])
            {
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            cout << pse[i] << "\t";
            st.push(i);
        }
        cout << endl;
        return pse;
    }

    long long rec(vector<int> &arr)
    {
        long long maxi = 0;

        vector<int> nse = findNse(arr);
        vector<int> pse = findPsee(arr);

        for (int i = 0; i < arr.size(); i++)
        {
            long long width = nse[i] - pse[i] - 1;
            long long area = arr[i] * width;
            maxi = max(maxi, area);
        }
        return maxi;
    }
};

int main()
{
    Solution solution;
    vector<int> arr = {3, 1, 2, 4};
    long long result = solution.rec(arr);
    cout << result;
    return 0;
}

4 4 3 4 4 3 2 4->3 1 2 4->2 4->4 3 1 2 4 2 4 4

// Better approach
#include <bits/stdc++.h>
    using namespace std;

class Solution
{
public:
    int LargestRectanhle(vector<int> &heights)
    {
        int n = heights.size();

        stack<int> st;
        int pse[n], nse[n];
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            if (st.empty())
                pse[i] = 0;
            else
                pse[i] = st.top() + 1;
            st.push(i);
        }
        while (!st.empty())
            st.pop();

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();

            if (st.empty())
                nse[i] = n - 1;
            else
                nse[i] = st.top() - 1;

            st.push(i);
        }
        int maxA = 0;
        for (int i = 0; i < n; i++)
        {
            maxA = max(maxA, heights[i] * (nse[i] - pse[i] - 1));
        }
        return maxA;
    }
};

int main()
{
    vector<int> heights = {3, 2, 10, 11, 5, 10, 6, 3};
    Solution obj;
    cout << "largest area" << obj.LargestRectanhle(heights);
    return 0;
}

result : 25

// optimal approach
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        int n = heights.size();
        
        for (int i = 0; i<=n;i++) {
            int currenttHeight = (i == n) ? 0 : heights[i];
            
            while(!st.empty() && heights[st.top()] > currenttHeight) {
                int height = heights[st.top()];
                st.pop();
                int width =  st.empty() ? i : i - st.top() - 1;
                maxArea  =max(maxArea, height * width);
            }
            st.push(i);
        }
        return maxArea;
    }
};

int main() {
    Solution solution;

    // Test input
    vector<int> heights = {3, 2, 10, 11, 5, 10, 6, 3};

    // Call the method and print the result
    int maxArea = solution.largestRectangleArea(heights);
    cout << "The largest rectangle area is: " << maxArea << endl;

    return 0;
}
