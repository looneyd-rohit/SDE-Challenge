// Leetcode 149
// Basic Coordinate Geometry

class Solution {
public:
    vector<double> getSlope(vector<int>& p1, vector<int>& p2){
        int x1 = p1[0], y1 = p1[1];
        int x2 = p2[0], y2 = p2[1];
        if(x1 == x2) return {};
        return {((y2-y1) * 1.0)/(x2-x1)};
    }
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n <= 2) return n;
        int ans = 2;
        for(int i=0; i<n; i++){
            unordered_map<double, int> mp;
            unordered_map<int, int> mp2;
            for(int j=i+1; j<n; j++){
                auto slope = getSlope(points[i], points[j]);
                if(slope.empty()){
                    mp2[points[i][0]] += 1;
                }else{
                    mp[slope.back()] += 1;
                }
            }
            for(auto& e: mp) ans = max(ans, e.second+1);
            for(auto& e: mp2) ans = max(ans, e.second+1);
        }
        return ans;
    }
};