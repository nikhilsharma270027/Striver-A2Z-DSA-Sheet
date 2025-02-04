#include<bits/stdc++.h>
using namespace std;

bool checkPrime(int n){
    int cnt = 0;
    for(int i = 1; i <= sqrt(n); i++){
        if(n % i == 0){
            cnt = cnt + 1;
            if(n / i != i){
                cnt = cnt + 1;
            }
        }
    }
    if(cnt == 2){
        return true;
    } else {
        return false; 
    }
}

vector<int> GetPrimeFactors(int N) {
    vector<int> list;
    for(int i = 1; i <= sqrt(N); i++) {
        if(N % i == 0) { 
            if(checkPrime(i)) list.push_back(i);  // Add factor 'i' if it's prime

            if(N / i != 1) {
                if(checkPrime(N / i)) list.push_back(N / i);  // Add corresponding factor if it's prime
            }
        }
    }
    return list;
}

//School method
vector<int> GetPrimeFactorsSchool(int N) {
    vector<int> list;
    for(int i = 2; i <= N; i++) {
        if(N % i == 0) {
            list.push_back(i);
        }

        while(N % i == 0 ) {
            N  = N / i;  
        }
    }
    return list;
}

vector<int> OPtimal(int N) {
    vector<int> list;
    for(int i = 2; i <= sqrt(N); i++) {
        if(N % i == 0) {
            list.push_back(i);
        }

        while(N % i == 0 ) {
            N  = N / i;
        }
    }
    if(N != 0) list.push_back(N); //we put the last prime like 13 cant be divided so put directly
    return list;
}    


int main() {
    int N = 780;
    vector<int> result = GetPrimeFactors(N);
    for(int i = 0; i< result.size();i++){
        cout << result[i] << " ";
    }
    cout << endl;
    vector<int> result1 = GetPrimeFactorsSchool(N);
    for(int i = 0; i< result.size();i++){
        cout << result1[i] << " ";
    }
    cout << endl;
    vector<int> result2 = OPtimal(N);
    for(int i = 0; i< result.size();i++){
        cout << result2[i] << " ";
    }
}

// o/p: 2, 3, 5, 13