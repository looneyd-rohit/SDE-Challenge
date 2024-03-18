// Leetcode 3080

class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        unordered_map<int, int> ump;
        set<pair<int, int>> mst;
        long long sum = 0;
        for(int i=0; i<n; i++){
            ump[i] = nums[i];
            mst.insert({nums[i], i});
            sum += nums[i];
        }
        int q = queries.size();
        vector<long long> ans;
        for(int i=0; i<q; i++){
            int ind = queries[i][0], k = queries[i][1];
            if(ump.find(ind)!=ump.end()){
                sum -= ump[ind];
                mst.erase({ump[ind], ind});
                ump.erase(ind);
            }
            
            while(!mst.empty() && k--){
                sum -= mst.begin()->first;
                ump.erase(mst.begin()->second);
                mst.erase(mst.begin());
            }
            ans.push_back(sum);
        }
        return ans;
    }
};