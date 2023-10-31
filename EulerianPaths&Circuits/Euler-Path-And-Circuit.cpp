// https://practice.geeksforgeeks.org/problems/euler-circuit-and-path/1

class Solution {
public:
    void dfs(int node, vector<int> adj[], vector<bool>& visited){
        visited[node] = true;
        for(auto& next: adj[node]){
            if(!visited[next]){
                dfs(next, adj, visited);
            }
        }
    }
    bool isConnected(int V, vector<int> adj[]){
        int startNode = -1;
        for(int i=0; i<V; i++){
            if(adj[i].size()!=0){
                startNode = i;
                break;
            }
        }
        // make dfs call
        vector<bool> visited(V, false);
        dfs(startNode, adj, visited);
        
        // check if all non zero vertices are visited or not
        for(int i=0; i<V; i++){
            if(!visited[i] && adj[i].size()>0){
                return false;
            }
        }
        return true;
    }
	int isEularCircuit(int V, vector<int>adj[]){
	    if(!isConnected(V, adj)){
	        return false;
	    }
	    
	    // check for number of odd vertices
	    int oddVertexCount = 0;
	    for(int i=0; i<V; i++){
	        if(adj[i].size() & 1){
	            oddVertexCount++;
	        }
	    }
	    
	    if(oddVertexCount > 2) return 0;
	    if(oddVertexCount == 2) return 1;
	    if(oddVertexCount == 0) return 2;
	    return 0;
	}
};