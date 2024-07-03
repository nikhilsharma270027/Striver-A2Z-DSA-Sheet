#include<bits/stdc++.h>
using namespace std;

void fn(int i, int n){
    
    if(i>n) return;
    cout << i << endl;
    fn(i+1,n);
    
}

int main(){

    int n;
    cin >> n;
    fn(1,n);
    return 0;
    
}

// Input:
// 3

// Output:
// 1
// 2
// 3