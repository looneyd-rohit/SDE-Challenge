// Leetcode 75

// Approach (old): DNF algorithm (3 pointers)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        // we will keep three pointers to solve this problem
        // i --> last index where 0 is present
        // j --> movable index which traverses array --> at end j points to last index of 1
        // k --> first index where 2 is present
        int n = nums.size();
        int i=-1, j=0, k=n;
        while(i<j && j<k){
            if(nums[j] == 1){
                // do nothing, just skip
            }else if(nums[j] == 0){
                swap(nums[i+1], nums[j]);
                i++;
            }else if(nums[j] == 2){
                swap(nums[k-1], nums[j]);
                // we do j-- since [j..k] part of array is not visited so we don't know
                // 0 or 1 may be present at k-1 
                j--;
                k--;
            }
            j++;
        }
    }
};

// Approach (new): dnf algorithm (3 pointers)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int zero = -1, two = n;
        for(int one=0; one<two; one++){
            if(nums[one]==1){
                // continue
            }else if(nums[one]==0){
                // swap with zero
                zero++;
                swap(nums[zero], nums[one]);
            }else if(nums[one]==2){
                two--;
                swap(nums[one], nums[two]);
                one--;
            }
        }
    }
};