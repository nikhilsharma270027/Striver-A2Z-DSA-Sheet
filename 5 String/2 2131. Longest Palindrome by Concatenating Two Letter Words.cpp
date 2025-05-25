2131. Longest Palindrome by Concatenating Two Letter Words

You are given an array of strings words. Each element of words consists of two lowercase English letters.
Create the longest possible palindrome by selecting some elements from words and concatenating them in any order. Each element can be selected at most once.
Return the length of the longest palindrome that you can create. If it is impossible to create any palindrome, return 0.
A palindrome is a string that reads the same forward and backward.

 
Example 1:

Input: words = ["lc","cl","gg"]
Output: 6
Explanation: One longest palindrome is "lc" + "gg" + "cl" = "lcggcl", of length 6.
Note that "clgglc" is another longest palindrome that can be created.
Example 2:

Input: words = ["ab","ty","yt","lc","cl","ab"]
Output: 8
Explanation: One longest palindrome is "ty" + "lc" + "cl" + "yt" = "tylcclyt", of length 8.
Note that "lcyttycl" is another longest palindrome that can be created.
Example 3:

Input: words = ["cc","ll","xx"]
Output: 2
Explanation: One longest palindrome is "cc", of length 2.
Note that "ll" is another longest palindrome that can be created, and so is "xx".


class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;

        int result = 0;

        for (string& word : words) { // travering on every word
            string reverseWord = word;
            swap(reverseWord[0], reverseWord[1]);

            // finding word reveseWord
            // its its one 1 we increse result by 4 =  tyyt
            // then we decrese it by 1
            // else we didnt find the reverseWord we append it;
            if (mp[reverseWord] > 0) {
                result += 4;
                mp[reverseWord]--;
            } else {
                mp[word]++;
            }
        }

        // till here i have appended and found matches

        // check equal character words and use only one
        for (auto& it : mp) {
            string word = it.first;
            int count = it.second;
            // same character words we can use only if its more than 0 right
            if (word[0] == word[1] && count > 0) {
                result += 2;
                break;
            }
        }

        return result;
    }
};