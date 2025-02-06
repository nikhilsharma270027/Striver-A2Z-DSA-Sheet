#include<bits/stdc++.h>
using namespace std;

int AssignCookie(vector<int> greed, vector<int> CookieSize) {
    int n = greed.size();
    int m = CookieSize.size();
    int right, left = 0;
    sort(greed.begin(), greed.end());
    sort(CookieSize.begin(), CookieSize.end());
    
    while(left < m && right < n) {
        if(greed[right] <= CookieSize[left]) {
            right += 1;
        }
        left += 1;
    }
    return right;
}

int main() {
    vector<int> greed = {1, 5, 3, 3, 4};
    vector<int> CookieSize = {4, 2, 1, 2, 1, 3};
    int result = AssignCookie(greed, CookieSize);
    cout << result ;
}

// o/p: 3