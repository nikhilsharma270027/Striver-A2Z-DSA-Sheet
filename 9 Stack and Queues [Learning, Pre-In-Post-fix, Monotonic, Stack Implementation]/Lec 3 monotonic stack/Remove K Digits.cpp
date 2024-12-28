#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        int  n = num.size();
        stack<char> st;
        for(int  i = 0;i < n;i++){
            while(!st.empty() && k > 0 && (st.top() - '0') > (num[i]- '0')){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        
        while(k > 0 && !st.empty()){   // if k is still left , 
            st.pop();   // remove all back element suppose "123456" k=3 we dont take 456 
            k--;
        }
        
        
        string res = "";
        while(!st.empty()){
            res = res + st.top();
            st.pop();
        }
        while(res.size()!= 0 && res.back() == '0'){ //if we have at the back remove all ex. 123000
            res.pop_back();
        }
        reverse(res.begin(),res.end());
        if(res.empty()){
            return "0";
        }
        return res;
    }
};

int main(){
    Solution solution;
    int  k = 3;
    string num = "1432219";
    string res = solution.removeKdigits(num, k);
    cout << res;
}