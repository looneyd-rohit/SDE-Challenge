// Leetcode 1755

// Approach: meet in the middle subset approach
class Solution {
public:
    void solve(int index, int sum, int n, vector<int>& nums, vector<int>& store){
        if(index == n){
            store.push_back(sum);
            return;
        }

        // take
        solve(index+1, sum+nums[index], n, nums, store);

        // not take
        solve(index+1, sum, n, nums, store);
    }
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();

        vector<int> left, right;
        for(int i=0; i<(n>>1); i++){
            left.push_back(nums[i]);
        }
        for(int i=(n>>1); i<n; i++){
            right.push_back(nums[i]);
        }
        
        vector<int> store_left, store_right;
        // form left
        solve(0, 0, left.size(), left, store_left);
        // form right
        solve(0, 0, right.size(), right, store_right);

        sort(begin(store_left), end(store_left));

        sort(begin(store_right), end(store_right));

        set<int> temp(begin(store_left), end(store_left));
        int mini = 1e9;
        for(auto& e: temp){
            int req = goal - e;
            auto it = upper_bound(begin(store_right), end(store_right), req);
            if(it!=store_right.end()) mini = min(mini, abs(*it + e - goal));
            if(it!=store_right.begin()) mini = min(mini, abs(*(--it) + e - goal));
        }
        return mini;
    }
};