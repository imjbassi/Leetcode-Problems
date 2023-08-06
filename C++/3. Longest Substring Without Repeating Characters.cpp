class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int n = s.length();
        int maxLength = 0;
        std::unordered_map<char, int> charIndex;

        for (int end = 0, start = 0; end < n; ++end) {
            if (charIndex.find(s[end]) != charIndex.end()) {
                // Move the start pointer to exclude the first occurrence of the repeating character
                start = std::max(start, charIndex[s[end]] + 1);
            }
            charIndex[s[end]] = end; // Update the index of the current character
            maxLength = std::max(maxLength, end - start + 1);
        }

        return maxLength;
    }
};