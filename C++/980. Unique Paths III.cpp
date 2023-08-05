class Solution {
  public: int uniquePathsIII(vector < vector < int >> & grid) {
    int startRow, startCol, emptySquares = 1; // Initialize emptySquares with 1

    // Find the starting square and count the number of empty squares
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[0].size(); ++j) {
        if (grid[i][j] == 1) {
          startRow = i;
          startCol = j;
        } else if (grid[i][j] == 0) {
          emptySquares++;
        }
      }
    }

    int paths = 0;
    dfs(grid, startRow, startCol, emptySquares, paths);
    return paths;
  }

  private: void dfs(vector < vector < int >> & grid, int row, int col, int emptySquares, int & paths) {
    if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == -1) {
      return;
    }

    if (grid[row][col] == 2) {
      if (emptySquares == 0) {
        paths++;
      }
      return;
    }

    grid[row][col] = -1; // Mark the current square as visited

    dfs(grid, row + 1, col, emptySquares - 1, paths); // Move down
    dfs(grid, row - 1, col, emptySquares - 1, paths); // Move up
    dfs(grid, row, col + 1, emptySquares - 1, paths); // Move right
    dfs(grid, row, col - 1, emptySquares - 1, paths); // Move left

    grid[row][col] = 0; // Backtrack and unmark the current square
  }
};