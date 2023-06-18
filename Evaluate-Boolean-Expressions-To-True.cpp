int solve(int i, int j, int isTrue, int mod, string &expression, vector<vector<vector<int>>> &dp)
{
    // base cases
    if (i > j)
        return 0;
    if (i == j)
    {
        // only 'T' or 'F' remaining
        if (isTrue == 1)
        {
            // we need true
            return expression[i] == 'T';
        }
        return expression[i] == 'F';
    }

    // dp check
    if (dp[i][j][isTrue] != -1)
        return dp[i][j][isTrue];

    // partition the epxression and evaluate small parts
    int ansTrue = 0;
    int ansFalse = 0;
    for (int k = i + 1; k <= j; k += 2)
    {
        int leftTrue = solve(i, k - 1, 1, mod, expression, dp);
        int leftFalse = solve(i, k - 1, 0, mod, expression, dp);
        int rightTrue = solve(k + 1, j, 1, mod, expression, dp);
        int rightFalse = solve(k + 1, j, 0, mod, expression, dp);

        // check the current operator and make computations
        char op = expression[k];
        if (op == '|')
        {
            int a = (leftTrue * rightTrue) % mod;
            int b = (leftTrue * rightFalse) % mod;
            int c = (leftFalse * rightTrue) % mod;
            ansTrue += (((a + b) % mod) + c) % mod;

            int d = (leftFalse * rightFalse) % mod;
            ansFalse += d;
        }
        else if (op == '&')
        {
            int a = (leftTrue * rightTrue) % mod;
            ansTrue += a;

            int b = (leftFalse * rightFalse) % mod;
            int c = (leftTrue * rightFalse) % mod;
            int d = (leftFalse * rightTrue) % mod;
            ansFalse += (((b + c) % mod) + d) % mod;
        }
        else if (op == '^')
        {
            int a = (leftTrue * rightFalse) % mod;
            int b = (leftFalse * rightTrue) % mod;
            ansTrue += ((a + b) % mod);

            int c = (leftTrue * rightTrue) % mod;
            int d = (leftFalse * rightFalse) % mod;
            ansFalse += ((c + d) % mod);
        }
    }
    if (isTrue == 1)
        return dp[i][j][isTrue] = ansTrue % mod;
    return dp[i][j][isTrue] = ansFalse % mod;
}
int Solution::cnttrue(string A)
{
    int n = A.size();
    int mod = 1e3 + 3;
    // memoization:
    // vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
    // return solve(0, n-1, 1, mod, A, dp) % mod;

    // tabulation:
    string expression = A;
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, 0)));
    for (int i = 0; i < n; i++)
    {
        dp[i][i][1] = (expression[i] == 'T') ? 1 : 0;
        dp[i][i][0] = (expression[i] == 'F') ? 1 : 0;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        // j always lies to the right of j, so j=i+1 atleast (base case j=i handled
        // already)
        for (int j = i + 1; j <= n - 1; j++)
        {
            for (int isTrue = 0; isTrue <= 1; isTrue++)
            {
                // partition the epxression and evaluate small parts
                int ansTrue = 0;
                int ansFalse = 0;
                for (int k = i + 1; k < j; k += 2)
                {
                    int leftTrue = dp[i][k - 1][1];
                    int leftFalse = dp[i][k - 1][0];
                    int rightTrue = dp[k + 1][j][1];
                    int rightFalse = dp[k + 1][j][0];

                    // check the current operator and make computations
                    char op = expression[k];
                    if (op == '|')
                    {
                        int a = (leftTrue * rightTrue) % mod;
                        int b = (leftTrue * rightFalse) % mod;
                        int c = (leftFalse * rightTrue) % mod;
                        ansTrue += (((a + b) % mod) + c) % mod;

                        int d = (leftFalse * rightFalse) % mod;
                        ansFalse += d;
                    }
                    else if (op == '&')
                    {
                        int a = (leftTrue * rightTrue) % mod;
                        ansTrue += a;

                        int b = (leftFalse * rightFalse) % mod;
                        int c = (leftTrue * rightFalse) % mod;
                        int d = (leftFalse * rightTrue) % mod;
                        ansFalse += (((b + c) % mod) + d) % mod;
                    }
                    else if (op == '^')
                    {
                        int a = (leftTrue * rightFalse) % mod;
                        int b = (leftFalse * rightTrue) % mod;
                        ansTrue += ((a + b) % mod);

                        int c = (leftTrue * rightTrue) % mod;
                        int d = (leftFalse * rightFalse) % mod;
                        ansFalse += ((c + d) % mod);
                    }
                }
                if (isTrue == 1)
                    dp[i][j][isTrue] = ansTrue % mod;
                else
                    dp[i][j][isTrue] = ansFalse % mod;
            }
        }
    }
    return dp[0][n - 1][1] % mod;
}
