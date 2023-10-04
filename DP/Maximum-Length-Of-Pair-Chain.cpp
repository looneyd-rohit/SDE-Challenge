// Leetcode 646
// [IMP]: LIS Pattern
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(begin(pairs), end(pairs));
        vector<int> chain(n, 1);
        int ans = 1;
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(pairs[i][0] > pairs[j][1]){
                    chain[i] = max(chain[i], 1+chain[j]);
                }
            }
            ans = max(ans, chain[i]);
        }
        return ans;
    }
};