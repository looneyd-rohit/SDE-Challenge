// Leetcode 2997

// Approach: just count set bits in all the numbers
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> freq(31, 0);
        for(int i=0; i<n; i++){
            int e = nums[i];
            for(int bit=0; bit<=30; bit++){
                if(e & (1<<bit)){
                    freq[bit]++;
                    freq[bit] %= 2;
                }
            }
        }
        int count = 0;
        for(int bit=0; bit<=30; bit++){
            if(!(k & (1<<bit)) != !(freq[bit])){
                count++;
            }
        }
        return count;
    }
};