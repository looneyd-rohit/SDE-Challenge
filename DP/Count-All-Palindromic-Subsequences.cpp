// https://www.geeksforgeeks.org/problems/count-palindromic-subsequences/1

class Solution{
    public:
    const int M = 1e9+7;
    long long int  countPS(string str)
    {
        int n = str.length();
        vector<vector<long long>> dp(n, vector<long long>(n, 0));
        for(int i=0; i<n; i++) dp[i][i] = 1;
        for(int i=0, j=1; i<n && j<n; i++, j++) dp[i][j] = 2 + (str[i]==str[j]);
        for(int gap=2; gap<n; gap++){
            for(int i=0, j=gap; i<n && j<n; i++, j++){
                if(str[i]==str[j]){
                    int a = dp[i][j-1];
                    int b = dp[i+1][j];
                    dp[i][j] = ((a + b) % M + 1) % M;
                }else{
                    int a = dp[i][j-1];
                    int b = dp[i+1][j];
                    int c = dp[i+1][j-1];
                    dp[i][j] = ((a + b) % M - c + M) % M;
                }
            }
        }
        return dp[0][n-1];
    }
     
};