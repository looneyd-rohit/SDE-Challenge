// Leetcode 2812

// Approach: first do ms-bfs to find out the minimum manhattan distance -> the do binary search to find optimal distance
class Solution {
public:
    vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    bool checkBounds(int x, int y, int m, int n){
        if(x < 0 || y < 0 || x >= m || y >= n) return false;
        return true;
    }
    vector<vector<int>> compute(vector<vector<int>>& grid){
        int n = grid.size();
        vector<vector<int>> distances(n, vector<int>(n, 1e9));
        queue<tuple<int, int, int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    q.push(tuple<int, int, int>(0, i, j));
                    distances[i][j] = 0;
                }
            }
        }
        while(!q.empty()){
            auto f = q.front(); q.pop();
            int dist = get<0>(f), x = get<1>(f), y = get<2>(f);
            // visit neighbours
            for(auto& dir: directions){
                int dx = dir.first, dy = dir.second;
                int new_x = x + dx, new_y = y + dy;
                if(checkBounds(new_x, new_y, n, n)){
                    if(distances[new_x][new_y] > 1 + dist){
                        // cout<<new_x<<", "<<new_y<<endl;
                        distances[new_x][new_y] = 1 + dist;
                        q.push(tuple<int, int, int>(distances[new_x][new_y], new_x, new_y));
                    }
                }
            }
        }

        return distances;
    }
    bool isPossible(vector<vector<int>>& distances, int mid){
        int n = distances.size();
        if(distances[0][0] < mid) return false;
        queue<pair<int, int>> q;
        q.push(pair<int, int>(0, 0));
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        visited[0][0] = true;
        while(!q.empty()){
            auto f = q.front(); q.pop();
            int x = f.first, y = f.second;

            if(x == n-1 && y == n-1){
                return true;
            }

            for(auto& dir: directions){
                int dx = dir.first, dy = dir.second;
                int new_x = x + dx, new_y = y + dy;
                if(checkBounds(new_x, new_y, n, n)){
                    if(!visited[new_x][new_y]){
                        if(distances[new_x][new_y] >= mid){
                            visited[new_x][new_y] = true;
                            q.push(pair<int, int>(new_x, new_y));
                        }
                    }
                }
            }
        }
        return false;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> distances = compute(grid);
        int low = 0, high = 0;
        for(auto& row: distances){
            for(auto& e: row){
                high = max(high, e);
            }
        }
        while(low <= high){
            int mid = low + ((high - low) >> 1);
            if(isPossible(distances, mid)){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return high;
    }
};