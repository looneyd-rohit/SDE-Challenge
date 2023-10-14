// Leetcode 1095

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findPeak(MountainArray &mountainArr){
        int n = mountainArr.length();
        int low = 1, high = n-2;
        while(low <= high){
            int mid = low + ((high-low)>>1);
            int prev = mountainArr.get(mid-1);
            int val = mountainArr.get(mid);
            int next = mountainArr.get(mid+1);
            if(val>prev && val>next) return mid;
            else if(val>prev) low = mid + 1;
            else high = mid - 1;
        }
        return n;
    }
    int customBinarySearch(MountainArray &mountainArr, int l, int r, int target, bool dir=true){
        int n = mountainArr.length();
        int low = l, high = r;
        while(low <= high){
            int mid = low + ((high-low)>>1);
            int val = mountainArr.get(mid);
            if(val==target) return mid;
            if(dir){
                if(val>target) high = mid - 1;
                else low = mid + 1;
            }else{
                if(val>target) low = mid + 1;
                else high = mid - 1;
            } 
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int peakIndex = findPeak(mountainArr);
        cout<<peakIndex<<endl;
        // search in left half
        int res = -1;
        if((res = customBinarySearch(mountainArr, 0, peakIndex-1, target))!=-1){
            return res;
        }
        // search in right half
        return customBinarySearch(mountainArr, peakIndex, n-1, target, false);
    }
};