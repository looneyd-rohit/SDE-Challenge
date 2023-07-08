// Q1.

class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxi = -1;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int second = nums[j], first = nums[j-1];
                int size = j-i+1;
                int diff = second - first;
                if(size & 1){
                    if(diff != -1) break;
                    maxi = max(maxi, size);
                }else{
                    if(diff != 1) break;
                    maxi = max(maxi, size);
                }
            }
        }
        return maxi;
    }
};