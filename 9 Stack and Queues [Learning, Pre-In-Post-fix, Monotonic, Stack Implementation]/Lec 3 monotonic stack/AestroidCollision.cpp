#include<bits/stdc++.h>
using namespace std;

vector < int > AestroidCollision(std::vector<int> num){
    vector<int> st;
    int  n = num.size();
    for(int i = 0;i < n-1 ;i++){
        if(num[i] > 0){
            // push if its postive integer
            st.push_back(num[i]);
        }
        else {
            while(!st.empty() && st.back() > 0 && st.back() < abs(num[i])){
                // 6 < | -7 | then pop
                // 6 < | -1 | then dont pop continue
                st.pop_back();
            }
            
            if(!st.empty() && st.back() == abs(num[i])){
                // 6 == |-6| remove +ve element we dont put the -ve
                st.pop_back();
            }    
            else if (st.empty() || st.back() < 0){
                // pushing -ve if no +ve left
                st.push_back(num[i]);
            }
        }
    }
    return st;
}

int main(){
    vector<int> num = {4 ,7,1,1,2,-3,-7,17,15,-16};
    vector<int> res = AestroidCollision(num);
    for (int i = 0; i < res.size() - 1 ; i++) {
    cout << res[i] << " ";
  }
    return 0;
}

// Output: 4 17