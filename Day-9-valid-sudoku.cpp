bool isPossible(int i, int j, int digit, int matrix[9][9])
{
    // check ith row
    for (int col = 0; col < 9; col++)
    {
        if (j != col && matrix[i][col] == digit)
        {
            return false;
        }
    }
    // check jth col
    for (int row = 0; row < 9; row++)
    {
        if (row != i && matrix[row][j] == digit)
        {
            return false;
        }
    }
    // check 3X3 box
    int start_i = (i / 3) * 3;
    int start_j = (j / 3) * 3;
    for (int dx = 0; dx < 3; dx++)
    {
        for (int dy = 0; dy < 3; dy++)
        {
            int cur_i = start_i + dx;
            int cur_j = start_j + dy;
            if (i != cur_i && j != cur_j && matrix[cur_i][cur_j] == digit)
            {
                return false;
            }
        }
    }
    return true;
}
int solve(int i, int j, int matrix[9][9])
{
    // base case
    if (j == 9)
    {
        if (i == 8)
            return true;
        j = 0;
        i = i + 1;
    }

    if (matrix[i][j] != 0)
        return solve(i, j + 1, matrix);

    for (int digit = 1; digit <= 9; digit++)
    {
        if (isPossible(i, j, digit, matrix))
        {
            matrix[i][j] = digit;
            if (solve(i, j + 1, matrix))
                return true;
            matrix[i][j] = 0;
        }
    }
    return false;
}
bool isItSudoku(int matrix[9][9])
{
    return solve(0, 0, matrix);
}
