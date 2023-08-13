// https://www.codingninjas.com/studio/problems/climbing-the-leaderboard_842427?leftPanelTab=0

#include <bits/stdc++.h> 
vector<int> findPosition(vector<int> leaderboardScore, int n, vector<int> playerScore, int m) {
    vector<int> ans(m, -1);
    set<int> scores;
    for(int i=0; i<n; i++) scores.insert(leaderboardScore[i]);
    vector<int> arrScores(begin(scores), end(scores));
    for(int i=0; i<m; i++){
        int score = playerScore[i];
        auto it = lower_bound(begin(arrScores), end(arrScores), score);
        if(*it == score){
            ans[i] = arrScores.size() - (it - begin(arrScores));
        }else{
            ans[i] = arrScores.size() - (it - begin(arrScores)) + 1;
        }
    }
    return ans;
}
