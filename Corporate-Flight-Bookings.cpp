// Leetcode 1109
// Difference array technique

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        // difference array technique
        int b = bookings.size();
        vector<int> ans(n, 0);
        for(int i=0; i<b; i++){
            int f = bookings[i][0], l = bookings[i][1], qt = bookings[i][2];
            ans[f-1]+=qt;
            if(l < n) ans[l] -= qt;
        }
        for(int i=1; i<n; i++) ans[i] += ans[i-1];
        return ans;
    }
};