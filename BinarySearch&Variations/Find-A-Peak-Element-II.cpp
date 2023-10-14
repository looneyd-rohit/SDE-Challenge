// Leetcode 1901

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        // optimized approach: keep low at 0 and high at m-1
        // now binary search for the row nos. for a particular row, find the max element
        // since we are taking the max element for a particular row, it is already satisfying
        // two conditions i.e., it is greater than its left and right elements
        // now, we only need to check if that max element is greater than up and down or not
        // if not shrink the search space to the respective side
        int low = 0, high = m-1;
        while(low <= high){
            int mid = low + ((high-low) >> 1);
            // find the max element for the current row
            int maxi = -1, maxIndY = -1;
            for(int i=0; i<n; i++){
                if(mat[mid][i]>maxi){
                    maxi = mat[mid][i];
                    maxIndY = i;
                }
            }
            // check if it is larger than up and down elements
            int up = mid > 0 ? mat[mid-1][maxIndY] : -1;
            int down = mid < m-1 ? mat[mid+1][maxIndY] : -1;
            if(maxi > up && maxi > down){
                return {mid, maxIndY};
            }else if(maxi > up){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return {-1, -1};
    }
};