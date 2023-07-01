// Leetcode 2305
// https://leetcode.com/problems/fair-distribution-of-cookies/description/

class Solution {
public:
    int solve(int index, int k, int maxSum, vector<int>& cookies, vector<int>& distribution){
        // base case
        if(index >= cookies.size()){
            return maxSum;
        }

        int cookie = cookies[index];
        int ans = 1e9;
        int t = maxSum;
        for(int i=0; i<k; i++){
            // redundant call elimination
            if(i>0 && distribution[i]==distribution[i-1]) continue;
            distribution[i] += cookie;
            maxSum = max(maxSum, distribution[i]);
            ans = min(ans, solve(index-1, k, maxSum, cookies, distribution));
            maxSum = t;
            distribution[i] -= cookie;
        }
        return ans;
    }
    int distributeCookies(vector<int>& cookies, int k) {
        int n = cookies.size();
        vector<int> distribution(k, 0);
        return solve(n-1, k, 0, cookies, distribution);
    }
};