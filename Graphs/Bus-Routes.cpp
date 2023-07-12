// Leetcode 815
// Good BFS Variation

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        // we have to construct a different type of adjacency list for this graph traversal
        // the logic is, from one source node get all the buses possible that go through the source
        // and then use a bfs traversal from that source to all the nodes that can be reached
        // through all the buses
        // <busStop, list<busNos>>
        unordered_map<int, list<int>> adj;
        int bus = 0;
        for(auto& route: routes){
            for(auto& e: route){
                adj[e].push_back(bus);
            }
            bus++;
        }
        // queue for bfs
        // <busStop, dist> dist --> no of buses used
        queue<pair<int, int>> q;
        q.push({source, 0});
        vector<bool> busStopVisited(1e5+1, false);
        while(!q.empty()){
            auto f = q.front(); q.pop();
            int busStop = f.first, dist = f.second;
            if(busStop == target) return dist;
            
            // visit neighbours
            for(auto& nextBus: adj[busStop]){
                // go to all the nodes that are reachable through this bus
                for(auto& nextBusStop: routes[nextBus]){
                    if(!busStopVisited[nextBusStop]){
                        busStopVisited[nextBusStop] = true;
                        q.push({nextBusStop, dist+1});
                    }
                }
                // once we reach all the nodes with this bus, we should never come to
                // any of the location with the same bus i.e., don't board the same bus
                // this below step is done to improve time complexity, else code will work
                // even without it
                routes[nextBus].clear();
            }
        }
        return -1;
    }
};