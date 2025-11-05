// Recursion Basic
// fibonacci(sum) {
//     if(n == 0) return 0;
//     if(n == 1) return 1;
//     return f(n-1) + f(n-2);
// }
    


// Memoization
#include <bits/stdc++.h>
using namespace std;
int f(int n , vector<int>& dp) {
    if(n<= 1) return n; // 0 or 1
    
    if(dp[n] != -1) return dp[n];
    return dp[n] = f(n - 1, dp) + f(n-2, dp);
}

int main(){
    int n = 5;
    vector<int> dp(n+1, -1);
    cout << f(n, dp);
    return 0;
}

//------------------------///
//Tabulation - Bottom Up
#include <bits/stdc++.h>
using namespace std;
int main() {

    int n=5;
    vector<int> dp(n+1,-1);
    
    dp[0]= 0;
    dp[1]= 1;
    
    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1]+ dp[i-2];
    }
    cout<<dp[n];
    return 0;
}


//----------------------------//
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n = 5;
    
    int prev2 = 0;
    int prev = 1;
    
    for(int i = 2;i<=n;i++) {
        int cur_i = prev2 + prev;
        prev2 = prev;
        prev = cur_i;
    }
    cout << prev;
    return 0;
}