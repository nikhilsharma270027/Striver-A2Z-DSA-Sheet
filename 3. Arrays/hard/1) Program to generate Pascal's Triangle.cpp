// Variation 1
#include <bits/stdc++.h>
using namespace std;

int nCr(int n, int r) {
    long long res = 1;

    // calculating nCr:
    for (int i = 0; i < r; i++) {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}

int pascalTriangle(int r, int c) {
    int element = nCr(r - 1, c - 1);
    return element;
}

int main() {
    int r = 5; // row number
    int c = 3; // col number
    int element = pascalTriangle(r, c);
    cout << "The element at position (r,c) is: "
            << element << "n";
    return 0;
}
                
// Output: The element at position (r,c) is: 6

// Complexity Analysis
// Time Complexity: O(c), where c = given column number.
// Reason: We are running a loop for r times, where r is c-1.

// Space Complexity: O(1) as we are not using any extra space.

// Variation 2 - type 1
#include <bits/stdc++.h>
using namespace std;
        //  4      0
int nCr(int n, int r) {
    long long res = 1;   //here the condition i<r i.e 0<0 is false so first number is res  = 1

    // calculating nCr: r=0
    for (int i = 0; i < r; i++) {//   4,0         4,1         4,2           4,3
        res = res * (n - i);    //1=1*4-0=4  // 4=4*4-1=12 // 12=12*4-2=24 //4=4*4-3=4
        res = res / (i + 1);   // 4=4/0+1=4  // 12=12/1+1=6// 24=12/2+1=4   // 4=4/3+1=1
    }
    return res;
}
                      //5
void pascalTriangle(int n) {
    // printing the entire row n:
    for (int c = 1; c <= n; c++) {
        cout << nCr(n - 1, c - 1) << " "; 
    }              //4     //0
    cout << "n";
}

int main() {
    int n = 5;
    pascalTriangle(n); // n =5
    return 0;
}
// Output: 1 4 6 4 1

// Complexity Analysis
// Time Complexity: O(n*r), where n is the given row number, and r is the column index which can vary from 0 to n-1.
// Reason: We are calculating the element for each column. Now, there are total n columns, and for each column, the calculation of the element takes O(r) time where r is the column index.

// Space Complexity: O(1) as we are not using any extra space.

// Variation 2- type 2 Optimal
// Current element = prevElement * (rowNumber - colIndex) / colIndex
#include <bits/stdc++.h>
using namespace std;

void pascalTriangle(int n) {
    long long ans = 1;
    cout << ans << " "; // printing 1st element

    //Printing the rest of the part:
    for (int i = 1; i < n; i++) {
        ans = ans * (n - i);
        ans = ans / i;
        cout << ans << " ";
    }
    cout << endl;
}

int main() {
    int n = 5;
    pascalTriangle(n);
    return 0;
}
// Output: 1 4 6 4 1

// Complexity Analysis
// Time Complexity: O(N) where N = given row number. Here we are using only a single loop.

// Space Complexity: O(1) as we not using any extra space.

// Variation 3 - type 1
#include <bits/stdc++.h>
using namespace std;

int nCr(int n, int r) {
    long long res = 1;

    // calculating nCr:
    for (int i = 0; i < r; i++) {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return (int)(res);
}

vector<vector<int>> pascalTriangle1(int n) {
    vector<vector<int>> ans;

    //Store the entire pascal's triangle:
    for (int row = 1; row <= n; row++) {
        vector<int> tempLst; // temporary list
        for (int col = 1; col <= row; col++) {
            tempLst.push_back(nCr(row - 1, col - 1));
        }
        ans.push_back(tempLst);
    }
    return ans;
}

int main()
{
    int n = 5;
    vector<vector<int>> ans = pascalTriangle1(n);
    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "n";
    }
    return 0;
}
// Output:
// 1
// 1 1
// 1 2 1
// 1 3 3 1
// 1 4 6 4 1
// Complexity Analysis
// Time Complexity: O(n*n*r) ~ O(n3), where n = number of rows, and r = column index.
// Reason: The row loop will run for approximately n times. And generating a row using the naive approach of variation 2 takes O(n*r) time complexity.
// Space Complexity: In this case, we are only using space to store the answer. That is why space complexity can be still considered as O(1).

// Variation 3 _ type 2 optimal
#include <bits/stdc++.h>
using namespace std;

vector<int> generateRow(int row) {
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1); //inserting the 1st element

    //calculate the rest of the elements:
    for (int col = 1; col < row; col++) {
        ans = ans * (row - col);
        ans = ans / col;
        ansRow.push_back(ans);
    }
    return ansRow;
}

vector<vector<int>> pascalTriangle2(int n) {
    vector<vector<int>> ans;

    //store the entire pascal's triangle:
    for (int row = 1; row <= n; row++) {
        ans.push_back(generateRow(row));
    }
    return ans;
}

int main()
{
    int n = 5;
    vector<vector<int>> ans = pascalTriangle2(n);
    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "n";
    }
    return 0;
}
// Output:
// 1
// 1 1
// 1 2 1
// 1 3 3 1
// 1 4 6 4 1
// Complexity Analysis
// Time Complexity: O(n2), where n = number of rows(given).
// Reason: We are generating a row for each single row. The number of rows is n. And generating an entire row takes O(n) time complexity.

// Space Complexity: In this case, we are only using space to store the answer. That is why space complexity can still be considered as O(1).