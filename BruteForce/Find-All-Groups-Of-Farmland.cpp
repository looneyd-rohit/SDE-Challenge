// Leetcode 1992

// Approach: brute force implementation
class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size(), n = land[0].size();
        vector<vector<int>> ans;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(land[i][j]==1){
                    int temp_i = i, temp_j = j;
                    for(; temp_i<m && land[temp_i][j]; temp_i++);
                    for(; temp_j<n && land[i][temp_j]; temp_j++);
                    temp_i--; temp_j--;
                    if(land[temp_i][temp_j]!=2){
                        vector<int> coord;
                        coord.push_back(i);
                        coord.push_back(j);
                        coord.push_back(temp_i);
                        coord.push_back(temp_j);
                        ans.push_back(coord);
                        land[temp_i][temp_j] = 2;
                    }
                    j = temp_j;
                }
            }
        }
        return ans;
    }
};