// Leetcode 3092

// Approach: normal id to frequency and set to track largest
class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        int n = nums.size();
        unordered_map<long long, long long> ump;
        multiset<long long> mst;
        vector<long long> ans;
        for(int i=0; i<n; i++){
            int id = nums[i], f = freq[i];
            int prev = ump[id];
            if(mst.find(prev)!=mst.end()) mst.erase(mst.find(prev));
            ump[id] += f;
            mst.insert(ump[id]);
            ans.push_back(*mst.rbegin());
        }
        return ans;
    }
};