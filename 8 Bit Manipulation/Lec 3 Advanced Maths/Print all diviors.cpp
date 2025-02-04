#include<bits/stdc++.h>
using namespace std;

vector<int> DivisorList(int N) {
    vector<int> list;
    for(int i = 1;i<= N;i++) {
        if(N % i == 0) {
            list.push_back(i);
        }
    }
    return list;
}

vector<int> DivisorList1(int N) {
    vector<int> list;
    for(int i = 1;i*i <= N;i++) {
        if(N % i == 0) {
            list.push_back(i);
        // cout << i << endl;
        if(i != N / i) {
            list.push_back(N/i);
        }
        }
    }
    return list;
}


int main() {
    int N = 36;
    vector<int> result = DivisorList(N);
    sort(result.begin(), result.end());
    for(int i = 0; i< result.size();++i){
        cout << result[i] << " ";
        
    }
    cout << endl;
    vector<int> result1 = DivisorList1(N);
    sort(result1.begin(), result1.end());
    for(int i = 0; i< result1.size();i++){
        cout << result1[i] << " ";
    }
}

// 1 2 3 4 6 9 12 18 36 
// 1 2 3 4 6 9 12 18 36 