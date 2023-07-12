// Leetcode 587
// Convex Hull design problem

class Solution {
public:
    int slopeDifference(pair<int, int>& p1, pair<int, int>& p2, pair<int, int> p3){
        int x1 = p1.first, y1 = p1.second;
        int x2 = p2.first, y2 = p2.second;
        int x3 = p3.first, y3 = p3.second;
        
        return (y3-y2)*(x2-x1) - (y2-y1)*(x3-x2);
    }
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        // we will have to take only those that lie in the boundaries, forming a convex
        // structure
        // we will make use of slopes for this purpose
        int n = trees.size();
        sort(begin(trees), end(trees));
        vector<pair<int, int>> upperPoints, lowerPoints;
        
        for(int i=0; i<n; i++){
            auto point = trees[i];
            
            int u = upperPoints.size(), l = lowerPoints.size();
            
            // for upperPoints the slopeDifference is expected to be less than 0, but if it is > 0
            // we pop it
            while(u >= 2 && slopeDifference(upperPoints[u-2], upperPoints[u-1], {point[0], point[1]}) > 0){
                u--;
                upperPoints.pop_back();
            }
            
            // for lowerPoints the slopeDifference is expected to be more than 0, but if it is < 0
            // we pop it
            while(l >= 2 && slopeDifference(lowerPoints[l-2], lowerPoints[l-1], {point[0], point[1]}) < 0){
                l--;
                lowerPoints.pop_back();
            }
            
            upperPoints.push_back({point[0], point[1]});
            lowerPoints.push_back({point[0], point[1]});
        }
        
        set<pair<int, int>> st;
        for(auto& point: upperPoints) st.insert(point);
        for(auto& point: lowerPoints) st.insert(point);
        
        vector<vector<int>> ans;
        for(auto& point: st) ans.push_back({point.first, point.second});
        return ans;
    }
};