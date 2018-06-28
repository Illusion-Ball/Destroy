class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        vector<string> zigZag(min(numRows, (int) s.length()));
        int row = 0;
        bool goingDown = true;
        for (char ch : s) {
            if (row == 0) {
                goingDown = true;
            } else if (row == numRows - 1) {
                goingDown = false;
            }
            zigZag[row] += ch;
            if (goingDown) {
                row++;
            } else {
                row--;
            }
        }
        string zigZagString;
        for (string &str : zigZag) {
            zigZagString += str;
        }
        return zigZagString;
    }
};
