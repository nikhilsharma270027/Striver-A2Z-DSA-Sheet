    #include<bits/stdc++.h>
using namespace std;

// Hashing using Map for String
int main() {
    string s;
    cin >> s;
    
    //pre-compute
    map<char, int> mpp;
    for(int i = 0;i<s.size();i++) {
        mpp[s[i]]++;
    }
    
    // auto iterator
    for(auto it: mpp) {
        cout << it.first << "->" << it.second << endl;
    }
    
    int q;
    cin >> q;
    while(q--) {
        char number;
        cin >> number;
        //fetch
        cout << mpp[number] << endl;
    }
}

// input:  
// abcabc
// 5
// a
// b
// c
// a
// b
// c

//Input:
// a->2
// b->2
// c->2
// 2
// 2
// 2
// 0
// 0
    