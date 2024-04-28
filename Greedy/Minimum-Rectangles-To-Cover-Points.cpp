// Leetcode 3111

// Approach: greedy
class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        int n = points.size();
        set<int> st;
        for(int i=0; i<n; i++){
            st.insert(points[i][0]);
        }
        vector<int> v(begin(st), end(st));
        int mini = 1;
        int prev = v[0];
        for(int i=1; i<v.size(); i++){
            int curr = v[i];
            if(curr-prev <= w){
                // continue;
            }else{
                prev = curr;
                mini++;
            }
        }
        return mini;
    }
};