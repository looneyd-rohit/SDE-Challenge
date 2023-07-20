// Leetcode 834
// [IMP]: Graph includes both BFS and DFS and observations and maths
class Solution {
public:
    int dfs(int node, int par, unordered_map<int, list<int>>& adj, vector<bool>& visited, int len, vector<int>& relativeDistances, vector<int>& childCounts, vector<int>& parents){
        visited[node] = true;
        relativeDistances[node] = len;
        parents[node] = par;
        int ans = 1;
        for(auto& next: adj[node]){
            if(!visited[next]){
                ans += dfs(next, node, adj, visited, len+1, relativeDistances, childCounts, parents);
            }
        }
        childCounts[node] = ans - 1;
        return ans;
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        // concept of relative distances, if we know distance of all other nodes from node n
        // then we can calculate distances of all other nodes from another node m
        
        // construct the adjancency list
        unordered_map<int, list<int>> adj;
        for(auto& edge: edges){
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        
        vector<bool> visited(n, false);
        // we need relativeDistance from atleast one of the nodes, and we need childCounts of
        // every node, and we need parents of every node
        // since the formula can be derived as
        // distanceSumFromChild = relativeDistanceSumFromParent - childNodes(including itself) + parentAndOthers
        vector<int> relativeDistances(n, 0), childCounts(n, 0), parents(n, -1);
        
        // main dfs call to generate the structures
        dfs(0, -1, adj, visited, 0, relativeDistances, childCounts, parents);
        
        
        int distanceSumFrom0 = 0;
        for(auto& e: relativeDistances) distanceSumFrom0 += e;
        vector<int> ans(n, distanceSumFrom0);
        
        
        // do a bfs, since child's count is directly dependent on parent's count
        vector<bool> visited2(n, false);
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int f = q.front(); q.pop();
            int par = parents[f];
            visited2[f] = true;
            if(par != -1){
                int relativeDistSumFromParent = ans[par];
                int childNodes = childCounts[f] + 1;
                int parentAndOthers = n - childNodes;
                ans[f] = relativeDistSumFromParent + parentAndOthers - childNodes;
            }
            // visit others
            for(auto& next: adj[f]){
                if(!visited2[next]){
                    q.push(next);
                }
            }
        }
        return ans;
    }
};