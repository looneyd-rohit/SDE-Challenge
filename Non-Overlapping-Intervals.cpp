// Leetcode 435

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        // since we have to make them non overlapping, a sorted order based on start index
        // will help us
        sort(begin(intervals), end(intervals));
        int startInterval = intervals[0][0], endInterval = intervals[0][1];
        int count = 0;
        for(int i=1; i<n; i++){
            int currentStart = intervals[i][0], currentEnd = intervals[i][1];
            if(currentStart < endInterval){
                // overlapping occurs
                // delete the one which has greater end time
                // keep the one with smaller end time
                endInterval = min(endInterval, currentEnd);
                count++;
            }else{
                // no overlapping
                // update intervals
                startInterval = currentStart; endInterval = currentEnd;
            }
        }
        return count;
    }
};