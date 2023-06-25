// Leetcode 2745
class Solution
{
public:
    int dp[51][51][51][4] = {0};
    int solve(vector<string> &words, int x, int y, int z, int prev)
    {
        // dp check
        if (dp[x][y][z][prev] != 0)
            return dp[x][y][z][prev];

        // adding one x
        int xx = 0;
        if (prev == 0 || prev != 1)
        {
            if (x > 0)
            {
                xx = 2 + solve(words, x - 1, y, z, 1);
            }
        }

        // adding one y
        int yy = 0;
        if (prev == 0 || (prev != 2 && prev != 3))
        {
            if (y > 0)
            {
                yy = 2 + solve(words, x, y - 1, z, 2);
            }
        }

        // adding one z
        int zz = 0;
        if (prev == 0 || prev != 1)
        {
            if (z > 0)
            {
                zz = 2 + solve(words, x, y, z - 1, 3);
            }
        }

        return dp[x][y][z][prev] = max({xx, yy, zz});
    }
    int longestString(int x, int y, int z)
    {
        vector<string> words;
        words.push_back("AA");
        words.push_back("BB");
        words.push_back("AB");
        return solve(words, x, y, z, 0);
    }
};