// Leetcode 2597
// Normal Recursion
class Solution {
public:
    int solve(int index, vector<int>& nums, int k, vector<int>& hash){
        // base case
        if(index >= nums.size()){
            return 1;
        }
        
        // pick --> only if doesn not violate
        int req1 = nums[index] - k + 1000;
        int pick = 0;
        if(hash[req1] > 0){
            // don't add
        }else{
            hash[nums[index] + 1000]++;
            pick = solve(index+1, nums, k, hash);
            hash[nums[index] + 1000]--;
        }
        
        // notPick
        int notPick = solve(index+1, nums, k, hash);
        
        return (pick + notPick);
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> hash(3000, 0);
        // if we sort the array we won't have to check for +k and -k both
        sort(begin(nums), end(nums));
        return solve(0, nums, k, hash) - 1;
    }
};