#include<bits/stdc++.h>
using namespace std;

//Count the number of set bits
// int main() {
//     int cnt = 0;
//     int n = 16;
//     while(n > 1){
//         if (n % 2 ==0 ) cnt++;
//         n = n / 2;
//     }
//     if(n == 1) cnt = 1;
//     cout << cnt ;
// }

// Competetive programmers
int main() {
    int cnt = 0;
    int n = 3;
    while(n != 0){
        cnt += (n & 1);
        n = n >> 1;
    }
    // if(n == 1) cnt = 1;
    cout << cnt ;
}

// int main() {
//     int cnt = 0;
//     int n = 3;
//     while(n != 0) {
//         n = n & (n -1);
//         cnt++;
//     }
//     cout << cnt ;
//     return 0;
// }