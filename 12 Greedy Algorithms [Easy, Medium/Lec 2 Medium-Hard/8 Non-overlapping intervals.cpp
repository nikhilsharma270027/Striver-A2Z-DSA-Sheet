#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	static bool comp(vector<int>& val1, vector<int>& val2) {
		return val1[1] < val2[1]; // sort by end element
	}
public:
	int merge(vector<vector<int>>& arr) {
        int n = arr.size();
		sort(arr.begin(),arr.end(), comp);

		int cnt = 1;
		int lastEndTime = arr[0][1]; // 2
		for(int i =1; i< n; i++) {
			if(arr[i][0] >= lastEndTime) { // 3 >= 2 true
				cnt++;                                                  
				lastEndTime = arr[i][1];  // update
			}
		}
		return n - cnt;
	}
};

int main()
{
	Solution solution;
	vector<vector<int>> arr = {{0, 5}, {3, 4}, {1, 2}, {5, 9}, {5, 7}, {7, 9}};
		int ans = solution.merge(arr);
		cout << "The merged intervals are: "<< ans << "\n";

		return 0;
}