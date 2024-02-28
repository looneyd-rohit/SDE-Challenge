// Leetcode 1814

class Solution {
public:
    const int M = 1e9+7;
    int rev(int x){
        string temp = to_string(x);
        reverse(begin(temp), end(temp));
        return stoi(temp);
    }
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> hash;
        int ans = 0;
        for(int i=0; i<n; i++){
            nums[i] = nums[i] - rev(nums[i]);
            ans += hash[nums[i]] % M;
            ans %= M;
            hash[nums[i]]++;
        }
        return ans;
    }
};