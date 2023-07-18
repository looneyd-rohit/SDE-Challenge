// Leetcode 973

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        // maxheap will help us
        priority_queue<pair<double, int>> maxheap;
        for(int i=0; i<n; i++){
            int x = points[i][0], y = points[i][1];
            double dist = sqrt(pow(x, 2) + pow(y, 2));
            maxheap.push({dist, i});
            if(maxheap.size() > k) maxheap.pop();
        }
        vector<vector<int>> ans;
        while(!maxheap.empty()){
            ans.push_back(points[maxheap.top().second]);
            maxheap.pop();
        }
        return ans;
    }
};