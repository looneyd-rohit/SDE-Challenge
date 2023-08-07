// Leetcode 930

// Appraoch 1: Sliding Window Count Pattern
class Solution {
public:
    int countPatternSWT(vector<int>& nums, int goal){
        int n = nums.size();
        int i = 0, j = 0;
        long long sum = 0, count = 0;
        while(j<n){
            sum += nums[j];
            if(sum <= goal){
                count+=(j-i+1);
                j++;
            }else{
                while(i <= j && sum > goal){
                    sum-=nums[i]; i++;
                }
                count+=(j-i+1);
                j++;
            }
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // since the array does not contain negative elements, so the prefix sum
        // is increasing in the nums, hence moving right increases sum and moving left
        // decreases sum, hence we can apply sliding window since movement of window
        // requires a condition, and we can seamlessly move the window
        // apply count pattern of sliding window
        return countPatternSWT(nums, goal) - countPatternSWT(nums, goal-1);
    }
};

// Approach 2: Using Hashmap
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // hashmap based approach
        int n = nums.size();
        int sum = 0, count = 0;
        unordered_map<int, int> umap;
        for(int i=0; i<n; i++){
            sum += nums[i];
            if(sum == goal){
                count++;
            }
            int req = sum - goal;
            if(umap.find(req)!=umap.end()){
                count += umap[req];
            }
            umap[sum]++;
        }
        return count;
    }
};