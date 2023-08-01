// Leetcode 2178

class Solution {
public:
    bool solve(long long sum, long long prev, vector<long long>& temp, vector<long long>& ans){
        // base case
        if(sum == 0){
            if(ans.size() < temp.size()){
                ans = temp;
                return true;
            }
            return false;
        }
        
        // should be unique, so dependent on previous number taken
        // also maximum is to be found, so add up as small as possible, not the larger
        // so greedy type approach
        
        
        long long next = prev + 2;
        if(sum >= next){
            // take the next
            temp.push_back(next);
            if(solve(sum - next, next, temp, ans)) return true;
            temp.pop_back();
            if(solve(sum, next, temp, ans)) return true;
        }
        
        return false;
    }
    vector<long long> maximumEvenSplit(long long finalSum) {
        if(finalSum & 1) return {};
        vector<long long> temp, ans;
        solve(finalSum, 0, temp, ans);
        return ans;
    }
};