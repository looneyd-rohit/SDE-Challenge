// Q4.

class Solution {
public:
    int M, N;
    bool checkBounds(int x, int y){
        if(x<0 || y<0 || x>=M || y>=N) return false;
        return true;
    }
    bool isBlack(int x, int y, unordered_map<int, unordered_map<int, bool>>& st){
        return st[x][y];
    }
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& coordinates) {
        this->M = m; this->N = n;
        int c = coordinates.size();
        unordered_map<int, unordered_map<int, bool>> st;
        for(auto& coord: coordinates){
            st[coord[0]][coord[1]] = true;
        }
        
        vector<long long> ans(5, 0);
        for(int i=0; i<c; i++){
            int x = coordinates[i][0], y = coordinates[i][1];
            
            // (x, y) as top left corner
            if(checkBounds(x+1, y) && checkBounds(x, y+1) && checkBounds(x+1, y+1)){
                int noOfBlackBoxes = 1 + isBlack(x+1, y, st) + isBlack(x, y+1, st) + isBlack(x+1, y+1, st);
                ans[noOfBlackBoxes]++;
            }
            
            // (x, y) as top right corner
            if(checkBounds(x+1, y) && checkBounds(x, y-1) && checkBounds(x+1, y-1)){
                int noOfBlackBoxes = 1 + isBlack(x+1, y, st) + isBlack(x, y-1, st) + isBlack(x+1, y-1, st);
                ans[noOfBlackBoxes]++;
            }
            
            // (x, y) as bottom left corner
            if(checkBounds(x-1, y) && checkBounds(x, y+1) && checkBounds(x-1, y+1)){
                int noOfBlackBoxes = 1 + isBlack(x-1, y, st) + isBlack(x, y+1, st) + isBlack(x-1, y+1, st);
                ans[noOfBlackBoxes]++;
            }
            
            // (x, y) as bottom right corner
            if(checkBounds(x-1, y) && checkBounds(x, y-1) && checkBounds(x-1, y-1)){
                int noOfBlackBoxes = 1 + isBlack(x-1, y, st) + isBlack(x, y-1, st) + isBlack(x-1, y-1, st);
                ans[noOfBlackBoxes]++;
            }
        }
        int total = 0;
        for(int i=1; i<5; i++){
            ans[i] = ans[i] / i;
            total += ans[i];
        }
        ans[0] = 1LL*(m-1)*(n-1) - total;
        return ans;
    }
};