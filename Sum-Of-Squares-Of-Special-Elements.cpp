// Leetcode 2778

class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=1; i*i<=n; i++){
            if((n % i) == 0){
                sum += pow(nums[i-1], 2);
                if(i != n/i) sum += pow(nums[(n/i)-1], 2);
            }
        }
        return sum;
    }
};