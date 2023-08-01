// Leetcode 2660

class Solution {
public:
    int calculateScore(vector<int>& player){
        int n = player.size();
        int score = 0;
        for(int i=0; i<n; i++){
            score += player[i];
            if((i>0 && player[i-1]>=10) || (i>1 && player[i-2]>=10)){
                score += player[i];
            }
        }
        return score;
    }
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int score1 = calculateScore(player1);
        int score2 = calculateScore(player2);
        if(score1 > score2) return 1;
        else if(score1 < score2) return 2;
        return 0;
    }
};