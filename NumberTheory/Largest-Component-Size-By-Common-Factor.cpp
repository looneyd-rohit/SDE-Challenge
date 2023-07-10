// Leetcode 952

class Solution {
public:
    vector<int> parent, rank;
    void init(int n){
        parent.resize(n+1, 0);
        rank.resize(n+1, 0);
        for(int i=0; i<=n; i++) parent[i] = i;
    }

    int findParent(int u){
        // if found
        if(u == parent[u]) return u;
        // path compression
        return parent[u] = findParent(parent[u]);
    }

    void unionByRank(int u, int v){
        u = findParent(u);
        v = findParent(v);
        if(u == v) return;
        if(rank[u] == rank[v]){
            // both have same ranks, join one to any
            parent[v] = u;
            rank[u]++;
        }else if(rank[u] > rank[v]){
            // u is larger, join v to u
            parent[v] = u;
        }else{
            // v is larger, join u to v
            parent[u] = v;
        }
    }
    int largestComponentSize(vector<int>& nums) {
        // APPROACH: we cannot do a brute force way of taking two pairs and computing their intersection of
        // divisors because the test cases are too large and TLE will occur
        // Hence, one optimized approach is to form disjoint unions of all the divisors for each
        // number in nums[]. The array atmost has 1e4 nos. and divisors will lie in [2...sqrt(1e4)]
        // hence time ~ O(n * sqrt(n)) ~ 1e6 roughly
        
        // initialize the parent and rank
        init(1e5);
        int n = nums.size();
        for(int i=0; i<n; i++){
            int num = nums[i];
            // get all the divisors and form disjoint union of them (sieve like loop)
            for(int j=2; j*j<=num; j++){
                if((num % j) == 0){
                    // divisible
                    unionByRank(num, j); unionByRank(num, num/j);
                }
            }
        }
        // cout<<"ok"<<endl;

        // now traverse through the array and find the parents of each of them, and get the largest 
        // group having same parents
        unordered_map<int, int> parentCount;
        int maxi = 0;
        for(int i=0; i<n; i++){
            int num = nums[i];
            int p = findParent(num);
            parentCount[p]++;
            maxi = max(maxi, parentCount[p]);
        }
        return maxi;
    }
};