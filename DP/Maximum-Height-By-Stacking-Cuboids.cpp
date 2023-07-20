// Leetcode 1691
// DP: [IMP] LIS Pattern
class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        // since we can rearrange, we prefer to sort the cuboids as well as sort each cuboid
        // dimension
        int n = cuboids.size();
        for(int i=0; i<n; i++){
            sort(begin(cuboids[i]), end(cuboids[i]));
        }
        sort(begin(cuboids), end(cuboids));
        // now apply lis based approach (NxN) to find the largest height(NOT length!!!) of stack
        int ans = cuboids[0][2];
        vector<int> heights;
        for(int i=0; i<n; i++) heights.push_back(cuboids[i][2]);
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(cuboids[i][0] >= cuboids[j][0] && cuboids[i][1] >= cuboids[j][1] && cuboids[i][2] >= cuboids[j][2]){
                    if(heights[i] < cuboids[i][2] + heights[j]){
                        heights[i] = cuboids[i][2] + heights[j];
                    }
                }
            }
            ans = max(ans, heights[i]);
        }
        return ans;
    }
};