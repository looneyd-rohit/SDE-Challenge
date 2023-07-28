// Leetcode 861

class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        // maximum score by flipping bits --> most likely to get answer by preserving msb
        int m = grid.size(), n = grid[0].size();
        // 1. make the msb 1 in any way possible
        for(int i=0; i<m; i++){
            if(grid[i][0]==1){
                continue;
            }else{
                // flip the current row
                for(int j=0; j<n; j++){
                    grid[i][j] = 1 - grid[i][j];
                }
            }
        }
        // 2. now, since we have msb preserved as 1, try to maximize the number of 1's
        // except the msb in each row, now we cannot flip bits of a row, since, it will
        // affect the msb so only we can flip cols
        for(int j=1; j<n; j++){
            // count no. of 1's in current column
            int count = 0;
            for(int i=0; i<m; i++){
                if(grid[i][j]==1) count++;
            }
            
            if(count < m - count){
                // zero count is more hence flip this column
                for(int i=0; i<m; i++){
                    grid[i][j] = 1 - grid[i][j];
                }
            }
        }
        // 3. calculate sum
        int sum = 0;
        for(int i=0; i<m; i++){
            int curr = 0;
            for(int j=0; j<n; j++){
                curr += grid[i][j] * (1<<(n-1-j));
            }
            sum += curr;
        }
        return sum;
    }
};