// Leetcode 1970
// Approach: MSBFS + Binary Search (straight forward)
class Solution {
public:
    bool checkBounds(int x, int y, int m, int n){
        if(x<0 || y<0 || x>=m || y>=n) return false;
        return true;
    }
    bool msBFS(int row, int col, vector<vector<int>>& cells, int lastDay){
        // build the grid till the lastDay
        vector<vector<int>> grid(row, vector<int>(col, 0));
        for(int i=0; i<=lastDay; i++) grid[cells[i][0]-1][cells[i][1]-1] = 1;
        // now traverse
        queue<pair<int, int>> q;
        vector<pair<int, int>> moves = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        for(int j=0; j<col; j++){
            if(grid[0][j]==0){
                q.push({0, j});
                grid[0][j] = -1;
            }
        }
        while(!q.empty()){
            auto f = q.front(); q.pop();
            int x = f.first, y = f.second;
            if(x == row-1) return true;
            for(auto& mm: moves){
                int dx = mm.first, dy = mm.second;
                int new_x = x + dx, new_y = y + dy;
                if(checkBounds(new_x, new_y, row, col)){
                    if(grid[new_x][new_y]==0){
                        grid[new_x][new_y] = -1;
                        q.push({new_x, new_y});
                    }
                }
            }
        }
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int n = cells.size();
        vector<vector<int>> grid(row, vector<int>(col, 0));
        int low = 0, high = n-1;
        while(low <= high){
            int mid = low + ((high-low) >> 1);
            int lastDay = mid;
            bool flag = msBFS(row, col, cells, lastDay);
            if(flag){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return high + 1;
    }
};