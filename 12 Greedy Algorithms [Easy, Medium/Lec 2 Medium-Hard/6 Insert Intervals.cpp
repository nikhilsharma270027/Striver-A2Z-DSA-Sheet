#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> insert(vector<vector<int>>& a, vector<int>& ni) {
    vector<vector<int>> result;
    int i = 0; 
    int n = a.size(); 

    // Step 1: Add all intervals that come before the new interval and do not overlap
    while (i < n && a[i][1] < ni[0]) { // Check if the end of the current interval is less than the start of the new interval
        result.push_back(a[i]); // Add the non-overlapping interval to the result
        i++; 
    }

    // Step 2: Merge overlapping intervals with the new interval
    while (i < n && a[i][0] <= ni[1]) { // Check if the current interval overlaps with the new interval
        ni[0] = min(ni[0], a[i][0]); // Update the start of the new interval to the minimum of the two
        ni[1] = max(ni[1], a[i][1]); // Update the end of the new interval to the maximum of the two
        i++;
    }
    result.push_back(ni);

    // Step 3: Add all remaining intervals that come after the new interval
    while (i < n) { // Add all remaining intervals that do not overlap with the new interval
        result.push_back(a[i]); // Add the interval to the result
        i++; // Move to the next interval
    }

    return result; 
}

int main() {
    vector<vector<int>> intervals
    intervals.push_back({1, 3}); 
    intervals.push_back({6, 9});

    vector<int> newInterval; 
    newInterval.push_back(2);
    newInterval.push_back(5); 

    intervals = insert(intervals, newInterval);
    for (int i = 0; i < intervals.size(); i++) {
        cout << "[" << intervals[i][0] << "," << intervals[i][1] << "] ";
    }

    return 0;
}

// O/P: [1, 5] [6, 9]