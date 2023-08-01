// Leetcode 2596

class Solution {
public:
    bool checkBounds(int x, int y, int m, int n){
        if(x<0 || y<0 || x>=m || y>=n) return false;
        return true;
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0]!=0) return false;
        vector<pair<int, int>> moves = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};
        int n2 = n*n;
        int x = 0, y = 0;
        for(int i=0; i<n2-1; i++){
            // take move from current x, y to new_x, new_y
            bool found = false;
            for(auto& move: moves){
                int dx = move.first, dy = move.second;
                int new_x = x + dx, new_y = y + dy;
                if(checkBounds(new_x, new_y, n, n)){
                    if(i+1 == grid[new_x][new_y]){
                        found = true;
                        x = new_x, y = new_y;
                        break;
                    }
                }
            }

            if(!found) return false;
        }
        return true;
    }
};