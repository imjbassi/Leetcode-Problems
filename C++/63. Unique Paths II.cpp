class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        // Create a DP array to store the number of unique paths to each cell
        vector<vector<long long>> dp(m, vector<long long>(n, 0));
        
        // Initialize the first cell
        dp[0][0] = (obstacleGrid[0][0] == 0) ? 1 : 0;
        
        // Fill the first column
        for (int i = 1; i < m; ++i) {
            if (obstacleGrid[i][0] == 0) {
                dp[i][0] = dp[i - 1][0];
            }
        }
        
        // Fill the first row
        for (int j = 1; j < n; ++j) {
            if (obstacleGrid[0][j] == 0) {
                dp[0][j] = dp[0][j - 1];
            }
        }
        
        // Fill the rest of the DP array
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (obstacleGrid[i][j] == 0) {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        
        return dp[m - 1][n - 1];
    }
};