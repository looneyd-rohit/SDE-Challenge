// Leetcode 2444

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        int i = 0, j = 0;
        long long count = 0;
        int mini = 1e9, maxi = -1e9;
        while(j < n){
            int e = nums[j];
            if(e<minK || e>maxK){    // out of range [minK...maxK]
                mini = 1e9; maxi = -1e9;
                i = j+1;
                j++;
            }else{
                if(e == minK){
                    mini = j;
                }
                if(e == maxK){
                    maxi = j;
                }
                if(mini!=1e9 && maxi!=-1e9){
                    count += min(mini, maxi) - i + 1;
                }
                j++;
            }
        }
        return count;
    }
};