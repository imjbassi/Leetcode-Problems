class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) {
            return result;
        }

        vector<string> mapping = {
            "abc", "def", "ghi", "jkl",
            "mno", "pqrs", "tuv", "wxyz"
        };

        backtrack(result, "", digits, 0, mapping);

        return result;
    }

    void backtrack(vector<string>& result, string current, const string& digits, int index, const vector<string>& mapping) {
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }

        string letters = mapping[digits[index] - '2'];
        for (char letter : letters) {
            backtrack(result, current + letter, digits, index + 1, mapping);
        }
    }
};