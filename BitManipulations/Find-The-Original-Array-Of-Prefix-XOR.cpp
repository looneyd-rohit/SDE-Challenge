// Leetcode 2433

class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        vector<int> ans(n, 0);
        for(int i=0; i<n; i++){
            ans[i] = ((i>0) ? pref[i-1] : 0) ^ pref[i];
        }
        return ans;
    }
};