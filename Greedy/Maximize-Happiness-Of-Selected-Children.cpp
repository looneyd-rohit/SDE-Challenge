// Leetcode 3075

// Approach: sort + choose k
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n = happiness.size();
        long long maxi = 0;
        sort(begin(happiness), end(happiness));
        int decrement = 0;
        for(int i=n-1; i>=0; i--){
            int h = happiness[i];
            // cout<<h<<endl;
            if(k > 0){
                maxi += max(0, h - decrement);
                decrement++;
                k--;
            }
        }
        return maxi;
    }
};