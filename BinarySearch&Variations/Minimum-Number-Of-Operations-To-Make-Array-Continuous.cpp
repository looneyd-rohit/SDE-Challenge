// Leetcode 2009

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        // brute: choose a start index, then add n-1 to it, now that start+n-1=end index
        // now traverse the nums array to find the no of elements not between start and
        // end which gives the no. of operations
        // since start is variable: T.C. ~ O(n*n)
        // optimized: apply binary search type logic to get the count of operations
        // (make array elements unique)
        set<int> st(begin(nums), end(nums));
        vector<int> arr(begin(st), end(st));
        int mini = n;
        for(int i=0; i<arr.size(); i++){
            int startVal = arr[i];
            int endVal = startVal + n - 1;

            int justEndSeBadaInd = upper_bound(begin(arr)+i, end(arr), endVal) - begin(arr);
            int operations = i + (n-justEndSeBadaInd);

            mini = min(mini, operations);
        }
        return mini;
    }
};