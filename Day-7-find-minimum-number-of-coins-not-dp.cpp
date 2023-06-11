#include <bits/stdc++.h> 
int findMinimumCoins(int amount) 
{
    // since answer always exists, so we don't need to use dp as dp checks
    // all possible ways --> more overhead
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int n = coins.size();
    int cnt = 0;
    for(int i=n-1; i>=1; i--){
        if(amount >= coins[i]){
            cnt += amount / coins[i];
            amount = amount % coins[i];
        }
    }
    if(amount > 0) cnt += amount;
    return cnt;
}
