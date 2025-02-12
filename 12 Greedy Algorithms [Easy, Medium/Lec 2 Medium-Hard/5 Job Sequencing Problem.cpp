#include<bits/stdc++.h>
using namespace std;

struct Job {
    int id;
    int dead;
    int profit;
};

class Solution {
    public:
        bool static comparsion(Job a, Job b) {
            return (a.profit > b.profit);
        }
        
    pair<int, int> JobScheduling(Job arr[], int n) {
        
        sort(arr, arr + n, comparsion);
        int maxi = arr[0].dead; // deadline of first job as maxi
        // find the which is the highs deadline
        for(int i = 1;i<n;i++){
            maxi = max(maxi, arr[i].dead);// iter will tell us the max deadline
            // cout << maxi;
        }
        int slot[maxi + 1]; // defining a hashmap with +1 of space as -1 for all
        
        for (int i = 0; i <= maxi; i++)
         slot[i] = -1;
        int countJobs = 0, jobProfit = 0;
        
        for(int i = 0 ;i<n;i++) {
            for(int j = arr[i].dead;j > 0; j--) {
                if(slot[j] == -1) {
                    slot[j] = i;
                    countJobs++;
                    jobProfit += arr[i].profit;
                    break;
                }
            }
        }
        return make_pair(countJobs, jobProfit);
    }
};
int main() {
   int n = 4;
   Job arr[n] = {{1,4,20},{2,1,10},{3,2,40},{4,2,30}};

   Solution ob;
   //function call
   pair < int, int > ans = ob.JobScheduling(arr, n);
   cout << ans.first << " " << ans.second << endl;

   return 0;
} 
Output: 3 90

Time Complexity: O(N log N) + O(N*M).

O(N log N ) for sorting the jobs in decreasing order of profit. O(N*M) since we are iterating through all N jobs and for every job we are checking from the last deadline, say M deadlines in the worst case.

Space Complexity: O(M) for an array that keeps track on which day which job is performed if M is the maximum deadline available.