#include<bits/stdc++.h>
using namespace std;

void fn(int i, int n){
    
    if(i<1) return; // Base Condition
    cout << i << endl;
    fn(i-1,n);
    
}

int main(){

    int n = 4;
    fn(n,n);
    return 0;
    
}

// Output:
// 4
// 3
// 2
// 1