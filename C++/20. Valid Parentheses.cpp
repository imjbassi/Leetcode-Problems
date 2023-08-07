class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> brackets;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                brackets.push(c);
            } else if (c == ')' || c == '}' || c == ']') {
                if (brackets.empty()) {
                    return false;
                } else if ((c == ')' && brackets.top() == '(') ||
                           (c == '}' && brackets.top() == '{') ||
                           (c == ']' && brackets.top() == '[')) {
                    brackets.pop();
                } else {
                    return false;
                }
            }
        }
        return brackets.empty();
    }
};