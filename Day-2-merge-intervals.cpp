class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(begin(intervals), end(intervals));
        vector<vector<int>> ans;
        int i = 1;
        int start = intervals[0][0], end = intervals[0][1];
        while(i<n){
            int new_start = intervals[i][0], new_end = intervals[i][1];
            if(new_start <= end){
                end = max(end, new_end);
            }else{
                vector<int> temp;
                temp.push_back(start);
                temp.push_back(end);
                ans.push_back(temp);
                start = new_start;
                end = new_end;
            }
            i++;
        }
        vector<int> temp;
        temp.push_back(start);
        temp.push_back(end);
        ans.push_back(temp);
        return ans;
    }
};