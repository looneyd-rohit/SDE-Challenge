// Leetcode 3112

// Approach: khandani dijkstra approach
class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for(auto& edge: edges){
            int u = edge[0], v = edge[1], wt = edge[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq_;
        pq_.push({0, 0});
        vector<int> distance(n, 1e9);
        distance[0] = 0;
        vector<int> ans(n, 1e9);
        while(!pq_.empty()){
            auto f = pq_.top(); pq_.pop();
            int time = f.first, node = f.second;
            // cout<<time<<" and "<<node<<endl;
            if(time < disappear[node]) ans[node] = min(ans[node], time), disappear[node] = 0;
            else if(time >= disappear[node] || time > distance[node]) continue;
            // visit neighbours
            for(auto& next: adj[node]){
                if(time + next.second < distance[next.first]){
                    if(time + next.second < disappear[next.first]){
                        distance[next.first] = time + next.second;
                        pq_.push({distance[next.first], next.first});
                    }
                }
            }
        }
        for(int i=0; i<n; i++) if(ans[i]==1e9) ans[i] = -1;
        return ans;
    }
};