// Leetcode 1575
class Solution
{
public:
    const int M = 1e9 + 7;
    int solve(int city, vector<int> &locations, int fuel, int finish, vector<vector<int>> &dp)
    {
        // dp check
        if (dp[city][fuel] != -1)
            return dp[city][fuel];

        int ans = 0;
        // bool travelled = false;
        for (int i = 0; i < locations.size(); i++)
        {
            // visit next city if possible
            if (i != city)
            {
                if (fuel - abs(locations[i] - locations[city]) >= 0)
                {
                    ans += solve(i, locations, fuel - abs(locations[i] - locations[city]), finish, dp) % M;
                    ans = ans % M;
                }
            }
        }
        if (city == finish)
        {
            ans++;
        }
        return dp[city][fuel] = ans % M;
    }
    int countRoutes(vector<int> &locations, int start, int finish, int fuel)
    {
        int n = locations.size();
        // memoization:
        vector<vector<int>> dp(101, vector<int>(201, -1));
        return solve(start, locations, fuel, finish, dp) % M;
    }
};