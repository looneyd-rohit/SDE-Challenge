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

// Approach: updated solution
class Solution {
public:
    bool checkEulerCircuit(int V, vector<int>adj[]){
        vector<int> indegree(V, 0);
        for(int i=0; i<V; i++){
            for(auto& node: adj[i]){
                indegree[node]++;
            }
        }
        for(int i=0; i<V; i++){
            if(indegree[i] & 1){
                return false;
            }
        }
        vector<bool> visited(V, false);
        function<void(int)> dfs = [&](int node){
            visited[node] = true;
            for(auto& next: adj[node]){
                if(!visited[next]){
                    dfs(next);
                }
            }
        };
        dfs(0);
        for(int i=0; i<V; i++){
            if(indegree[i] > 0){
                if(!visited[i]){
                    // separate components
                    return false;
                }
            }
        }
        return true;
    }
    bool checkEulerPath(int V, vector<int>adj[]){
        vector<int> indegree(V, 0);
        for(int i=0; i<V; i++){
            for(auto& node: adj[i]){
                indegree[node]++;
            }
        }
        int count = 0;
        for(int i=0; i<V; i++){
            if(indegree[i] & 1){
                count++;
            }
        }
        // only 0 or only 2 odd vertex allowed in euler path
        if(count != 0 && count != 2) return false;
        
        vector<bool> visited(V, false);
        function<void(int)> dfs = [&](int node){
            visited[node] = true;
            for(auto& next: adj[node]){
                if(!visited[next]){
                    dfs(next);
                }
            }
        };
        dfs(0);
        for(int i=0; i<V; i++){
            if(indegree[i] > 0){
                if(!visited[i]){
                    // separate components
                    return false;
                }
            }
        }
        return true;
    }
	int isEulerCircuit(int V, vector<int>adj[]){
	    // check for euler circuit
	    if(checkEulerCircuit(V, adj)) return 2;
	    
	    // check for euler path
	    if(checkEulerPath(V, adj)) return 1;
	    
	    return 0;
	}
};