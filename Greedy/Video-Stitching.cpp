// Leetcode 1024

// Approach [IMP]: Nice Greedy Pattern, similar to jump game ii, min taps to water garden etc.
class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        int n = clips.size();
        sort(begin(clips), end(clips));
        vector<int> store(101, 0);    // stores left range as index and corresponding maximum right
                              // range as the value
        for(int i=0; i<n; i++){
            int ind = clips[i][0];
            store[ind] = max(store[ind], clips[i][1]);
        }
        int count = 0, maxEnd = 0, currEnd = 0;
        for(int i=0; i<=time; i++){
            if(i > maxEnd) return -1;
            if(i > currEnd){
                count++;
                currEnd = maxEnd;
            }
            maxEnd = max(maxEnd, store[i]);
        }
        return count;
    }
};