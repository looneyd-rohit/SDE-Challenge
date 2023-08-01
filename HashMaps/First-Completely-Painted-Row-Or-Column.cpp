// Leetcode 2661

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        // brute force:
        int sz = arr.size();
        int m = mat.size(), n = mat[0].size();
        unordered_map<int, pair<int, int>> umap;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                umap[mat[i][j]] = make_pair(i, j);
            }
        }
        // maintain a hash array(s) that will store count of cell of a particular
        // row or col that is painted
        vector<int> row(m, 0), col(n, 0);
        for(int i=0; i<sz; i++){
            int e = arr[i];

            // color the e-th cell
            int x = umap[e].first, y = umap[e].second;
            mat[x][y] = -1;

            // update count
            row[x]++; col[y]++;

            // check if row/col is colored
            if(row[x] == n) return i;
            if(col[y] == m) return i;
        }
        return -1;
    }
};