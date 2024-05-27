// Leetcode 3152

// Approach: prefix sum based approach
class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> pref(n-1, 0);
        for(int i=0; i<n-1; i++){
            pref[i] = ((nums[i]&1) != (nums[i+1]&1));
        }
        for(int i=1; i<n-1; i++){
            pref[i] += pref[i-1];
        }
        int q = queries.size();
        vector<bool> ans(q, 0);
        for(int i=0; i<q; i++){
            int a = queries[i][0], b = queries[i][1];
            if(b > 0){
                int cnt = pref[b-1] - (a > 0 ? pref[a-1] : 0);
                if(cnt == b-a){
                    ans[i] = true;
                }
            }else{
                ans[i] = true;
            }
        }
        return ans;
    }
};