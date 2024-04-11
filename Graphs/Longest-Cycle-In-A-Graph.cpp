// Leetcode 2360

// Approach: cycles finding approach in a graph
class Solution {
public:
    int solve(int node, int par, vector<int>& edges, vector<int>& visited, vector<int>& parent){
        int ans = 0;
        if(visited[node] == 1){
            // re encountering same node twice --> presence of loop
            int len = 1;
            int prev = par;
            while(prev != node){
                len++;
                prev = parent[prev];
                ans = max(ans, len);
            }
            return ans;
        }
        visited[node] = 1;
        parent[node] = par;
        int next = edges[node];
        if(next!=-1 && visited[next]!=2){
            ans = max(ans, solve(next, node, edges, visited, parent));
        }
        visited[node] = 2;
        return ans;
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> visited(n, -1), parent(n, -1);
        int ans = 0;
        for(int i=0; i<n; i++){
            if(visited[i]==-1){
                ans = max(ans, solve(i, -1, edges, visited, parent));
            }
        }
        return (ans == 0) ? -1 : ans;
    }
};