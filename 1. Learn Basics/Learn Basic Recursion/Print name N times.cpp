#include<bits/stdc++.h>
using namespace std;

void fn(int i, int n){
    
    if(i>n) return; // Base Condition
    cout << "Sharma" << endl;
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
// Sharma
// Sharma
// Sharma
