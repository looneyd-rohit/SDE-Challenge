// Leetcode 1519
// DFS plain with modifications (Brute Force: since every subtree return vector of 26)
// more space required
class Solution {
public:
    vector<int> dfs(int node, unordered_map<int, list<int>>& adj, string& labels, vector<bool>& visited, vector<int>& store){
        visited[node] = true;
        vector<int> ans(26, 0);
        for(auto& next: adj[node]){
            if(!visited[next]){
                auto temp = dfs(next, adj, labels, visited, store);
                for(int k=0; k<26; k++){
                    ans[k] += temp[k];
                }
            }
        }
        ans[labels[node]-'a'] += 1;
        store[node] = ans[labels[node]-'a'];
        return ans;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        unordered_map<char, int> freq;
        for(int i=0; i<n; i++) freq[labels[i]]++;
        // construct the graph
        unordered_map<int, list<int>> adj;
        for(auto& edge: edges){
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(n, false);
        vector<int> store(n, 0);
        // dfs from root which is node 0
        dfs(0, adj, labels, visited, store);
        return store;
    }
};

// Optimized: slight changes
class Solution {
public:
    void dfs(int node, unordered_map<int, list<int>>& adj, string& labels, vector<bool>& visited, vector<int>& count, vector<int>& store){
        visited[node] = true;
        int countBeforeNode = count[labels[node]-'a'];
        // increment count
        count[labels[node]-'a']++;
        for(auto& next: adj[node]){
            if(!visited[next]){
                dfs(next, adj, labels, visited, count, store);
            }
        }
        int countAfterVisitingChilds = count[labels[node]-'a'];
        store[node] = countAfterVisitingChilds - countBeforeNode;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        // optimized: we can remove the O(26) loop inside by applying a bit of logic
        unordered_map<char, int> freq;
        for(int i=0; i<n; i++) freq[labels[i]]++;
        // construct the graph
        unordered_map<int, list<int>> adj;
        for(auto& edge: edges){
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(n, false);
        vector<int> store(n, 0);
        vector<int> count(26, 0);
        // dfs from root which is node 0
        dfs(0, adj, labels, visited, count, store);
        return store;
    }
};