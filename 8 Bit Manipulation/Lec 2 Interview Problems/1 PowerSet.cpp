#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		int n = nums.size();
		int subset = 1 << n;
		vector<vector<int>> ans;

		for(int  i = 0; i<  subset; i++) {
			vector<int> list;
			for(int j = 0; j< n; j++) {
				if(i & (1 << j)) {
					list.push_back(nums[j]);
				}
			}
			ans.push_back(list);
		}
		return ans;
	}
};

int main() {
	Solution solution;
	vector<int> nums = {1, 2, 3};
	vector<vector<int>> result = solution.subsets(nums);

	for ( auto& subset : result)  {
		cout << "{ ";
		for(int num : subset) {
			cout << num << " ";
		}
		cout << "}" << endl;
	}
	return 0;
}

// { }
// { 1 }
// { 2 }
// { 1 2 }
// { 3 }
// { 1 3 }
// { 2 3 }
// { 1 2 3 }