// Leetcode 130

class Solution {
public:
  void mark(int i, int j, int m, int n, vector<vector<char>> &board) {
    if (i < 0 || j < 0 || i >= m || j >= n)
      return;
    if (board[i][j] == 'Y' || board[i][j] == 'X')
      return;
    board[i][j] = 'Y';
    mark(i - 1, j, m, n, board);
    mark(i + 1, j, m, n, board);
    mark(i, j - 1, m, n, board);
    mark(i, j + 1, m, n, board);
  }
  void solve(vector<vector<char>> &board) {
    int m = board.size(), n = board[0].size();
    for (int i = 0; i < m; i++) {
      mark(i, 0, m, n, board);
      mark(i, n - 1, m, n, board);
    }
    for (int j = 0; j < n; j++) {
      mark(0, j, m, n, board);
      mark(m - 1, j, m, n, board);
    }
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (board[i][j] == 'O') {
          board[i][j] = 'X';
        }
        if (board[i][j] == 'Y') {
          board[i][j] = 'O';
        }
      }
    }
  }
};