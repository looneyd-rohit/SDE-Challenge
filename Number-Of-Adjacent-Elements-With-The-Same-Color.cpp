// Leetcode 2672

class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        int q = queries.size();
        vector<int> colors(n, 0);
        vector<int> ans(q, 0);
        int count = 0;
        for(int i=0; i<q; i++){
            int index = queries[i][0], color = queries[i][1];
            // since we are going to color the i-th index with new color
            // check if it already shares same colors with adjacents
            if(colors[index]!=0){
                if(index > 0 && colors[index-1]==colors[index]) count--;
                if(index < n-1 && colors[index+1]==colors[index]) count--;
            }
            // place new color
            colors[index] = color;
            // check for adjacency
            if(index > 0 && colors[index-1]==colors[index]) count++;
            if(index < n-1 && colors[index+1]==colors[index]) count++;
            // store answer
            ans[i] = count;
        }
        return ans;
    }
};