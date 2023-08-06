class Solution {
public:
    int romanToInt(std::string s) {
        std::unordered_map<char, int> romanValues = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int result = 0;
        int n = s.length();

        for (int i = 0; i < n; ++i) {
            int value = romanValues[s[i]];

            if (i < n - 1 && value < romanValues[s[i + 1]]) {
                result -= value;
            } else {
                result += value;
            }
        }

        return result;
    }
};