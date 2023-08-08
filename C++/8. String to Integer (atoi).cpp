class Solution {
public:
    int myAtoi(std::string s) {
        int i = 0;
        int n = s.length();

        // Skip leading whitespaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // Check if the number is positive or negative
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Read the digits
        int result = 0;
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            // Check for integer overflow
            if (result > (INT_MAX - digit) / 10) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            result = result * 10 + digit;
            i++;
        }

        return result * sign;
    }
};
