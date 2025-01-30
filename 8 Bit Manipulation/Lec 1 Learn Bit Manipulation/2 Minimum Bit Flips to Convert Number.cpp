#include<bits/stdc++.h>
using namespace std;

// Minimum Bit Flips to Convert Number
int main() {
    int cnt = 0;
    int start= 10;
    int goal = 7;
    int ans  = start ^ goal;
    for(int  i = 0; i < 32; i++){
        if(ans & (1 << i)){
            cout << (ans & (1 << i)) << endl;
            cnt++;
        }
    }
    cout << cnt ;
}
// Time Complexity: O(31) as the time complexity remains constant and because the loop iterates 
// over a fixed number of bit positions which is constant and independent of the magnitude of the 
// input numbers.

// Space Complexity: O(1) as the algorithm uses only a constant amount of extra space. The space 
// required does not increase with the size of input numbers.