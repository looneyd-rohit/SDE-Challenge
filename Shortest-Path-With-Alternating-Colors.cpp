// Leetcode 1129
// Approach: Atmost two bfs are required to reach any node if path exists from 0 to that node with the given constraints (dry run)

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        // first construct the graph
        // red --> 1, blue --> 2
        unordered_map<int, list<pair<int, int>>> adj;
        for(auto& edge: redEdges){
            int u = edge[0], v = edge[1];
            adj[u].push_back({v, 1});
        }
        for(auto& edge: blueEdges){
            int u = edge[0], v = edge[1];
            adj[u].push_back({v, 2});
        }
        queue<tuple<int, int, int>> q;
        // <node, dist, prevColor>
        // a node can be reached either by red or by blue color, nothing else
        // atmost two visits are required to find the distance to every other node (if exists)
        q.push(tuple<int, int, int>(0, 0, 0));
        vector<vector<int>> visited(3, vector<int>(101, 0));
        visited[0][0] = 1;
        vector<int> distances(n, -1);
        distances[0] = 0;
        while(!q.empty()){
            auto f = q.front(); q.pop();
            int node = get<0>(f), dist = get<1>(f), prevColor = get<2>(f);
            if(distances[node] == -1) distances[node] = dist;
            for(auto& next: adj[node]){
                if(next.second != prevColor){
                    // alternating color
                    if(!visited[next.second][next.first]){
                        // check not visited
                        visited[next.second][next.first] = 1;
                        q.push(tuple<int, int, int>(next.first, dist+1, next.second));
                    }
                }
            }
        }
        return distances;
    }
};