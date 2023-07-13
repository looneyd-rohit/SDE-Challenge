// Leetcode 1503
// Simulation Based + Maths
class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        // we don't care whether they change directions or not, since both are identical
        // assume both move without any change
        int ans = 0;
        int l = left.size(), r = right.size();
        for(int i=0; i<l; i++) ans = max(ans, left[i]);
        for(int i=0; i<r; i++) ans = max(ans, n-right[i]);
        return ans;
    }
};