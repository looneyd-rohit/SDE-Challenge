class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pivot = -1;
        for(int i=n-1; i>=1; i--){
            if(nums[i] > nums[i-1]){
                pivot = i;
                break;
            }
        }
        if(pivot == -1){
            reverse(begin(nums), end(nums));
        }else{
            int swapWith = n-1;
            for(int i=n-1; i>=pivot; i--){
                if(nums[i] > nums[pivot-1]){
                    swapWith = i;
                    break;
                }
            }
            swap(nums[pivot-1], nums[swapWith]);
            reverse(begin(nums) + pivot, end(nums));
        }
    }
};