// https://www.codingninjas.com/studio/problems/batch-photography_2279824?leftPanelTab=0

#include<bits/stdc++.h>
using namespace std;

int dp[(int)1e4+1];
int solve(int index, int n, int k, vector<int> &photos){
    // base case
    if(index >= n){
        return 0;
    }

    // dp check
    if(dp[index]!=-1) return dp[index];

    // take atleast k-photos, in current batch, then recur
    // for the next set of photos, in the next batch
    int error = 2e9;
    for(int i=index; i<n; i++){
        if(i-index+1 >= k){
            int current_error = photos[i] - photos[index];
            error = min(error, max(current_error, solve(i+1, n, k, photos)));
        }
    }
    return dp[index] = error;
}
int photography(int n, int k, vector<int> &photos) {
    sort(begin(photos), end(photos));
    // solve() --> returns the min error
    // memoization:
    memset(dp, -1, sizeof(dp));
    return solve(0, n, k, photos);
}