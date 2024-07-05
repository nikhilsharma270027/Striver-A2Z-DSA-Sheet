#include <bits/stdc++.h>
using namespace std;

//Fibonacci Series
int fn(int n)
{
    if (n <= 1)
        return n;
    int last = fn(n - 1);
    int slast = fn(n - 2);
    return last + slast;
}

int main()
{
    int n = 4;
    cout << fn(n);
}

// Output:
// 2

