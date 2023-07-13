// Leetcode 207

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // simple toposort based question, if toposort order exists then all
        // courses can be completed
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses, 0);
        for(auto& edge: prerequisites){
            int u = edge[0], v = edge[1];
            adj[v].push_back(u);
            indegree[u]++;
        }
        queue<int> q;
        for(int i=0; i<numCourses; i++) if(indegree[i]==0) q.push(i);
        vector<int> toposort;
        while(!q.empty()){
            auto f = q.front(); q.pop();
            toposort.push_back(f);
            // visit neighbours
            for(auto& next: adj[f]){
                indegree[next]--;
                if(indegree[next]==0){
                    q.push(next);
                }
            }
        }
        return toposort.size() == numCourses;
    }
};