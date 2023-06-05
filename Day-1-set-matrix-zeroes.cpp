class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        // we can store the fact that, whether a row or column will be zero on the
        // 0th row or 0th column itself
        // but before this we need to make sure, if row 0 or col 0 itself contains 0.
        bool firstRow = false, firstCol = false;
        for(int i=0; i<n; i++) if(matrix[i][0]==0) firstCol = true;
        for(int j=0; j<m; j++) if(matrix[0][j]==0) firstRow = true;
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        // now make it zero actually
        // rows
        for(int i=1; i<n; i++){
            if(matrix[i][0]==0){
                for(int j=0; j<m; j++){
                    matrix[i][j] = 0;
                }
            }
        }
        // cols
        for(int j=1; j<m; j++){
            if(matrix[0][j]==0){
                for(int i=0; i<n; i++){
                    matrix[i][j] = 0;
                }
            }
        }
        if(firstRow){
            for(int j=0; j<m; j++) matrix[0][j] = 0;
        }
        if(firstCol){
            for(int i=0; i<n; i++) matrix[i][0] = 0;
        }
    }
};