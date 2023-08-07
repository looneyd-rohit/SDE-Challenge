// Leetcode 959
// [IMP]: DSU very unique application
class DSU{
public:
    vector<int> parent;
    vector<int> rankArr;

    DSU(int n=0){
        parent.resize(n+1); rankArr.resize(n+1);
        for(int i=1; i<=n; i++){
            parent[i] = i;
            rankArr[i] = 1;
        }
    }

    int findParent(int u){
        if(u == parent[u]) return u;
        // path compression
        return parent[u] = findParent(parent[u]);
    }

    bool unionSet(int u, int v){
        u = findParent(u);
        v = findParent(v);
        if(u == v) return false;
        if(rankArr[u]==rankArr[v]){
            parent[v] = u;
            rankArr[u]++;
        }else if(rankArr[u]<rankArr[v]){
            parent[u] = v;
        }else{
            parent[v] = u;
        }
        return true;
    }
};
class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        // very tricky problem: use DSU to join the points, rather than lines,
        // think of it from points perspective, a nxn grid has (n+1)x(n+1) points
        // try to join those points together
        int n = grid.size();
        // init the DSU --> with total no. of points
        int points = (n+1) * (n+1);
        DSU dsu(points);
        // connect the boundary points at first
        for(int i=0; i<n+1; i++){
            // first row
            if(i==0){
                for(int j=0; j<n; j++) dsu.unionSet(j, j+1);
            }

            dsu.unionSet(0, i*(n+1)+0);
            dsu.unionSet(n, i*(n+1)+n);

            // last row
            if(i==n){
                for(int j=0; j<n; j++) dsu.unionSet(i*(n+1)+j, i*(n+1)+j+1);
            }

        }

        int ans = 1;
        // now connect the points due to slashes
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]=='/'){
                    // connect [i, j+1] and [i+1, j]
                    if(!dsu.unionSet(i*(n+1)+j+1, (i+1)*(n+1)+j)) ans++;
                }else if(grid[i][j]=='\\'){
                    // connect [i, j] and [i+1, j+1]
                    if(!dsu.unionSet(i*(n+1)+j, (i+1)*(n+1)+j+1)) ans++;
                }
            }
        }
        return ans;
    }
};