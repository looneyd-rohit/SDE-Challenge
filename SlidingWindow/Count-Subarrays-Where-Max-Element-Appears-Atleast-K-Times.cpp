// Leetcode 2962

// Approach 1: khandani sliding window count pattern
class Solution {
public:
    long long countSubarraysWithAtMostK(vector<int>& nums, int k){
        int n = nums.size();
        int freq = 0;
        int maxi = *max_element(begin(nums), end(nums));
        int i = 0, j = 0 ;
        long long count = 0;
        while(j < n){
            if(nums[j]==maxi) freq++;

            if(freq <= k){
                count += (j - i + 1);
                j++;
            }else{
                while(i<=j && freq > k){
                    if(nums[i]==maxi) freq--;
                    i++;
                }
                count += (j - i + 1);
                j++;
            }
        }
        return count;
    }
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        long long count_at_most_k = countSubarraysWithAtMostK(nums, k-1);
        long long total = n * 1LL * (n + 1) / 2;
        return (total - count_at_most_k);
    }
};

// Approach 2: without sliding window
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = *max_element(begin(nums), end(nums));
        vector<int> indices;
        long long count = 0;
        for(int i=0; i<n; i++){
            int e = nums[i];
            if(e == maxi) indices.push_back(i);
            if(indices.size() >= k){
                count += indices[indices.size()-k] + 1;
            }
        }
        return count;
    }
};