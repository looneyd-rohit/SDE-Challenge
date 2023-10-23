// Leetcode 2050

class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        // approach: this problem seems like topological sorting --> order needs to be
        // maintained since one course depends on previous course
        unordered_map<int, list<int>> adj;
        vector<int> indegree(n, 0);
        for(auto& rel: relations){
            int u = rel[0], v = rel[1];
            adj[u-1].push_back(v-1);
            indegree[v-1]++;
        }
        queue<int> q;
        vector<int> distances(n, 0);
        for(int i=0; i<n; i++){
            if(indegree[i]==0){
                q.push(i);
                distances[i] = time[i];
            }
        }
        while(!q.empty()){
            int node = q.front(); q.pop();
            // visit neighbours
            for(auto& next: adj[node]){
                distances[next] = max(distances[next], time[next]+distances[node]);
                indegree[next]--;
                if(indegree[next]==0){
                    q.push(next);
                }
            }
        }
        return *max_element(begin(distances), end(distances));
    }
};