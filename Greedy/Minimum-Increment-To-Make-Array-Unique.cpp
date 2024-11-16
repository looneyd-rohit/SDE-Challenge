// Leetcode 945

// Approach 1: sorting (greedy)
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        int total = 0;
        for(int i=1; i<n; i++){
            if(nums[i-1] >= nums[i]){
                total += nums[i-1] - nums[i] + 1;
                nums[i] = nums[i-1] + 1;
            }
        }
        return total;
    }
};

// Approach 2: hashmaps (optimized)
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;
        int mini = 1e9, maxi = -1e9;
        for(auto& e: nums){
            freq[e]++;
            mini = min(mini, e);
            maxi = max(maxi, e);
        }
        int total = 0;
        for(int num=mini; num<=maxi; num++){
            int extra = max(0, freq[num] - 1);
            if(extra > 0){
                freq[num+1] += extra;
                maxi = max(maxi, num+1);
                total += extra;
            }
        }
        return total;
    }
};