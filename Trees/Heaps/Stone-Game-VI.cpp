// Leetcode 1686
// [IMP]: Nice question on sorting, nice logic, not only focus on maximizing alice's score
// but also focus on maximizing difference between them
class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();
        // when we choose something for alice, it not only adds it to alice but also
        // prevents bob from having the same index stone, so our focus should be to
        // increase the the amount by which they differ and when it's same then take
        // max of alice's score
        vector<vector<int>> stones;
        for(int i=0; i<n; i++){
            stones.push_back({aliceValues[i]+bobValues[i], aliceValues[i], bobValues[i]});
        }
        sort(begin(stones), end(stones), greater<vector<int>>());
        int aliceScore = 0, bobScore = 0;
        for(int i=0; i<n; i++){
            if(!(i & 1)){
                aliceScore += stones[i][1];
            }else{
                bobScore += stones[i][2];
            }
        }
        if(aliceScore > bobScore) return 1;
        else if(aliceScore < bobScore) return -1;
        return 0;
    }
};