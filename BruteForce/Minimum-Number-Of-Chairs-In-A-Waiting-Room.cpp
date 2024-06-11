// Leetcode 3168

// Approach: brute force
class Solution {
public:
    int minimumChairs(string s) {
        int n = s.length();
        int ans = 0;
        int maxi = 0;
        for(auto& e: s){
            if(e=='E') ans += 1;
            else ans -= 1;
            maxi = max(maxi, ans);
        }
        return maxi;
    }
};