// Leetcode 2348

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> groups;
        int prev = nums[0], cnt = 1;
        for(int i=1; i<n; i++){
            if(nums[i]==prev){
                cnt++;
            }else{
                groups.push_back({prev, cnt});
                prev = nums[i];
                cnt = 1;
            }
        }
        groups.push_back({prev, cnt});
        long long ans = 0;
        for(int i=0; i<groups.size(); i++){
            if(groups[i].first == 0){
                long long c = groups[i].second;
                ans += c * (c + 1) / 2;
            }
        }
        return ans;
    }
};