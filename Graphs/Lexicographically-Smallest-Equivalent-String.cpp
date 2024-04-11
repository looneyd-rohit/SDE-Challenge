// Leetcode 1061

// Approach: DSU based approach
class DSU{
public:
    vector<int> parent;
    DSU(int n=0){
        this->parent.resize(26);
        for(int i=0; i<=25; i++){
            parent[i] = i;
        }
    }
    int findParent(int u){
        if(u == parent[u]) return u;
        // path compression
        return parent[u] = findParent(parent[u]);
    }
    void unionByRank(int u, int v){
        u = findParent(u);
        v = findParent(v);
        if(u == v) return;
        if(u > v){
            parent[u] = v;
        }else if(u < v){
            parent[v] = u;
        }else{
            parent[v] = u;
        }
    }
};

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.length(), m = baseStr.size();
        DSU *dsu = new DSU(n);
        for(int i=0; i<n; i++){
            dsu->unionByRank(s1[i]-'a', s2[i]-'a');
        }
        string ans = "";
        for(int i=0; i<m; i++){
            ans.push_back((char)(dsu->findParent(baseStr[i]-'a') + 'a'));
        }
        return ans;
    }
};