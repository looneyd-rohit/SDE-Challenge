// Leetcode 1424
// Approach 1: Using HashMap
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        // approach 1: diagonal trick (use indices sum and store in map)
        int n = nums.size();
        int m = 0;
        vector<int> ans;
        unordered_map<int, vector<int>> mp;
        for(int i=n-1; i>=0; i--){
            m = max(m, (int)nums[i].size());
            for(int j=0; j<nums[i].size(); j++){
                mp[i+j].push_back(nums[i][j]);
            }
        }
        for(int i=0; i<n+m; i++){
            for(auto& el: mp[i]) ans.push_back(el);
        }
        return ans;
    }
};

// Approach 2: Using BFS
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        // approach 2: bfs
        int n = nums.size();
        vector<int> ans;
        queue<pair<int, int>> q;
        q.push({0, 0});
        while(!q.empty()){
            auto f = q.front(); q.pop();
            int x = f.first, y = f.second;
            ans.push_back(nums[x][y]);
            if(x<n-1 && y==0) q.push({x+1, y});
            if(y<nums[x].size()-1) q.push({x, y+1});
        }
        return ans;
    }
};