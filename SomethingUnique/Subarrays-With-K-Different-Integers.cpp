// Leetcode 992

// [IMP] Approach 1: (Subarrays with COUNT Pattern with given K)

class Solution {
public:
    int countSubArrayWithAtMostKDistinct(vector<int>& nums, int k){
        int n = nums.size();
        unordered_map<int, int> hash;
        int i = 0, j = 0;
        int count = 0;
        while(j < n){
            hash[nums[j]]++;

            if(hash.size() <= k){
                count += (j - i + 1);
                j++;
            }else{
                while(i <= j && hash.size() > k){
                    hash[nums[i]]--;
                    if(hash[nums[i]]==0) hash.erase(nums[i]);
                    i++;
                }
                count += (j - i + 1);
                j++;
            }
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        return countSubArrayWithAtMostKDistinct(nums, k) - countSubArrayWithAtMostKDistinct(nums, k-1);
    }
};

// [IMP] Approach 2: without sliding window count pattern, one pass
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // one pass solution: tricky
        int n = nums.size();
        unordered_map<int, int> ump;
        int i = 0, j = 0, l = 0;
        int count = 0;
        while(j < n){
            ump[nums[j]]++;
            
            // take care of invalid subarray
            while(ump.size() > k){
                ump[nums[i]]--;
                if(ump[nums[i]]==0) ump.erase(nums[i]);
                i++; l = i;
            }

            // compute the smallest valid subarray
            while(ump[nums[i]] > 1){
                ump[nums[i]]--;
                i++;
            }

            if(ump.size() == k){
                count += (i - l + 1);
            }

            j++;
        }
        return count;
    }
};