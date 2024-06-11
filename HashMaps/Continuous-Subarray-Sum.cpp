// Leetcode 523

// Approach: hashmap subarray sum approach
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> hash;
        int sum = 0;
        hash[sum] = -1;
        for(int i=0; i<n; i++){
            sum += nums[i] % k;
            sum %= k;
            
            // if divisible
            if(sum==0){
                if(i>0) return true;
            }
            else{
                if(hash.find(sum)!=hash.end()){
                    if((i-hash[sum])>1)return true;
                }else hash[sum] = i;
            }
        }
        return false;
    }
};