#include <bits/stdc++.h>
bool solve(int i, int j, vector<vector<int>> &maze, vector<vector<int>> &ans)
{
    // boundary check
    if (i < 0 || j < 0 || i >= maze.size() || j >= maze[0].size())
        return 0;

    // if blocked
    if (maze[i][j] == 0 || maze[i][j] == -1)
        return false;

    // if destination reached
    if (i == maze.size() - 1 && j == maze[0].size() - 1)
    {
        maze[i][j] = -1;
        vector<int> temp;
        for (auto &row : maze)
        {
            for (auto &el : row)
            {
                if (el == -1)
                    temp.push_back(1);
                else
                    temp.push_back(0);
            }
        }
        ans.push_back(temp);
        maze[i][j] = 1;
        return true;
    }

    maze[i][j] = -1;

    // left
    bool left = solve(i, j - 1, maze, ans);

    // right
    bool right = solve(i, j + 1, maze, ans);

    // up
    bool up = solve(i - 1, j, maze, ans);

    // down
    bool down = solve(i + 1, j, maze, ans);

    maze[i][j] = 1;

    return (left || right || up || down);
}
vector<vector<int>> ratInAMaze(vector<vector<int>> &maze, int n)
{
    vector<vector<int>> ans;
    solve(0, 0, maze, ans);
    return ans;
}