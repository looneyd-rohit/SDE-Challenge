// Leetcode 1921

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<double> times(n, 0);
        for(int i=0; i<n; i++){
            times[i] = (dist[i] / (double)speed[i]);
        }
        sort(begin(times), end(times));
        int cnt = 1, timer = 1;
        for(int i=1; i<n; i++){
            int diff = times[i] - timer;
            if(times[i] - timer <= 0){
                return cnt;
            }
            // kill the monster
            cnt++;
            // recharge the weapon
            timer++;
        }
        return cnt;
    }
};