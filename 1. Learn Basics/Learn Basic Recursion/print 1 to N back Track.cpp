#include<bits/stdc++.h>
using namespace std;
// print 1 to N Back Trafn
void fn(int i, int n){
    
    if(i<1) return; // Base Condition
    fn(i-1,n);
    cout << i << endl; // Print after function
    
}

int main(){

    int n = 3;
    fn(n,n);
    return 0;
    
}

//Output
// 1
// 2
// 3