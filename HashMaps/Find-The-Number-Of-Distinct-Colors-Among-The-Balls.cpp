// Leetcode 3160

// Approach: two hashmap approach
class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> ump1;  // ball -> color
        unordered_map<int, set<int>> ump2;  // color -> [balls]
        vector<int> ans;
        for(auto& query: queries){
            int x = query[0], y = query[1];
            if(ump1.find(x)!=ump1.end()){
                // already colored
                int prev = ump1[x];
                ump1.erase(x);
                ump2[prev].erase(x);
                if(ump2[prev].empty()) ump2.erase(prev);
            }
            ump1[x] = y;
            ump2[y].insert(x);
            ans.push_back(ump2.size());
        }
        return ans;
    }
};