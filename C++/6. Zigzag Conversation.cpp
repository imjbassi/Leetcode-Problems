class Solution {
public:
    std::string convert(std::string s, int numRows) {
        if (numRows == 1 || s.length() <= numRows)
            return s;

        std::vector<std::string> zigzagPattern(numRows, "");
        int row = 0;
        int step = 1;

        for (char c : s) {
            zigzagPattern[row] += c;

            if (row == 0)
                step = 1;
            else if (row == numRows - 1)
                step = -1;

            row += step;
        }

        std::string result;
        for (const std::string& str : zigzagPattern) {
            result += str;
        }

        return result;
    }
};