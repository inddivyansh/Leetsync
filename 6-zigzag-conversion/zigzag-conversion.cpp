class Solution {
public:
    string convert(string s, int numRows) {
        int num = s.size();
        if (numRows == 1 || num <= numRows) {
            return s;
        }

        vector<string> rows(numRows);
        int curRow = 0;
        bool goingDown = false;

        for (int i = 0; i < num; i++) {
            rows[curRow] += s[i];
            if (curRow == 0 || curRow == numRows - 1) {
                goingDown = !goingDown;
            }
            curRow += goingDown ? 1 : -1;
        }

        string result = "";
        for (int i = 0; i < numRows; i++) {
            result += rows[i];
        }

        return result;
    }
};
