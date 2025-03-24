#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(begin(meetings), end(meetings));
        int start = 0;
        int end = 0; 
        int result = 0;
        for(int  i = 0; i < meetings.size(); i++){
            if(meetings[i][0] > end) {
                result += meetings[i][0] - end - 1;
            }
            end = max(end, meetings[i][1]);
        }

        if(end < days){
            result += days - end;
        }

        return result;
    }
};

int main() {
    int days = 10;
    vector<vector<int>> meetings = {{5, 7}, {1, 3}, {9, 10}};

    Solution sol;
    int result = sol.countDays(days, meetings);
    cout << "Free days: " << result << endl;

    return 0;
}
