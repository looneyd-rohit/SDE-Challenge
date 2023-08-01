// Leetcode 2683

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        int prev1 = 0, prev2 = 1;
        for(int i=1; i<n; i++){
            prev1 = derived[(i-1)] ^ prev1;
            prev2 = derived[(i-1)] ^ prev2;
        }
        return (0 == (derived.back() ^ prev1)) || (1 == (derived.back() ^ prev2));
    }
};