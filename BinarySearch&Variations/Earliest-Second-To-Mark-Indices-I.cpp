// Leetcode 3048
// haphazard implementation (but works)
class Solution {
public:
    bool isPossible(vector<int>& nums, vector<int>& changeIndices, int mid){
        int n = nums.size(), m = changeIndices.size();
        vector<int> markIndices(n, -1);
        int marked_available = 0;
        for(int i=1; i<=mid; i++){
            if(markIndices[changeIndices[i-1]-1]==-1) marked_available++;
            markIndices[changeIndices[i-1]-1] = i-1;
        }
        if(marked_available < n) return false;    // all indices cannot be marked
        // sort the markIndices array -> as it will help us see which marking is done first
        sort(begin(markIndices), end(markIndices));
        int decrement_available = 0;
        int j=0;    // traverses over markIndices
        for(int i=1; i<=mid; i++){
            if(j < markIndices.size() && (i-1)==markIndices[j]){
                // marking index reached while traversing
                if(decrement_available < nums[changeIndices[i-1]-1]) return false;    // not possible to decrement
                decrement_available -= nums[changeIndices[i-1]-1];
                j++;
            }else if(j < markIndices.size() && (i-1)!=markIndices[j]){
                decrement_available++;
            }
        }
        return true;
    }
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        // binary search approach:
        int n = nums.size(), m = changeIndices.size();
        int low = 1, high = m;
        while(low <= high){
            int mid = low + ((high - low) >> 1);
            if(isPossible(nums, changeIndices, mid)){
                // can be solved for m seconds, hence true for >m seconds
                // check for lower
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return (low > m) ? -1 : low;
    }
};

// good implementation
class Solution {
public:
    bool isPossible(vector<int>& nums, vector<int>& changeIndices, int mid){
        int n = nums.size(), m = changeIndices.size();
        // find the largest time for each number in nums from changeIndices
        vector<int> largestTime(n, -1);
        int countOfIndices = 0;
        for(int time=0; time<mid; time++){
            if(largestTime[changeIndices[time]-1]==-1){
                countOfIndices++;
            }
            largestTime[changeIndices[time]-1] = time;
        }
        if(countOfIndices < n) return false;    // all indices not present in [0...mid] in changeIndices
        vector<pair<int, int>> largestTimeWithIndices;
        for(int i=0; i<n; i++) largestTimeWithIndices.push_back({largestTime[i], i});
        sort(begin(largestTimeWithIndices), end(largestTimeWithIndices));
        int used = 0;
        for(auto& p: largestTimeWithIndices){
            int req = nums[p.second] + 1;    // +1 as we need one more second to mark
            if(req + used > p.first + 1) return false;
            used += req;
        }
        return true;
    }
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        int n = nums.size(), m = changeIndices.size();
        int low = 1, high = m;
        while(low <= high){
            int mid = low + ((high - low) >> 1);
            if(isPossible(nums, changeIndices, mid)){
                // possible with time mid
                // check for lower time
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return (low > m) ? -1 : low;
    }
};