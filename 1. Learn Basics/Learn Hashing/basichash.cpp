#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0;i<n;i++){
       cin >> arr[i]; 
    }
    
    // Precompute
    int hash[13] = {0};      // hash arr consists of all values zero
    for(int i = 0;i<n;i++){
        hash[ arr[i] ] += 1;
    }
    
    // Hash Query                       
    int q;                              
    cin >> q;                           
    while(q--){                         // Process each query using a for loop
                                        // for (int i = 0; i < q; i++) {
        int number;                     //      int number;
        cin >> number;                  //      int number;
        // Fetch                        //      Fetch and print the count of `number`
        cout << hash[number] << endl;   //      cout << hash[number] << endl;
    }
    return 0;
}

// Input:           // Output:
// 5                
// 1 3 2 1 3
// 5                // 
// 1                // 2
// 4                // 0
// 2                // 1
// 3                // 2
// 12               // 0