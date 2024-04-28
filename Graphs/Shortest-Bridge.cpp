// Leetcode 934

// [IMP] Approach: bfs/dfs for coloring + bfs for shortest path
class Solution {
public:
    vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    bool checkBounds(int x, int y, int m, int n){
        if(x<0 || y<0 || x>=m || y>=n) return false;
        return true;
    }
    void markIsland(vector<vector<int>>& grid, int i, int j){
        int n = grid.size();
        queue<pair<int, int>> q;
        q.push({i, j});
        while(!q.empty()){
            auto f = q.front(); q.pop();
            int x = f.first, y = f.second;
            grid[x][y] = 2;
            // visit neighbours
            for(auto& d: dir){
                int dx = d.first, dy = d.second;
                int new_x = x + dx, new_y = y + dy;
                if(checkBounds(new_x, new_y, n, n)){
                    if(grid[new_x][new_y]==1){
                        grid[new_x][new_y]=2;
                        q.push({new_x, new_y});
                    }
                }
            }
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        // approach: from each point in island 1 find the shortest path to island 2
        int n = grid.size();
        // mark all points in island 1 by same colour
        for(int i=0; i<n; i++){
            bool flag = false;
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    markIsland(grid, i, j);
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }
        queue<tuple<int, int, int>> points;
        // optimization: only keep the boundary cells marked with 2
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==2){
                    if((i+1<n && grid[i+1][j]!=2) || (j+1<n && grid[i][j+1]!=2) || (i-1>=0 && grid[i-1][j]!=2) || (j-1>=0 && grid[i][j-1]!=2)){
                        points.push(tuple<int, int, int>(0, i, j));
                    }
                }
            }
        }
        // int dist = 0;
        while(!points.empty()){
            // modified bfs
            auto p = points.front(); points.pop();
            int dist = get<0>(p), x = get<1>(p), y = get<2>(p);
            grid[x][y] = -1;
            for(auto& d: dir){
                int dx = d.first, dy = d.second;
                int new_x = x + dx, new_y = y + dy;
                if(checkBounds(new_x, new_y, n, n)){
                    if(grid[new_x][new_y]==1){
                        return dist;
                    }else if(grid[new_x][new_y]==0){
                        // new concept: mark as and when pushed to prevent
                        // duplicate addition to queue
                        grid[new_x][new_y] = -1;
                        points.push(tuple<int, int, int>(dist+1, new_x, new_y));
                    }
                }
            }
        }
        return 0;
    }
};