class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;

        std::string numStr = std::to_string(x);
        int left = 0;
        int right = numStr.length() - 1;

        while (left < right) {
            if (numStr[left] != numStr[right])
                return false;
            ++left;
            --right;
        }

        return true;
    }
};