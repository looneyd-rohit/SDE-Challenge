// Leetcode 329

// [IMP] Approach 1: forming graph + toposort (DAG)
class Solution {
public:
    bool checkBounds(int x, int y, int m, int n){
        if(x<0 || y<0 || x>=m || y>=n) return false;
        return true;
    }
    vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        // approach: we think to give a try using a graph based approach,
        // forming a graph and finding a the longest path, like
        // in toposort of DAG's
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> indegree(m, vector<int>(n, 0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int e = matrix[i][j];
                // left
                if((j-1)>=0 && matrix[i][j-1]>e){
                    indegree[i][j-1]++;
                }
                // right
                if((j+1)<n && matrix[i][j+1]>e){
                    indegree[i][j+1]++;
                }
                // up
                if((i-1)>=0 && matrix[i-1][j]>e){
                    indegree[i-1][j]++;
                }
                // down
                if((i+1)<m && matrix[i+1][j]>e){
                    indegree[i+1][j]++;
                }
            }
        }
        // now that we have the graph, we need the maximum level of the graph 
        // we can reach starting from the indegree 0
        queue<tuple<int, int, int>> q;    // <level, node coordinates x, node coordinates y>
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(indegree[i][j]==0){
                    q.push(tuple<int, int, int>(1, i, j));
                }
            }
        }
        int ans = 1;
        while(!q.empty()){
            auto p = q.front(); q.pop();
            int dist = get<0>(p), x = get<1>(p), y = get<2>(p);
            ans = max(ans, dist);
            // visit neighbours
            for(auto d: dir){
                int dx = d.first, dy = d.second;
                int new_x = x + dx, new_y = y + dy;
                if(checkBounds(new_x, new_y, m, n)){
                    // we are not building any adj list, so we need to check on the go
                    // if current node can be next node or not
                    if(matrix[new_x][new_y] > matrix[x][y]){
                        indegree[new_x][new_y]--;
                        if(indegree[new_x][new_y]==0){
                            q.push(tuple<int, int, int>(dist+1, new_x, new_y));
                        }
                    }
                }
            }
        }
        return ans;
    }
};

// [IMP] Approach 2: using recursion + dp (try all paths)
class Solution {
public:
    vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    bool checkBounds(int x, int y, int m, int n){
        if(x<0 || y<0 || x>=m || y>=n) return false;
        return true;
    }
    int dp[200][200];
    int solve(int i, int j, int m, int n, vector<vector<int>>& matrix){
        if(dp[i][j]!=-1) return dp[i][j];

        int ans = 1;
        for(auto& d: dir){
            int di = d.first, dj = d.second;
            int new_i = i + di, new_j = j + dj;
            if(checkBounds(new_i, new_j, m, n)){
                if(matrix[new_i][new_j] > matrix[i][j]){
                    ans = max(ans, 1 + solve(new_i, new_j, m, n, matrix));
                }
            }
        }
        return dp[i][j] = ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        // approach: dfs + memoization
        int m = matrix.size(), n = matrix[0].size();
        int ans = 1;
        memset(dp, -1, sizeof(dp));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                ans = max(ans, solve(i, j, m, n, matrix));
            }
        }
        return ans;
    }
};