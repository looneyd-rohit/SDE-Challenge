// Leetcode 1293
// Approach: BFS with multiple different state change pattern involving visited tracking
class Solution {
public:
    bool checkBounds(int x, int y, int m, int n){
        if(x<0 || y<0 || x>=m || y>=n) return false;
        return true;
    }
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<pair<int, int>> moves = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        vector<vector<vector<int>>> visited(k+1, vector<vector<int>>(41, vector<int>(41, 0)));
        queue<tuple<int, int, int, int>> q;
        q.push(tuple<int, int, int, int>(k, 0, 0, 0));
        visited[k][0][0] = 1;
        while(!q.empty()){
            auto f = q.front(); q.pop();
            int obstacles = get<0>(f), x = get<1>(f), y = get<2>(f), dist = get<3>(f);
            if(x == m-1 && y == n-1){
                return dist;
            }
            for(auto& mm: moves){
                int dx = mm.first, dy = mm.second;
                int new_x = x + dx, new_y = y + dy, new_obstacles = obstacles;
                if(checkBounds(new_x, new_y, m, n)){
                    if(grid[new_x][new_y]==1) new_obstacles--;
                    if(new_obstacles < 0) continue;
                    if(!visited[new_obstacles][new_x][new_y]){
                        visited[new_obstacles][new_x][new_y] = 1;
                        q.push(tuple<int, int, int, int>(new_obstacles, new_x, new_y, dist+1));
                    }
                }
            }
        }
        return -1;
    }
};