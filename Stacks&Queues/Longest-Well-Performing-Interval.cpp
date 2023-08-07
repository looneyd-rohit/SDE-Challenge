// Leetcode 1124
// Approach 1: Hashmap based
class Solution {
public:
    int longestWPI(vector<int>& hours) {
        // i am guessing sliding window to be applicable
        int n = hours.size();
        for(int i=0; i<n; i++){
            if(hours[i] > 8) hours[i] = 1;
            else hours[i] = -1;
        }
        int sum = 0, maxi = 0;
        unordered_map<int, int> hash;
        for(int i=0; i<n; i++){
            sum += hours[i];
            if(sum > 0){
                maxi = max(maxi, i+1);
            }else{
                // find the lowest sum-1 index
                if(hash.find(sum-1)!=hash.end()){
                    maxi = max(maxi, i-hash[sum-1]);
                }
            }

            // add to map if doesn't exist
            if(hash.find(sum)==hash.end()) hash[sum] = i;
        }
        return maxi;
    }
};

// Approach 2: stack based
class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n = hours.size() ;
        vector<int>preSum ;
        int sum = 0 ;
        preSum.push_back(sum) ;
        for(int i = 0; i < n ; i++){
            if(hours[i] > 8)
                sum += 1 ;
            else 
                sum += -1 ;
            preSum.push_back(sum) ;
        }
        
        stack<int>stk ;
        for(int i = 0; i <= n; i++){
            if(stk.empty() || preSum[i] < preSum[stk.top()])
                stk.push(i) ;
        }
        
        int ret = 0 ;
        for(int i = n; i >= 0; i--){
            while(!stk.empty() && preSum[i] > preSum[stk.top()])
            {
                ret = max(ret, i - stk.top()) ;
                stk.pop() ;
            }
        }
        return ret ;
    }
};