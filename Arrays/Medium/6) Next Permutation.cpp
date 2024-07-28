// better Approach
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int arr[] = {1,3,2}; // vector<int> arr= {1,3,2};
    
    next_permutation(arr,arr+3);//using in-built function of C++
    // next_permutation(arr.begin(),arr.end()); if using vector
    cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2];
    
    return 0; 
}

