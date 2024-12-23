#include<bits/stdc++.h>
using namespace std;

int SumOfSubarrayRange(std::vector<int> num){
    int n = num.size();
    int sum = 0;
    for(int i = 0 ; i < n-1;i++) {
        int longest = num[i], smallest = num[i];
        for(int  j = i+1; j<n;j++) {
            longest = max(longest, num[j]);
            smallest = min(smallest, num[j]);
            sum = sum + (longest - smallest);
        }
    }
    return sum;
}

int main(){
    vector<int> num = {1, 4, 3, 2};
    int res = SumOfSubarrayRange(num);
    cout << res << " ";
\
    return 0;
}

// Complexity
// TC -> o(n square)
// sc -> o(1)
// Output: 13