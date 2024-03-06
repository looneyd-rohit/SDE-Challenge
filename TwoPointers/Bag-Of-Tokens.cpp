// Leetcode 948

class Solution {
public:
  int bagOfTokensScore(vector<int> &tokens, int power) {
    int n = tokens.size();
    sort(begin(tokens), end(tokens));
    int i = 0, j = n - 1;
    int score = 0, max_score = 0;
    while (i <= j) {
      // either increase score by decreasing power -> decrease by smaller amount
      // or decrease score by increasing power -> increase by larger amount
      if (power >= tokens[i]) {
        score++;
        max_score = max(max_score, score);
        power -= tokens[i];
        i++;
      } else if (score >= 1) {
        score--;
        power += tokens[j];
        j--;
      } else {
        break;
      }
    }
    return max_score;
  }
};