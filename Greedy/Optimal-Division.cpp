// Leetcode 553
// Nice division logic
// since we have to maximize a/b/c/d/.... it can only happen only when
// (a/b) * c * d * ... --> a/(b/c/d/...) will be the answer
class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        int n = nums.size();
        string ans = "";
        if(n == 0) return ans;
        ans = to_string(nums[0]);
        if(n == 1) return ans;
        ans.push_back('/');
        if(n == 2) return ans + to_string(nums[1]);
        ans.push_back('(');
        for(int i=1; i<n; i++) ans += to_string(nums[i]), ans.push_back('/');
        ans.pop_back();
        ans.push_back(')');
        return ans;
    }
};