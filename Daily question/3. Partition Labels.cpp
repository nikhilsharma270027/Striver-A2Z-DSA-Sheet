Input: s = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.

// 
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
   vector<int> partitionLabels(string s) {
        int n = s.length();
         
         // to store result
         vector<int> result;

         // last occurance of each character
         // unordered_mao<char, int> mp;
         vector<int> mp(26, -1);
         for(int  i =0;i<n;i++){
            int index = s[i] - 'a'; // we get index
            mp[index] = i;
         } // we have all the last occurance of each char

        int i = 0;// pointer
        while( i < n ){
            // now i stand on first char and find end
            int end = mp[s[i] - 'a']; //a=0 then a is 2

            int j = i;
            while(j < end){
                end = max(end, mp[s[j] - 'a']);
                j++;
            }
            result.push_back(j-i+1);
            i = j+1;
        } 
        return result;
    }
};

int main() {
    string s = "ababcbacadefegdehijhklij";  // Hardcoded input string

    Solution solution;
    vector<int> result = solution.partitionLabels(s);
    
    for (int len : result) {
        cout << len << " ";
    }
    cout << endl;

    return 0;
}
// output: 9, 7, 8

// optimal 
class Solution {
    public:
        vector<int> partitionLabels(string s) {
            int n = s.length();
             
             // to store result
             vector<int> result;
    
             // last occurance of each character
             // unordered_mao<char, int> mp;
             vector<int> mp(26, -1);
             for(int  i =0;i<n;i++){
                int index = s[i] - 'a'; // we get index
                mp[index] = i;
             } // we have all the last occurance of each char
    
            int i = 0;// pointer
            int start = 0;// pointer
            int end = 0;
            while( i < n ){
                // now i stand on first char and find end
                end = max(end, mp[s[i] - 'a']);
                if(i == end){
                    result.push_back(end-start+1);
                    start = end+1;
                }
                i++;
            } 
            return result;
        }
    };