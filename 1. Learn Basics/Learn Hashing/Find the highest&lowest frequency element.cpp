#include <bits/stdc++.h>
using namespace std;

void countFreq(int arr[], int n)
{
    map<int, int> freq;

    // Count frequencies
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }

    for (auto it : freq)
    {
        cout << it.first << "->" << it.second << endl;
    }

    int maxFreq = 0, minFreq = n;
    int maxEle = 0, minEle = 0;

    // Find elements with highest and lowest frquency
    for (const auto& pair : freq)
    {
        if (pair.second > maxFreq)
        {
            maxFreq = pair.second;
            maxEle = pair.first;
        }
        if (pair.second < minFreq)
        {
            minFreq = pair.second;
            minEle = pair.first;
        }
    }

    cout << "The highest frequency element is: " << maxEle << "\n";
    cout << "The lowest frequency element is: " << minEle << "\n";
}
int main()
{
    int arr[] = {10, 5, 10, 15, 10, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    countFreq(arr, n);
    return 0;
}

// Output:
// 5->2
// 10->3
// 15->1
// The highest frequency element is: 10
// The lowest frequency element is: 15