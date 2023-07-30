// Leetcode 2594
// [IMP]: Binary Search Division Approach

class Solution {
public:
    long long compute(vector<int>& ranks, long long maxTime){
        int r = ranks.size();
        long long cnt = 0;
        for(int i=0; i<r; i++){
            cnt += sqrt((maxTime * 1.0) / ranks[i]);
        }
        return cnt;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        int r = ranks.size();
        long long low = 1, high = 1e14;
        while(low <= high){
            long long mid = low + ((high - low) >> 1);
            long long maxTime = mid;
            long long c = compute(ranks, maxTime);
            if(c >= cars){
                // possible in this time --> decrease time
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return low;
    }
};