// Leetcode 1239
// Simple Recursion with BitMasking
class Solution {
public:
    int solve(int index, int mask, vector<pair<int, int>>& arr){
        // base case
        if(index >= arr.size()) return 0;
        
        // pick
        int pick = 0;
        int currMask = arr[index].first;
        if(!(mask & currMask)){
            pick = arr[index].second + solve(index+1, mask | currMask, arr);
        }
        
        // not pick
        int notPick = solve(index+1, mask, arr);
        
        return max(pick, notPick);
    }
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        vector<pair<int, int>> store;
        for(int i=0; i<n; i++){
            int mask = 0;
            for(int j=0; j<arr[i].size(); j++){
                if(mask & (1 << (arr[i][j]-'a'))){
                    mask = 0; break;
                }
                mask = mask | (1 << (arr[i][j]-'a'));
            }
            if(mask != 0) store.push_back({mask, arr[i].size()});
        }
        return solve(0, 0, store);
    }
};