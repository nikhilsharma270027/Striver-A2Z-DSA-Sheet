#include<bits/stdc++.h>
using namespace std;
int cnt = 0;

void fn(){

    //Base condition
    if(cnt == 3) return;
    cout << cnt << endl;

    //Count Incremented
    cnt++;
    fn();

}

int main()
{
    fn();
    return 0;
}

// Output:
// 0
// 1
// 2
