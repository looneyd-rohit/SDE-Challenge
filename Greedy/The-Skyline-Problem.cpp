// Leetcode 218

// Approach [IMP]: Very nice set/multiset based observation based question

class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        if(a[0]!=b[0]) return a[0] < b[0];
        return a[1] > b[1];
    }
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        int n = buildings.size();
        vector<vector<int>> coordinates;
        for(int i=0; i<n; i++){
            // start point --> 0 flag
            coordinates.push_back({buildings[i][0], buildings[i][2], 0});
            // end point --> 1 flag
            coordinates.push_back({buildings[i][1], buildings[i][2], 1});
        }
        sort(begin(coordinates), end(coordinates));
        // cout<<coordinates.back()[0]<<", "<<coordinates.back()[1]<<endl;
        // when going from lower height (current height) to greater height, means 
        // encountering start point of new rectangle, then increase the height and
        // when reaching the end of current height rectangle, decrease the current
        // height.
        // basic logic, is to keep a pointer which is assumed to draw at each particular
        // height, and changes as rectangles come further
        multiset<int> heights;
        heights.insert(0);    // initial height is 0
        int initialHeight = 0;
        vector<vector<int>> ans;
        for(int i=0; i<coordinates.size(); i++){
            int x = coordinates[i][0], y = coordinates[i][1];
            int isEnd = coordinates[i][2];
            if(isEnd){
                // end point
                heights.erase(heights.find(y));
                if(initialHeight > *heights.rbegin()){
                    // surpassed the tallest building
                    ans.push_back({x, *heights.rbegin()});
                    initialHeight = *heights.rbegin();
                }
            }
            else{
                // start point
                heights.insert(y);
                if(initialHeight < *heights.rbegin()){
                    // add to skyline
                    ans.push_back({x, y});
                    // update max height
                    initialHeight = *heights.rbegin();
                }
            }
        }
        for(int i=0; i<ans.size()-1; i++){
            // erase same x diff height
            if(ans[i][0]==ans[i+1][0] && ans[i][1] < ans[i+1][1]){
                ans.erase(ans.begin()+i, ans.begin()+i+1);
                i--;
            }
        }
        return ans;
    }
};