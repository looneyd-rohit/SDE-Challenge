// Leetcode 1310

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        // prefix xor array can do the job
        int n = arr.size();
        vector<int> prefixXor(n, 0);
        prefixXor[0] = arr[0];
        for(int i=1; i<n; i++){
            prefixXor[i] = prefixXor[i-1] ^ arr[i];
        }
        int q = queries.size();
        vector<int> ans;
        for(int i=0; i<q; i++){
            int r = prefixXor[queries[i][1]];
            int l = 0;
            if(queries[i][0] > 0){
                l = prefixXor[queries[i][0]-1];
            }
            ans.push_back(r^l);
        }
        return ans;
    }
};