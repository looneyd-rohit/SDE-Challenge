class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        int K = 0;
        vector<vector<int>> ans;
        sort(begin(nums), end(nums));
        for(int i=0; i<n; i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int first = nums[i];
            int req = K - first;
            int j=i+1, k=n-1;
            while(j<k){
                int second = nums[j], third = nums[k];
                int sum = second + third;
                if(sum > req){
                    k--;
                }else if(sum < req){
                    j++;
                }else{
                    ans.push_back({first, second, third});
                    while(j<k){
                        if(nums[j]==second) j++;
                        else break;
                    }
                    while(j<k){
                        if(nums[k]==third) k--;
                        else break;
                    }
                }
            }
        }
        return ans;
    }
};