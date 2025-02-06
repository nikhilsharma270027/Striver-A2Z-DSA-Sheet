#include<bits/stdc++.h>
using namespace std;

bool LemonadeChange(vector<int> change) {
    int five = 0;
    int ten = 0;
    for(int  i = 0;i< change.size();i++) {
        if(change[i] == 5) {
            five += 1;
        }
        else if(change[i] == 10) {
            if(five) {
                five -= 1;
                ten += 1;
            }
            else return false;
        }
        else {
            if(ten && five) {
                five -= 1;
                ten -= 1;
            }
            else if (five >= 3) {
                five -= 3;
            }
            else return false;
        }
    }
    return true;
}

int main() {
    vector<int> cust = {5, 5,5 , 10, 20};
    bool result = LemonadeChange(cust);
    cout << result ;
}