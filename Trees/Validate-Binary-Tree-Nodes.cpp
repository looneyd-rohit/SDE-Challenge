// Leetcode 1361
// [IMP]
// Approach 1:
class Solution {
public:
    int dfs(int node, unordered_map<int, list<int>>& adj, vector<bool>& visited){
        visited[node] = true;
        int cnt = 1;
        for(auto& next: adj[node]){
            if(!visited[next]){
                cnt += dfs(next, adj, visited);
            }
        }
        return cnt;
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        // using binary tree property -->
        // first construct the tree as a graph
        // check that every child has atmost 2 child nodes (child to parent map)
        // then find the root --> element with no children
        // check if all are in a single component
        unordered_map<int, int> child_to_parent;
        unordered_map<int, list<int>> adj;
        for(int i=0; i<n; i++){
            int node = i, leftc = leftChild[i], rightc = rightChild[i];
            if(leftc!=-1){
                if(child_to_parent.find(leftc)==child_to_parent.end()){
                    child_to_parent[leftc] = node;
                    adj[node].push_back(leftc);
                }else{
                    return false;
                }
            }
            if(rightc!=-1){
                if(child_to_parent.find(rightc)==child_to_parent.end()){
                    child_to_parent[rightc] = node;
                    adj[node].push_back(rightc);
                }else{
                    return false;
                }
            }
        }
        int root = -1;
        for(int i=0; i<n; i++){
            if(child_to_parent.find(i)==child_to_parent.end()){
                if(root==-1) root = i;
                else return false; // more than one node present
            }
        }
        if(root == -1) return false;
        vector<bool> visited(n, false);
        return (dfs(root, adj, visited)==n);
    }
};

// Approach 2:
class DSU{
public:
    vector<int> parent, rank;
    DSU(int n=0){
        parent.resize(n+1); rank.resize(n+1);
        for(int i=0; i<=n; i++){
            parent[i] = i;
            rank[i] = 1;
        }
    }
    int findParent(int u){
        if(u==parent[u]) return u;
        return parent[u] = findParent(parent[u]);
    }
    bool unionCustom(int par, int chi){
        if(findParent(chi)!=chi) return false;    // parent already assigned (loop at random pos)

        if(findParent(par)==chi) return false;    // parent points to child (overall loop)

        parent[findParent(chi)] = findParent(par);

        return true;
    }
};
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        int components = n;
        DSU dsu(n);
        for(int i=0; i<n; i++){
            int node = i, leftc = leftChild[i], rightc = rightChild[i];
            if(leftc!=-1){
                if(!dsu.unionCustom(node, leftc)) return false;
                else components--;
            }
            if(rightc!=-1){
                if(rightc!=-1 && !dsu.unionCustom(node, rightc)) return false;
                else components--;
            }
        }
        return components==1;
    }
};