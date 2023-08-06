class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        if (strs.empty())
            return "";

        std::string commonPrefix = strs[0];
        int n = strs.size();

        for (int i = 1; i < n; ++i) {
            int j = 0;
            while (j < commonPrefix.length() && j < strs[i].length() && commonPrefix[j] == strs[i][j]) {
                ++j;
            }
            commonPrefix = commonPrefix.substr(0, j);

            if (commonPrefix.empty())
                break;
        }

        return commonPrefix;
    }
};