// Leetcode 2389

// Brute Force
class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        int q = queries.size();
        vector<int> ans(q, 0);
        for(int i=0; i<q; i++){
            int sum = 0;
            int len = 0;
            for(int j=0; j<n; j++){
                sum += nums[j];
                if(sum > queries[i]) break;
                len++;
            }
            ans[i] = len;
        }
        return ans;
    }
};

// Optimization (Prefix Sum):
class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        // optimization using prefix sum
        for(int i=1; i<n; i++) nums[i] += nums[i-1];
        int q = queries.size();
        vector<int> ans(q, 0);
        for(int i=0; i<q; i++){
            auto it = lower_bound(begin(nums), end(nums), queries[i]) - begin(nums);
            if(it < n && (nums[it] == queries[i])) ans[i] = it+1;
            else ans[i] = it;
        }
        return ans;
    }
};