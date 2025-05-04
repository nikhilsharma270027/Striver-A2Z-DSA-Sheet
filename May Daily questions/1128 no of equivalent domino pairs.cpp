// Brute force approach
class Solution {
    public:
        int numEquivDominoPairs(vector<vector<int>>& dominoes) {
            int count = 0;
            for (int i = 0 ; i < dominoes.size() ; i++) {
                for (int j = i + 1 ; j < dominoes.size() ; j++) {
                    int a = dominoes[i][0], b = dominoes[i][1];
                    int c = dominoes[j][0], d = dominoes[j][1];
                    if ((a == c && b == d) || (a == d && b == c))
                    ++count;
                }
            }
            return count;
        }
    };


// Better Approach
class Solution {
    public:
        int numEquivDominoPairs(vector<vector<int>>& dominoes) {
    
            map<pair<int, int>, int> mpp;
    
            for (auto& d : dominoes) {
                if (d[0] > d[1]) {
                    // swap if a is greater than b || (2, 1) == (1, 2)
                    swap(d[0], d[1]);
                }
    
                mpp[{d[0], d[1]}]++;
            }
    
            int result = 0;
    
            for (auto& it : mpp) {
                int freq = it.second;
    
                result += freq * (freq - 1) / 2;
            }
            return result;
        }
    };


// Optimal Approach
class Solution {
    public:
        int numEquivDominoPairs(vector<vector<int>>& dominoes) {
            vector<int> vec(100); // vec size of 100
    
            int result =0;
    
            for(auto&d : dominoes) {
                if(d[0] > d[1]) {
                    swap(d[0], d[1]);
                }
                // inceaseing a specific number of num to 
                int num = d[0] * 10 + d[1]; // (a, b) --> a*10 + b
    
                result += vec[num];
    
                vec[num]++;
            }
            
            return result;
        }
    };