// Leetcode 3132

// Approach: brute force
class Solution {
public:
    int solve(vector<int>& nums1, vector<int>& nums2){
        int n = nums1.size();
        int diff = nums2.front() - nums1.front();
        for(int i=1; i<n; i++){
            if((nums2[i]-nums1[i])!=diff){
                return 1e9;
            }
        }
        return diff;
    }
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        sort(begin(nums1), end(nums1));
        sort(begin(nums2), end(nums2));
        int mini = 1e9;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                // form new array without i and j
                vector<int> nums;
                for(int k=0; k<n; k++){
                    if(k==i || k==j) continue;
                    nums.push_back(nums1[k]);
                }
                mini = min(mini, solve(nums, nums2));
            }
        }
        return mini;
    }
};