// Leetcode 54

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // spiral traversal
        int m = matrix.size(), n = matrix[0].size();
        vector<int> ans;
        int dir = 0;    // 0 --> right, 1 --> down, 2 --> left, 3 --> up
        int x = 0, y = 0;
        for(int i=0; i<m*n; ){
            // cout<<x<<", "<<y<<" dir: "<<dir<<endl;
            if(dir == 0){
                if(y >= n || matrix[x][y] == -101){
                    x++; y--; dir++; dir%=4; continue;
                }
                ans.push_back(matrix[x][y]);
                matrix[x][y] = -101;
                y++;
            }else if(dir == 1){
                if(x >= m || matrix[x][y] == -101){
                    x--; y--; dir++; dir%=4; continue;
                }
                ans.push_back(matrix[x][y]);
                matrix[x][y] = -101;
                x++;
            }else if(dir == 2){
                if(y < 0 || matrix[x][y] == -101){
                    x--; y++; dir++; dir%=4; continue;
                }
                ans.push_back(matrix[x][y]);
                matrix[x][y] = -101;
                y--;
            }else if(dir == 3){
                if(x < 0 || matrix[x][y] == -101){
                    x++; y++; dir++; dir%=4; continue;
                }
                ans.push_back(matrix[x][y]);
                matrix[x][y] = -101;
                x--;
            }
            i++;
        }
        return ans;
    }
};