#include<bits/stdc++.h>
 using namespace std;
 
 int countPlatforms(int n,int arr[],int dep[])
 {
    int ans=1; //final value
    for(int i=0;i<=n-1;i++)
    {
        int count=1; // count of overlapping interval of only this   iteration
        for(int j=i+1;j<=n-1;j++)
        {
           // Check if train i and train j overlap
           if ((arr[i] >= arr[j] && arr[i] <= dep[j]) || // Condition 1: Train i arrives during train j's schedule
           (arr[j] >= arr[i] && arr[j] <= dep[i])) { // Condition 2: Train j arrives during train i's schedule
           {
               count++;
           }
        }
        ans=max(ans,count); //updating the value
    }
    return ans;
 }
 
 int main()
 {
    int arr[]={900,945,955,1100,1500,1800};
    int dep[]={920,1200,1130,1150,1900,2000};
    int n=sizeof(dep)/sizeof(dep[0]);
    cout<<"Minimum number of Platforms required "<<countPlatforms(n,arr,dep)<<endl;
 }
Output: Minimum number of Platforms required 3

Time Complexity: O(n^2)  (due to two nested loops).

Space Complexity: O(1)  (no extra space used).

// Optimal Approach

#include<bits/stdc++.h>
using namespace std;
 
 int countPlatforms(int n,int arr[],int dep[])
 {
    sort(arr, arr+n);
    sort(dep, dep+n);
    int i = 0;
    int j =0;
    int cnt = 0;
    int maxCnt = 0;
    while( i < n && j < n) {
        // If the next event is an arrival
        if(arr[i] <= dep[j]){
            cnt++;
            i++;
        } else{ // If the next event is a departure
            cnt--;
            j++;
        }
        maxCnt = max(maxCnt, cnt);
    }
    return maxCnt;
 }
 
 int main()
 {
    int arr[]={900,945,955,1100,1500,1800};
    int dep[]={920,1200,1130,1150,1900,2000};
    int n=sizeof(dep)/sizeof(dep[0]);
    cout<<"Minimum number of Platforms required "<<countPlatforms(n,arr,dep)<<endl;
 }
// Minimum number of Platforms required 3

// Time Complexity: O(nlogn) Sorting takes O(nlogn) and traversal of arrays takes O(n) so overall time complexity is O(nlogn).

// Space complexity: O(1)  (No extra space used).