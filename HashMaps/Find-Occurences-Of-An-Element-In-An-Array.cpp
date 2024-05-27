// Leetcode 3159

// Approach: basic hashmap approach
class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        int n = nums.size();
        vector<int> v;
        for(int i=0; i<n; i++) if(nums[i]==x) v.push_back(i);
        vector<int> ans;
        for(auto& q: queries){
            if(q>v.size()) ans.push_back(-1);
            else ans.push_back(v[q-1]);
        }
        return ans;
    }
};