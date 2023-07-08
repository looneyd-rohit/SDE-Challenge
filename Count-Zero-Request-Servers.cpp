// Leetcode 2747
// [IMP]: Sliding Window with QUERY Pattern

class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m = logs.size();
        for(int i=0; i<m; i++){
            swap(logs[i][0], logs[i][1]);
        }
        sort(begin(logs), end(logs));
        int q = queries.size();
        vector<pair<int, int>> queryInd;
        for(int i=0; i<q; i++) queryInd.push_back({queries[i], i});
        sort(begin(queryInd), end(queryInd));
        // sliding window approach, fixed size window of length = x
        vector<int> ans(q, 0);
        int ind = 0, ind2 = 0;
        unordered_map<int, int> hash;
        for(int i=0; i<q; i++){
            // expand the window until upper bound hit
            while(ind<m && logs[ind][0] <= queryInd[i].first){
                hash[logs[ind][1]]++;
                ind++;
            }
            // shrink till it exceeds lower bound
            while(ind2<m && logs[ind2][0] < queryInd[i].first - x){
                hash[logs[ind2][1]]--;
                if(hash[logs[ind2][1]]==0) hash.erase(logs[ind2][1]);
                ind2++;
            }
            ans[queryInd[i].second] = n - hash.size();
        }
        return ans;
    }
};