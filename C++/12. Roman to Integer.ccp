class Solution {
public:
    string intToRoman(int num) {
        vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> symbols = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        
        string roman_numeral = "";
        int i = 0;
        
        while (num > 0) {
            if (num >= values[i]) {
                roman_numeral += symbols[i];
                num -= values[i];
            } else {
                i++;
            }
        }
        
        return roman_numeral;
    }
};