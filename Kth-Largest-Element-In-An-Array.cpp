// Leetcode 215
// [IMP]: Implementation of Quick Select Algorithm
class Solution {
public:
    int partition(int l, int r, vector<int>& nums){
        int i=l-1, pivot = nums[r];
        for(int j=l; j<=r; j++){
            if(nums[j] <= pivot){
                i++;
                swap(nums[i], nums[j]);
            }
        }
        return i;    // pivot index is returned
    }
    int quickSelect(int l, int r, vector<int>& nums, int k){
        if(l > r) return -1;
        int n = nums.size();
        int pivotIndex = partition(l, r, nums);
        if(n - k == pivotIndex) return nums[pivotIndex];
        else if(n - k > pivotIndex) return quickSelect(pivotIndex+1, r, nums, k);
        else return quickSelect(l, pivotIndex-1, nums, k);
    }
    int findKthLargest(vector<int>& nums, int k) {
        // implementing quick select algorithm to find the k-th largest/smallest element
        int n = nums.size();
        return quickSelect(0, n-1, nums, k);
    }
};