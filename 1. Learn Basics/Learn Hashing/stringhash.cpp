#include<bits/stdc++.h>
using namespace std;

// For Small character
int main() {
    string s;
    cin >> s;
    
    // pre-compute
    int hash[26] = {0};
    for(int i = 0;i<s.size();i++){
        hash[s[i] - 'a'] += 1;
    }
    
    int q;
    cin >> q;
    while(q--) {
        char c;
        cin >> c;
        //fetch
        cout << hash[c - 'a'] << endl;   
    }
    return 0;
}

// Input:
// abcdabehf
// 5
// a
// g
// h
// b
// C

//Output
// 2
// 0
// 1
// 2
// 1

// For Capital character
// int main() {
//     string s;
//     cin >> s;
    
//     // pre-compute
//     int hash[26] = {0};
//     for(int i = 0;i<s.size();i++){
//         hash[s[i] - 'A'] += 1;
//     }
    
//     int q;
//     cin >> q;
//     while(q--) {
//         char c;
//         cin >> c;
//         //fetch
//         cout << hash[c - 'A'] << endl;   
//     }
//     return 0;
// }

// For all 256 character
// int main() {
//     string s;
//     cin >> s;
    
//     // pre-compute
//     int hash[256] = {0};
//     for(int i = 0;i<s.size();i++){
//         hash[s[i]] += 1;
//     }
    
//     int q;
//     cin >> q;
//     while(q--) {
//         char c;
//         cin >> c;
//         //fetch
//         cout << hash[c] << endl;   
//     }
//     return 0;
// }