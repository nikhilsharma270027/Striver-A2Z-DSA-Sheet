#include<bits/stdc++.h>
using namespace std;

int main() {
    int N = 1;
    int cnt = 0;
    for(int  i = 1;i<=sqrt(N);i++) {
        if(N % i == 0) {
            cnt = cnt + 1;
            if(N/i != i){
                cnt = cnt + 1;
            }
        }
        if(cnt > 2) break;
    }
    if(cnt == 2) cout << "yes";
    else cout << "NO";

    return 0;
}