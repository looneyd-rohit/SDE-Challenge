// Leetcode 3036

class Solution {
public:
    void computeLPS(vector<int>& pattern, vector<int>& lps, int m){
        int len = 0;
        lps[0] = len;
        int i = 1;
        while(i<m){
            if(pattern[i]==pattern[len]){
                lps[i++] = ++len;
            }else{
                // trace back
                if(len > 0) len = lps[len-1];
                else{    // not possible
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n = nums.size(), m = pattern.size();
        // calculate lps for pattern string
        vector<int> lps(m, 0);
        computeLPS(pattern, lps, m);
        // now match pattern
        int i=0, j=0, count=0;
        while(i<n){
            if(j<m && pattern[j]==-1){
                if(i+1<n && nums[i+1]<nums[i]){
                    i++; j++;
                    if(j==m){
                        // full pattern matched, \U0001f680
                        count++;
                        j = lps[j-1];
                    }
                }else{
                    // trace back
                    if(j > 0) j = lps[j-1];
                    else i++;
                }
            }else if(j<m && pattern[j]==0){
                if(i+1<n && nums[i+1]==nums[i]){
                    i++; j++;
                    if(j==m){
                        // full pattern matched, \U0001f680
                        count++;
                        j = lps[j-1];
                    }
                }else{
                    // trace back
                    if(j > 0) j = lps[j-1];
                    else i++;
                }
            }else if(j<m && pattern[j]==1){
                if(i+1<n && nums[i+1]>nums[i]){
                    i++; j++;
                    if(j==m){
                        // full pattern matched, \U0001f680
                        count++;
                        j = lps[j-1];
                    }
                }else{
                    // trace back
                    if(j > 0) j = lps[j-1];
                    else i++;
                }
            }else{
                // trace back
                if(j > 0) j = lps[j-1];
                else i++;
            }
        }
        return count;
    }
};