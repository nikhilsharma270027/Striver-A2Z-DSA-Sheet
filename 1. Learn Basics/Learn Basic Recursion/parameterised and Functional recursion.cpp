#include<bits/stdc++.h>
using namespace std;

// Parameterised Recursion

void para(int i,int sum){
    if ( i<1 ){
        cout << sum ;
        return;
    }
    //    3-1  0 + 3
    para( i-1, sum+i ); //para(3-1,0+3) -> para(2-1,3+2) -> para(1-1,5+1) -> para(0,6) return
}

int main(){
    
    int n = 3;
    para(n, 0);

}

#include<bits/stdc++.h>
using namespace std;

// Functional Recursion

int func(int n){
    if ( n == 0 ){
        return 0;
    }
    //     3 + func(3-1)
    return n + func(n-1); //func(2) -> func(1) -> func(0) return
        // 3 + 3         <- 2+1       <-1+0    <- return func(0)
}

int main(){
    
    int n = 3;
    func(n);
    int print = func(n);
    cout << print ;
    
    
}