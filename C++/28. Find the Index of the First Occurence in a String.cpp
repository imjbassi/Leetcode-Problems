class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        int haystackLen = haystack.length();
        int needleLen = needle.length();

        for (int i = 0; i <= haystackLen - needleLen; ++i) {
            int j;
            for (j = 0; j < needleLen; ++j) {
                if (haystack[i + j] != needle[j]) {
                    break;
                }
            }
            if (j == needleLen) {
                return i;
            }
        }

        return -1;
    }
};