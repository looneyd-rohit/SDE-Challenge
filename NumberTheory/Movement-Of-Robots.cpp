// Leetcode 2731

class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        // modulo mc
        vector<long long> v(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            v[i] = nums[i];
            if(s[i]=='L'){
                v[i]-=d;
            }
            else v[i]+=d;
        }
        sort(v.begin(),v.end());
        long long sum = 0, mod = 1e9 + 7, n = nums.size()-1;
        for(int i=0;i<nums.size()-1;i++){
            long long x = v[i+1]-v[i];
            x = ((x%mod)*(n%mod))%mod;
            x = (((i+1) % mod) * (x % mod)) % mod;
            sum = ((sum%mod)+x)%mod;
            n--;
        }
        int ans = sum;
        return ans;
    }
};