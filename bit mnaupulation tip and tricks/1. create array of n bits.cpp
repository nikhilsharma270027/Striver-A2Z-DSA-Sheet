#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> power;
    int n = 15;
    for (int i = 0; i < 32; i++)
    {
        if ((n & (1 << i)) != 0)
    {
        power.push_back(1 << i);
    }
}
return power;

}

// output
// n = 15
// 1 2 4 8

// output 
// n = 12
// 4 8