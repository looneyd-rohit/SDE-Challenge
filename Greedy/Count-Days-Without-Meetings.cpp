// Leetcode 3169

// Approach: sort + merge intervals
class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n = meetings.size();
        sort(begin(meetings), end(meetings));
        int start = meetings[0][0], end = meetings[0][1];
        vector<vector<int>> new_meet;
        for(int i=1; i<n; i++){
            if(meetings[i][0]<=end){
                end = max(end, meetings[i][1]);
            }else{
                new_meet.push_back({start, end});
                start = meetings[i][0];
                end = meetings[i][1];
            }
        }
        new_meet.push_back({start, end});
        int count = 0;
        for(auto& e: new_meet){
            count += e[1] - e[0] + 1;
        }
        return (days - count);
    }
};