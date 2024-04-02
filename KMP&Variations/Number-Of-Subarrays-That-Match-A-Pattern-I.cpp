// Leetcode 3034

// Approach 1: brute force
class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n = nums.size(), m = pattern.size();
        int count = 0;
        for(int i=0; i<n; i++){
            bool flag = true;
            for(int j=0; j<m; j++){
                if(pattern[j]==1){
                    if(i+j+1<n && nums[i+j+1]>nums[i+j]){

                    }else{
                        flag = false;
                        break;
                    }
                }else if(pattern[j]==0){
                    if(i+j+1<n && nums[i+j+1]==nums[i+j]){

                    }else{
                        flag = false;
                        break;
                    }
                }else if(pattern[j]==-1){
                    if(i+j+1<n && nums[i+j+1]<nums[i+j]){

                    }else{
                        flag = false;
                        break;
                    }
                }
            }
            count += flag;
        }
        return count;
    }
};

// Approach 2: using KMP algorithm
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
                        // full pattern matched, 🚀
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
                        // full pattern matched, 🚀
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
                        // full pattern matched, 🚀
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