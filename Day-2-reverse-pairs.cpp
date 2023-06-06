class Solution {
public:
    int merge(int low, int mid, int high, vector<int>& nums){
        int size1 = mid - low + 1;
        int size2 = high - mid;
        int cnt = 0;
        int x=0, y=0;
        while(x<size1 && y<size2){
            if(nums[low+x] > 2*1LL*nums[mid+1+y]){
                cnt += (size1 - x);
                y++;
            }else{
                x++;
            }
        }
        sort(begin(nums)+low, begin(nums)+high+1);
        return cnt;
    }
    int mergeSort(int low, int high, vector<int>& nums){
        int cnt = 0;
        if(low < high){
            int mid = low + ((high - low) >> 1);
            cnt += mergeSort(low, mid, nums);
            cnt += mergeSort(mid+1, high, nums);
            cnt += merge(low, mid, high, nums);
        }
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        // similar to count inversions pattern
        int n = nums.size();
        return mergeSort(0, n-1, nums);
    }
};