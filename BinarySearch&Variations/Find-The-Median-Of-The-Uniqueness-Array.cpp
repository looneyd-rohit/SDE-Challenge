// Leetcode 3134

// Approach: binary search + sliding window to count subarrays with atmost k distinct integers
class Solution {
public:
    long long countOfSubarraysWithAtmostKDistinct(vector<int>& nums, int k){
        int n = nums.size();
        int i=0, j=0;
        long long count = 0;
        unordered_map<int, int> hash;
        while(j<n){
            hash[nums[j]]++;
            if(hash.size() <= k){
                count += (j - i + 1);
                j++;
            }else{
                while(i<=j && hash.size() > k){
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
    int medianOfUniquenessArray(vector<int>& nums) {
        // approach: the uniqueness array consists of the count of the distinct
        // elements in each of the subarrays
        // for a number m to be median, count of numbers before m including m >= count of
        // numbers after m (not including it)
        // now, for a particular k number of distinct elements, we define a function
        // countOfSubarraysWithAtmost(k) -> as the number of subarrays with atmost k
        // distinct integers, here for k being a number in the uniqueness array, for this
        // to be median countOfSubarraysWithAtmost(k) >= total - countOfSubarraysWithAtmost(k)
        // total subarrays ~ n * (n + 1) / 2
        int n = nums.size();
        long long total = n * 1LL * (n + 1) / 2;
        long long low = 1, high = n;
        while(low <= high){
            long long mid = low + ((high - low) >> 1);
            long long left = countOfSubarraysWithAtmostKDistinct(nums, mid);
            long long right = total - left;
            if(left >= right){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return low;
    }
};