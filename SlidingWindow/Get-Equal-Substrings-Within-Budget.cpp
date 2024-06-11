// Leetcode 1208

// Approach 1: prefix sum + binary search
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length();
        vector<int> pref(n, 0);
        for(int i=0; i<n; i++) pref[i] = abs(t[i]-s[i]);
        for(int i=1; i<n; i++) pref[i] += pref[i-1];
        int maxi = 0;
        for(int i=0; i<n; i++){
            int low = i, high = n-1;
            while(low <= high){
                int mid = low + ((high - low) >> 1);
                int diff = pref[mid] - (i > 0 ? pref[i-1] : 0);
                if(diff > maxCost){
                    high = mid - 1;
                }else{
                    maxi = max(maxi, mid-i+1);
                    low = mid + 1;
                }
            }
        }
        return maxi;
    }
};

// Approach 2: sliding window
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length();
        vector<int> pref(n, 0);
        for(int i=0; i<n; i++) pref[i] = abs(t[i]-s[i]);
        int i = 0, j = 0, cost = 0, maxi = 0;
        while(j < n){
            cost += pref[j];
            if(cost <= maxCost){
                maxi = max(maxi, j-i+1);
                j++;
            }else{
                while(i<=j && cost > maxCost){
                    cost -= pref[i];
                    i++;
                }
                maxi = max(maxi, j-i+1);
                j++;
            }
        }
        return maxi;
    }
};