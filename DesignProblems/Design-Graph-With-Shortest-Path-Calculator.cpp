// Leetcode 2642

// Approach [IMP]: Floyd Warshall
class Graph {
public:
    int n;
    vector<vector<int>> distances;
    Graph(int n, vector<vector<int>>& edges) {
        this->n = n;
        distances.resize(n, vector<int>(n, 1e9));
        for(int i=0; i<n; i++) distances[i][i] = 0;
        for(auto& edge: edges){
            int u = edge[0], v = edge[1], wt = edge[2];
            distances[u][v] = wt;
        }
        // construct the distances array
        for(int via=0; via<n; via++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    distances[i][j] = min(distances[i][j], distances[i][via]+distances[via][j]);
                }
            }
        }
    }
    
    void addEdge(vector<int> edge) {
        int u = edge[0], v = edge[1], wt = edge[2];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                distances[i][j] = min(distances[i][j], distances[i][u] + wt + distances[v][j]);
            }
        }
    }
    
    int shortestPath(int node1, int node2) {
        return distances[node1][node2] >= 1e9 ? -1 : distances[node1][node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */