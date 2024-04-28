// Leetcode 2484

// Approach 1: brute forcing count of all possible palindromes of length 5 from the given string
class Solution {
public:
    const int M = 1e9+7;
    int dp[10001][5];
    long long solve(int i, int j, int n, int m, string& s, string& t){
        if(j == m) return 1;
        if(i == n) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];

        // take
        long long take = 0;
        if(s[i]==t[j]){
            take = solve(i+1, j+1, n, m, s, t) % M;
        }

        // not_take
        long long not_take = solve(i+1, j, n, m, s, t) % M;

        return dp[i][j] = (take + not_take) % M;
    }
    int countPalindromes(string s) {
        int n = s.length();
        if(n < 5) return 0;
        long long ans = 0;
        for(int i=0; i<10; i++){
            for(int j=0; j<10; j++){
                for(int k=0; k<10; k++){
                    memset(dp, -1, sizeof(dp));
                    string t = "";
                    t.push_back((char)(i+'0'));
                    t.push_back((char)(j+'0'));
                    t.push_back((char)(k+'0'));
                    t.push_back((char)(j+'0'));
                    t.push_back((char)(i+'0'));
                    // cout<<t<<endl;
                    ans += solve(0, 0, n, 5, s, t) % M;
                    ans %= M;
                }
            }
        }
        return ans;
    }
};

// Approach 2: optimized approach (using meet in the middle)
class Solution {
public:
    const int M = 1e9+7;
    int dp1[10001][2][100];
    int dp2[10001][2][100];
    long long solve1(int i, int j, int k, int n, int m, string& s, string& t){
        if(j==-1) return 1;
        if(i < 0) return 0;
        
        if(dp1[i][j][k]!=-1) return dp1[i][j][k];

        // take
        long long take = 0;
        if(s[i]==t[j]){
            take = solve1(i-1, j-1, k, n, m, s, t) % M;
        }

        // not_take
        long long not_take = solve1(i-1, j, k, n, m, s, t) % M;

        return dp1[i][j][k] = (take + not_take) % M;
    }
    long long solve2(int i, int j, int k, int n, int m, string& s, string& t){
        if(j == m) return 1;
        if(i == n) return 0;
        
        if(dp2[i][j][k]!=-1) return dp2[i][j][k];

        // take
        long long take = 0;
        if(s[i]==t[j]){
            take = solve2(i+1, j+1, k, n, m, s, t) % M;
        }

        // not_take
        long long not_take = solve2(i+1, j, k, n, m, s, t) % M;

        return dp2[i][j][k] = (take + not_take) % M;
    }
    int countPalindromes(string s) {
        int n = s.length();
        if(n < 5) return 0;
        long long ans = 0;
        memset(dp1, -1, sizeof(dp1));
        memset(dp2, -1, sizeof(dp2));
        for(int i=2; i<n-2; i++){
            // fix i-th as the middle element
            int k = 0;
            for(int first=0; first<10; first++){
                for(int second=0; second<10; second++){
                    string left = "", right = "";
                    left.push_back((char)(first+'0'));
                    left.push_back((char)(second+'0'));

                    right.push_back((char)(second+'0'));
                    right.push_back((char)(first+'0'));

                    long long cnt_left = solve1(i-1, 1, k, n, 2, s, left);
                    long long cnt_right = solve2(i+1, 0, k, n, 2, s, right);

                    ans += (cnt_left * cnt_right) % M;
                    ans %= M;

                    k++;
                }
            }
        }
        return ans;
    }
};