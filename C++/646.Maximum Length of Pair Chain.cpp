class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        // Sort the pairs based on the second value (right endpoint)
        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        int n = pairs.size();
        vector<int> dp(n, 1); // Initialize dp array with 1
        
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (pairs[i][0] > pairs[j][1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};