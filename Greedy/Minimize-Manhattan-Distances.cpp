// Leetcode 3102

// [IMP] Approach: Manhattan Distance maximization approach
class Solution {
public:
    vector<int> findMaximumManhattanDistance(vector<vector<int>>& points, int not_take){
        int n = points.size();
        int max_sum = -1e9, max_sum_ind = -1, min_sum = 1e9, min_sum_ind = -1;
        int max_diff = -1e9, max_diff_ind = -1, min_diff = 1e9, min_diff_ind = -1;
        for(int i=0; i<n; i++){
            if(i==not_take) continue;

            int sum = points[i][0] + points[i][1];
            int diff = points[i][0] - points[i][1];

            if(sum > max_sum){
                max_sum = sum;
                max_sum_ind = i;
            }
            
            if(sum < min_sum){
                min_sum = sum;
                min_sum_ind = i;
            }

            if(diff > max_diff){
                max_diff = diff;
                max_diff_ind = i;
            }

            if(diff < min_diff){
                min_diff = diff;
                min_diff_ind = i;
            }
        }
        if(max_sum - min_sum > max_diff - min_diff){
            return {max_sum - min_sum, max_sum_ind, min_sum_ind};
        }else{
            return {max_diff - min_diff, max_diff_ind, min_diff_ind};
        }
    }
    int minimumDistance(vector<vector<int>>& points) {
        int n = points.size();
        auto v = findMaximumManhattanDistance(points, -1);
        auto a = findMaximumManhattanDistance(points, v[1]);
        auto b = findMaximumManhattanDistance(points, v[2]);
        return min(a[0], b[0]);
    }
};