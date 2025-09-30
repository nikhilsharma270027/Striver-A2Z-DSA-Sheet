/***************************************************************** C++ *****************************************************************/
//Approach (Simple simulation)
// T.C. : Constructor → O(rows), setCell / resetCell → O(1), getValue → O(L) for substr where L = length of formula
// S.C. : O(1)
class Spreadsheet {
public:
    vector<vector<int>> sheet;

    Spreadsheet(int rows) {
        sheet.assign(rows, vector<int>(26, 0));    
    }
    
    void setCell(string cell, int value) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)) - 1;

        sheet[row][col] = value;

    }
    
    void resetCell(string cell) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)) - 1;
        sheet[row][col] = 0;
    }
    
    int solve(string &s) {
        if(isdigit(s[0])) {
            return stoi(s);
        }

        int col = s[0] - 'A';
        int row = stoi(s.substr(1)) - 1;

        return sheet[row][col];
    }

    int getValue(string formula) {
        //Example : "=X+Y"
        string s = formula.substr(1); //remove =
        int plusIdx = s.find('+');

        string left = s.substr(0, plusIdx);
        string right = s.substr(plusIdx+1);


        return solve(left) + solve(right);
    }
};


// Input:
// ["Spreadsheet", "getValue", "setCell", "getValue", "setCell", "getValue", "resetCell", "getValue"]
// [[3], ["=5+7"], ["A1", 10], ["=A1+6"], ["B2", 15], ["=A1+B2"], ["A1"], ["=A1+B2"]]

// Output:
// [null, 12, null, 16, null, 25, null, 15]

// Explanation

// Spreadsheet spreadsheet = new Spreadsheet(3); // Initializes a spreadsheet with 3 rows and 26 columns
// spreadsheet.getValue("=5+7"); // returns 12 (5+7)
// spreadsheet.setCell("A1", 10); // sets A1 to 10
// spreadsheet.getValue("=A1+6"); // returns 16 (10+6)
// spreadsheet.setCell("B2", 15); // sets B2 to 15
// spreadsheet.getValue("=A1+B2"); // returns 25 (10+15)
// spreadsheet.resetCell("A1"); // resets A1 to 0
// spreadsheet.getValue("=A1+B2"); // returns 15 (0+15)