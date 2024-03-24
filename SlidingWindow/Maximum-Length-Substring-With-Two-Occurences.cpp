// Leetcode 3090

// Approach: sliding window
class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length();
        int i = 0, j = 0;
        unordered_map<int, int> ump;
        int maxi = 0;
        while(j<n){
            ump[s[j]]++;
            if(ump[s[j]] > 2){
                // remove this element which causes disturbance
                while(i<j && ump[s[j]]>2){
                    ump[s[i]]--;
                    i++;
                }
                maxi = max(maxi, j-i+1);
                j++;
            }else{
                maxi = max(maxi, j-i+1);
                j++;
            }
        }
        return maxi;
    }
};