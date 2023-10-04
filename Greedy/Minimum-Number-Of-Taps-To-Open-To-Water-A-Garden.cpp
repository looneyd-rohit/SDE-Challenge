// Leetcode 1326
// [IMP]: Nice Pattern on Jumping/Greedy, similar to jump game ii
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int, int>> leftRightRange;
        for(int i=0; i<=n; i++){
            leftRightRange.push_back({max(0, i-ranges[i]), min(n, i+ranges[i])});
        }
        vector<int> store(n+1, 0);    // here the index is the leftRange and value is the
                                      // corresponding maximum right range 
        for(int i=0; i<=n; i++){
            int ind = leftRightRange[i].first;
            store[ind] = max(store[ind], leftRightRange[i].second);
        }
        int taps = 0, maxEnd = 0, currEnd = 0;
        for(int i=0; i<=n; i++){
            if(i > maxEnd) return -1;    // not possible to reach, the n-th point
            if(i > currEnd){
                // check if previous movement requires opening a tap
                taps++;
                currEnd = maxEnd;
            }
            maxEnd = max(maxEnd, store[i]);
        }
        return taps;
    }
};