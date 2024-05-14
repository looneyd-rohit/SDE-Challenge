// Leetcode 506

// Approach: greedy storing
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        map<int, int> mp;
        for(int i=0; i<n; i++) mp[score[i]] = i;
        vector<string> ans(n, "");
        
        int ind = mp.rbegin()->second;
        ans[ind] = "Gold Medal";
        mp.erase(mp.rbegin()->first);
        if(n == 1) return ans;

        ind = mp.rbegin()->second;
        ans[ind] = "Silver Medal";
        mp.erase(mp.rbegin()->first);
        if(n == 2) return ans;

        ind = mp.rbegin()->second;
        ans[ind] = "Bronze Medal";
        mp.erase(mp.rbegin()->first);
        if(n == 3) return ans;

        int rank = 4;
        for(auto it=mp.rbegin(); it!=mp.rend(); it++){
            ans[it->second] = to_string(rank++);
        }

        return ans;
    }
};