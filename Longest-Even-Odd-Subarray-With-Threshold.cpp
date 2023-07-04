// Leetcode 2760
class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int n = nums.size();
        int maxi = 0;
        for(int i=0; i<n; i++){
            if(!(nums[i] & 1) && nums[i]<=threshold){
                maxi = max(maxi, 1);
                for(int j=i+1, k=i; j<n; j++, k++){
                    if((nums[j]%2 == nums[k]%2) || nums[j] > threshold){
                        i = k;
                        break;
                    }
                    maxi = max(maxi, j-i+1);
                }
            }
        }
        return maxi;
    }
};