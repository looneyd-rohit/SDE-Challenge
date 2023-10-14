// Leetcode 2251

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        // approach: no. of flowers = total possible bloom - total died
        // total possible bloom = flowers that bloomed on or before given time t
        // total died = flowers that died before time t
        int n = flowers.size(), m = people.size();
        vector<int> bloom, died;
        for(int i=0; i<n; i++){
            bloom.push_back(flowers[i][0]);
            died.push_back(flowers[i][1]);
        }
        sort(begin(bloom), end(bloom));
        sort(begin(died), end(died));
        vector<int> ans(m, 0);
        for(int i=0; i<m; i++){
            int t = people[i];
            int b = upper_bound(begin(bloom), end(bloom), t) - begin(bloom);
            int d = lower_bound(begin(died), end(died), t) - begin(died);
            ans[i]=(b-d);
        }
        return ans;
    }
};