// Leetcode 1535

class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        int maxi = *max_element(begin(arr), end(arr));
        if(k >= n) return maxi;
        int winner = arr[0], streak = 0;
        for(int i=1; i<n; i++){
            if(arr[i] > winner){
                winner = arr[i];
                streak = 1;
            }else{
                streak++;
            }
            if(streak==k || winner==maxi) return winner;
        }
        return winner;
    }
};