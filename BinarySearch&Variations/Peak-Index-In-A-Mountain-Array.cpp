// Leetcode 852
// Typical Binary Search
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        // since mountain always exists, so skew mountain (only increasing/decreasing) does not
        // exists, so the seach space is bound to be in between except the first and the last
        // element
        int low = 1, high = n-2;
        while(low <= high){
            int mid = low + ((high - low) >> 1);
            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
                return mid;
            }else if(arr[mid]>arr[mid-1]){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return -1;
    }
};