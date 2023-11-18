// Leetcode 1980
// [IMP]: string pattern making unique
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        // make each index differ for each string
        string ans = "";
        for(int i=0; i<n; i++){
            ans.push_back(nums[i][i] == '1' ? '0' : '1');
        }
        return ans;
    }
};