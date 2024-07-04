#include<bits/stdc++.h>
using namespace std;

// Reversing array in recursion
void func(int i,int arr[], int n){

    if ( i >= n/2 ) return;
    swap( arr[i], arr[n-i-1] );
    func( i+1, arr, n );

}

int main(){

    int n;
    cin >> n;;
    int arr[n];
    for(int i = 0;i<n;i++) cin >> arr[i];
    func( 0, arr, n );
    for (int i = 0;i<n;i++) cout << arr[i] << " ";
    return 0;
    
}

//Input: 5
//       1 2 3 4 5
//Output:5 4 3 2 1