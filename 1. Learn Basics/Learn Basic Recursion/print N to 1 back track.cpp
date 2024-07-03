#include<bits/stdc++.h>
using namespace std;

void fn(int i, int n){
    
    if(i>n) return; // Base Condition
    fn(i+1,n);
    cout << i << endl; // Print after function
    
}

int main(){

    int i = 1;
    int n = 5;
    fn(i,n);
    return 0;
    
}

// Output
// 4
// 3
// 2
// 1