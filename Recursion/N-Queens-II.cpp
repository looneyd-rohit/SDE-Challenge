// Leetcode 52

class Solution {
public:
  bool isSafeCell(int row, int col, int n, vector<vector<char>> &board) {
    // check horizontally backwards
    for (int j = 0; j < col; j++) {
      if (board[row][j] == 'Q')
        return false;
    }
    // check vertically --> not required

    // check diagonally upwards and backwards
    int r = row - 1, c = col - 1;
    while (r >= 0 && c >= 0) {
      if (board[r][c] == 'Q')
        return false;
      r--;
      c--;
    }
    // check diagonally downwards and backwards
    r = row + 1, c = col - 1;
    while (r < n && c >= 0) {
      if (board[r][c] == 'Q')
        return false;
      r++;
      c--;
    }

    return true;
  }
  int solve(int col, int n, vector<vector<char>> &board) {
    if (col == n) {
      // convert to string
      return 1;
    }

    // check for all the rows in the current col
    int ans = 0;
    for (int row = 0; row < n; row++) {
      if (isSafeCell(row, col, n, board)) {
        board[row][col] = 'Q';
        ans += solve(col + 1, n, board);
        board[row][col] = '.';
      }
    }
    return ans;
  }
  int totalNQueens(int n) {
    vector<vector<char>> board(n, vector<char>(n, '.'));
    return solve(0, n, board);
  }
};