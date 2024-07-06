#include<bits/stdc++.h>
using namespace std;

// Hashing using Map for Integer
int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0;i<n;i++) {
        cin >> arr[i];
    }
    
    //pre-compute
    map<int, int> mpp;
    for(int i = 0;i<n;i++) {
        mpp[arr[i]]++;
    }
    
    // auto iterator
    for(auto it: mpp) {
        cout << it.first << "->" << it.second << endl;
    }
    
    int q;
    cin >> q;
    while(q--) {
        int number;
        cin >> number;
        //fetch
        cout << mpp[number] << endl;
    }
}

// input:               // Output:
// 7                    // 1->1
// 1 2 3 1 3 2 12       // 2->2
// 5                    // 3->2
// 1                    // 12->1
// 2                    // 2
// 3                    // 2
// 4                    // 2
// 12                   // 0
                        // 1
    