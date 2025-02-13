#include<bits/stdc++.h>
using namespace std;

// class Solution {
//     public:
        vector<vector<int>> merge(vector<vector<int>>& intervals) {
            vector<vector<int>> mergedIntervals;
            if(intervals.size() == 0) {
                return mergedIntervals; 
            }
            sort(intervals.begin(), intervals.end());
            vector<int> tempInterval = intervals[0];
            
            for(auto it : intervals) {
                // [1, 3] <= [2, 4] 
                // check if 
                //   1               3
                if(it[0] <= tempInterval[1]) { 
                    tempInterval[1] = max(it[1], tempInterval[1]);
                                    // result right in both
            } else {
                mergedIntervals.push_back(tempInterval);
                tempInterval = it; // at end put the the next it 
            }
            }
            mergedIntervals.push_back(tempInterval); // adding the last interval
            return mergedIntervals;
        }
// };

int main()
{
    vector<vector<int>> arr = {{1, 3}, {8, 10}, {2, 6}, {15, 18}};
    vector<vector<int>> ans = merge(arr);
    cout << "The merged intervals are: " << "\n";
    for (auto it : ans) {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << endl;
    return 0;
}

// O/P : The merged intervals are: 
// [1, 6] [8, 10] 


// check if 
//   1               3
//   