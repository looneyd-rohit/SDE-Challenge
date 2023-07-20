// Leetcode 1514
// Dijkstra Pattern
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        // similar pattern related to dijkstra
        // construct the adjancency list
        int m = edges.size();
        unordered_map<int, list<pair<int, double>>> adj;
        for(int i=0; i<m; i++){
            int u = edges[i][0], v = edges[i][1];
            double prob = succProb[i];
            adj[u].push_back({v, prob});
            adj[v].push_back({u, prob});
        }
        // finding the probability of all paths from start_node to others
        // hence, when standing at start_node probability = 1.0 since start_node to start_node
        // will have probability = 1.0
        priority_queue<pair<double, int>> maxheap;
        vector<double> probability(n, 0.0);
        maxheap.push({1.0, start_node});
        probability[start_node] = 1.0;
        while(!maxheap.empty()){
            auto top = maxheap.top(); maxheap.pop();
            double p = top.first;
            int node = top.second;
            if(node == end_node) return p;
            // visit neighbours
            for(auto& next: adj[node]){
                double next_p = p * next.second;
                if(next_p > probability[next.first]){
                    probability[next.first] = next_p;
                    maxheap.push({next_p, next.first});
                }
            }
        }
        return 0;
    }
};