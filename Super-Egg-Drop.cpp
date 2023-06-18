class Solution
{
public:
    int solve(int eggs, int floors, vector<vector<int>> &dp)
    {
        // base cases
        if (eggs == 1)
            return floors;
        if (floors == 0)
            return 0;
        if (floors == 1)
            return 1;

        // dp check
        if (dp[eggs][floors] != -1)
            return dp[eggs][floors];

        // try out for all floors --> since we need to try out for all
        // floors, we can apply binary search on the floor search space instead of going through
        // each floor
        int ans = 1e9;
        int low = 1, high = floors;
        while (low <= high)
        {
            int mid = low + ((high - low) >> 1);
            int f = mid;

            // assuming egg breaks at f --> check for f-1 floors below f
            int breaks = solve(eggs - 1, f - 1, dp);

            // assuming egg does not break at f --> check for floors-f floors above f
            int notBreaks = solve(eggs, floors - f, dp);

            // take the worst of luck
            // adding 1, because we tried one operation for current floor
            int worst = 1 + max(breaks, notBreaks);

            // take best of choices
            ans = min(ans, worst);

            // update search space
            if (breaks > notBreaks)
            {
                // no of attempts in breaks is higher than in notBreaks, and we are focussed
                // on taking the min of worst, so we go towards the worst
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return dp[eggs][floors] = ans;
    }
    int superEggDrop(int k, int n)
    {
        // memoization:
        // vector<vector<int>> dp(k+1, vector<int>(n+1, -1));
        // return solve(k, n, dp);

        // tabulation:
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));
        for (int floors = 0; floors <= n; floors++)
            dp[1][floors] = floors;
        for (int eggs = 2; eggs <= k; eggs++)
        {
            dp[eggs][0] = 0;
            dp[eggs][1] = 1;
        }
        for (int eggs = 2; eggs <= k; eggs++)
        {
            for (int floors = 2; floors <= n; floors++)
            {
                // try out for all floors --> since we need to try out for all
                // floors, we can apply binary search on the floor search space instead of going through
                // each floor
                int ans = 1e9;
                int low = 1, high = floors;
                while (low <= high)
                {
                    int mid = low + ((high - low) >> 1);
                    int f = mid;

                    // assuming egg breaks at f --> check for f-1 floors below f
                    int breaks = dp[eggs - 1][f - 1];

                    // assuming egg does not break at f --> check for floors-f floors above f
                    int notBreaks = dp[eggs][floors - f];

                    // take the worst of luck
                    // adding 1, because we tried one operation for current floor
                    int worst = 1 + max(breaks, notBreaks);

                    // take best of choices
                    ans = min(ans, worst);

                    // update search space
                    if (breaks > notBreaks)
                    {
                        // no of attempts in breaks is higher than in notBreaks, and we are focussed
                        // on taking the min of worst, so we go towards the worst
                        high = mid - 1;
                    }
                    else
                    {
                        low = mid + 1;
                    }
                }
                dp[eggs][floors] = ans;
            }
        }
        return dp[k][n];
    }
};