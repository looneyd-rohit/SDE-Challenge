bool isPossible(int row, int col, int n, vector<vector<int>> &grid)
{
    // check current row, leftwards horizontally
    for (int j = 0; j < col; j++)
    {
        if (grid[row][j])
        {
            return false;
        }
    }

    // check current

    // check diagonal left upwards
    int i = row - 1, j = col - 1;
    while (i >= 0 && j >= 0)
    {
        if (grid[i][j])
        {
            return false;
        }
        i--;
        j--;
    }

    // check diagonal left downwards
    i = row + 1, j = col - 1;
    while (i < n && j >= 0)
    {
        if (grid[i][j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}
void solve(int col, int n, vector<vector<int>> &grid, vector<vector<int>> &ans)
{
    // base case
    if (col == grid.size())
    {
        // we have reached the end, filling the queens in their locations
        vector<int> temp;
        for (auto &row : grid)
        {
            for (auto &el : row)
            {
                temp.push_back(el);
            }
        }
        ans.push_back(temp);
        return;
    }

    // check out all possibilities for the current col
    for (int row = 0; row < n; row++)
    {
        if (isPossible(row, col, n, grid))
        {
            grid[row][col] = 1;
            solve(col + 1, n, grid, ans);
            grid[row][col] = 0;
        }
    }
}
vector<vector<int>> solveNQueens(int n)
{
    vector<vector<int>> grid(n, vector<int>(n, 0));
    vector<vector<int>> ans;
    solve(0, n, grid, ans);
    return ans;
}