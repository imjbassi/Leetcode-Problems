function solveSudoku(board) {
  const n = board.length;
  dfs(board, n);
}

function dfs(board, n) {
  for (let row = 0; row < n; row++) {
    for (let col = 0; col < n; col++) {
      if (board[row][col] !== '.') continue;
      
      for (let i = 1; i <= 9; i++) {
        const c = i.toString();
        
        if (isValid(board, row, col, n, c)) {
          board[row][col] = c;
          
          if (dfs(board, n)) return true;
        }
      }
      
      board[row][col] = '.';
      return false;
    }
  }
  return true;
}

function isValid(board, row, col, n, c) {
  const blockRow = Math.floor(row / 3) * 3;
  const blockCol = Math.floor(col / 3) * 3;
  
  for (let i = 0; i < n; i++) {
    if (board[row][i] === c || board[i][col] === c) return false;
    const curRow = blockRow + Math.floor(i / 3);
    const curCol = blockCol + Math.floor(i % 3);
    if (board[curRow][curCol] === c) return false;
  }
  
  return true;
}

// Test the solver
const board = [
  ["5","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
];

solveSudoku(board);

// Convert all values to strings for output
for (let i = 0; i < 9; i++) {
  for (let j = 0; j < 9; j++) {
    board[i][j] = board[i][j].toString();
  }
}

console.log(board);