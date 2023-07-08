// Leetcode 2382
// [IMP]: Kruskal's Modification (Modified DSU Rank by Sum)
class Solution {
public:
    int findParent(int u, vector<int>& parent){
        if(u == parent[u]) return u;
        // path compression
        return parent[u] = findParent(parent[u], parent);
    }
    void unionBySum(int u, int v, vector<int>& parent, vector<long long>& sum, long long& maxi){
        u = findParent(u, parent);
        v = findParent(v, parent);
        if(u == v) return;
        // we have to perform union no matter what, so we just form the union without
        // comparing ranks
        sum[u] += sum[v];
        maxi = max(maxi, sum[u]);
        parent[v] = u;
    }
    bool noNeighbours(int i, vector<bool>& visited){
        int n = visited.size();
        if(n==1) return true;    // size 1 array
        else if(i==0 && (i+1<n) && visited[i+1]==0) return true;    // size 2 array
        else if(i==n-1 && (i-1>=0) && visited[i-1]==0) return true;    // size 2 array
        else if(i>0 && i<n-1 && visited[i-1]==0 && visited[i+1]==0) return true;    // size 3 or more array
        return false;
    }
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
        // reverse Union Find
        int n = nums.size();
        vector<int> parent(n, 0);
        for(int i=0; i<n; i++) parent[i] = i;
        vector<long long> sum(n, 0);
        for(int i=0; i<n; i++) sum[i] = nums[i];
        // visited array to keep track which are already added and take decisions 
        // based on it on how to add current val to parent
        vector<bool> visited(n, 0);
        vector<long long> ans(n, 0);
        long long maxi = 0;
        for(int i=n-1; i>=0; i--){
            ans[i] = maxi;
            int indOfNums = removeQueries[i];
            visited[indOfNums] = true;
            // if none of the neighbours are visited, then when the current val gets added
            // we cannot merge it with any neighbour, hence we take max with element itself
            if(noNeighbours(indOfNums, visited)) maxi = max(maxi, 1LL*nums[indOfNums]);
            else{
                // if neighbours are visited
                if(indOfNums>0 && visited[indOfNums-1]==1){
                    unionBySum(indOfNums, indOfNums-1, parent, sum, maxi);
                }
                if(indOfNums<n-1 && visited[indOfNums+1]==1){
                    unionBySum(indOfNums, indOfNums+1, parent, sum, maxi);
                }
            }
        }
        return ans;
    }
};