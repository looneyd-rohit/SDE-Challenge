// Leetcode 51

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
  void solve(int col, int n, vector<vector<char>> &board,
             vector<vector<string>> &ans) {
    if (col == n) {
      // convert to string
      vector<string> v;
      for (int i = 0; i < n; i++) {
        string temp = "";
        for (int j = 0; j < n; j++) {
          temp.push_back(board[i][j]);
        }
        v.push_back(temp);
      }
      ans.push_back(v);
      return;
    }

    // check for all the rows in the current col
    for (int row = 0; row < n; row++) {
      if (isSafeCell(row, col, n, board)) {
        board[row][col] = 'Q';
        solve(col + 1, n, board, ans);
        board[row][col] = '.';
      }
    }
  }
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<char>> board(n, vector<char>(n, '.'));
    vector<vector<string>> ans;
    solve(0, n, board, ans);
    return ans;
  }
};