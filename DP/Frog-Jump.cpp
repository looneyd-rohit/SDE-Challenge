// Leetcode 403

class Solution {
public:
    bool solve(int index, int prevStep, unordered_map<int, bool>& pos, int& destination, unordered_map<int, unordered_map<int, bool>>& dp){
        // base cases
        // if index does not have a stone in it then return false
        if(pos[index]!=true) return false;
        // if index is destination or greater then already reached
        if(index >= destination) return true;


        // dp check
        if(dp.find(index)!=dp.end()){
            if(dp[index].find(prevStep)!=dp[index].end()){
                if(dp[index][prevStep]!=-1) return dp[index][prevStep];
            }
        }
        
        bool ans = false;
        for(int i=-1; i<=1; i++){
            int nextStep = prevStep + i;
            if(nextStep <= 0) continue;
            ans = ans | solve(index + nextStep, nextStep, pos, destination, dp);
        }

        return dp[index][prevStep] = ans;
    }
    bool canCross(vector<int>& stones) {
        unordered_map<int, bool> pos;
        for(auto& s: stones) pos[s] = true;
        int destination = stones.back();
        // vector<vector<int>> dp(destination+1, vector<int>(destination+1, -1));
        // dp array relies on index and prevStep, since index can go as large as 2^31 - 1, so we can't
        // make an array of that size, hence better to use another hashmap
        unordered_map<int, unordered_map<int, bool>> dp;
        return solve(1, 1, pos, destination, dp);
    }
};