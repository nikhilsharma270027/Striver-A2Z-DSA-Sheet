// Given a word pat and a text txt. Return the count of the occurrences of anagrams of the word in the text.

// Example 1:

// Input: txt = "forxxorfxdofr", pat = "for"
// Output: 3
// Explanation: for, orf and ofr appears in the txt, hence answer is 3.
// Example 2:

// Input: txt = "aabaabaa", pat = "aaba"
// Output: 4
// Explanation: aaba is present 4 times in txt.
// Constraints:
// 1 <= |pat| <= |txt| <= 105
// Both strings contain lowercase English letters.



// User function template for C++
class Solution {
  public:
    bool allZero(vector<int>& counter) {
        for(int &i : counter) {
            if(i != 0) {
                return false;
            }
        }
        return true;
    }
    int search(string &pat, string &txt) {
        // code here
        int n = txt.size();
        
        vector<int> counter(26, 0);
        // count the frequency of each chars in pat
        for(int i = 0; i < pat.length(); i++) {
            char ch = pat[i];
            counter[ch - 'a']++;
        }
        
        
        int i = 0, j = 0;
        int result = 0;
        int k = pat.size();
        while(j < n) {
            counter[txt[j] - 'a']--;
            
            if(j - i + 1 == k) {
                if(allZero(counter)) {
                    result++;
                }
                counter[txt[i] - 'a']++;
                i++;
            }
            j++;
        }
        
        return result;
    }
};