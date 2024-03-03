// Leetcode 3071

class Solution {
public:
  int minimumOperationsToWriteY(vector<vector<int>> &grid) {
    int n = grid.size();
    // count 0, 1, 2 on grid
    int zeros = 0, ones = 0, twos = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 0)
          zeros++;
        else if (grid[i][j] == 1)
          ones++;
        else
          twos++;
      }
    }
    // count 0, 1, 2 on the Y
    int zeros_y = 0, ones_y = 0, twos_y = 0;
    // diagonals
    for (int i = 0; i < n / 2; i++) {
      // left diagonal
      if (grid[i][i] == 0)
        zeros_y++;
      else if (grid[i][i] == 1)
        ones_y++;
      else
        twos_y++;
      // right diagonal
      if (grid[i][n - 1 - i] == 0)
        zeros_y++;
      else if (grid[i][n - 1 - i] == 1)
        ones_y++;
      else
        twos_y++;
    }
    // vertical
    for (int i = n / 2; i < n; i++) {
      if (grid[i][n / 2] == 0)
        zeros_y++;
      else if (grid[i][n / 2] == 1)
        ones_y++;
      else
        twos_y++;
    }
    zeros -= zeros_y;
    ones -= ones_y;
    twos -= twos_y;

    // 0 on Y and 1 on others
    int ops1 = ones_y + twos_y + zeros + twos;

    // 0 on Y and 2 on others
    int ops2 = ones_y + twos_y + zeros + ones;

    // 1 on Y and 0 on others
    int ops3 = zeros_y + twos_y + ones + twos;

    // 1 on Y and 2 on others
    int ops4 = zeros_y + twos_y + zeros + ones;

    // 2 on Y and 0 on others
    int ops5 = zeros_y + ones_y + ones + twos;

    // 2 on Y and 1 on others
    int ops6 = zeros_y + ones_y + zeros + twos;

    return min({ops1, ops2, ops3, ops4, ops5, ops6});
  }
};