class Solution
{
public:
    int solve(int i, int j, vector<vector<int>> &dungeon, vector<vector<int>> &dp)
    {
        // boundary check
        if (i >= dungeon.size() || j >= dungeon[0].size())
        {
            return 1e9;
        }

        if (i == dungeon.size() - 1 && j == dungeon[0].size() - 1)
        {
            if (dungeon[i][j] < 0)
                return 1 - dungeon[i][j];
            return 1;
        }

        // dp check
        if (dp[i][j] != -1)
            return dp[i][j];

        int minEnergyIfGoingFromRight = solve(i, j + 1, dungeon, dp);

        int minEnergyIfGoingFromDown = solve(i + 1, j, dungeon, dp);

        return dp[i][j] = min(max(1, -dungeon[i][j] + minEnergyIfGoingFromRight), max(1, -dungeon[i][j] + minEnergyIfGoingFromDown));
    }
    int calculateMinimumHP(vector<vector<int>> &dungeon)
    {
        // assuming we write a function solve(i, j) --> which returns the minimum
        // energy required by the knight to go from (i, j) to (n-1, n-1)
        // then break the problem into smaller parts
        int m = dungeon.size(), n = dungeon[0].size();
        // memoization:
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // int ans = solve(0, 0, dungeon, dp);
        // return ans;

        // tabulation:
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 1e9));
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (i == m - 1 && j == n - 1)
                {
                    dp[i][j] = (dungeon[i][j] < 0) ? 1 - dungeon[i][j] : 1;
                }
                else
                {
                    int minEnergyIfGoingFromRight = dp[i][j + 1];

                    int minEnergyIfGoingFromDown = dp[i + 1][j];

                    dp[i][j] = min(max(1, -dungeon[i][j] + minEnergyIfGoingFromRight), max(1, -dungeon[i][j] + minEnergyIfGoingFromDown));
                }
            }
        }
        return dp[0][0];
    }
};