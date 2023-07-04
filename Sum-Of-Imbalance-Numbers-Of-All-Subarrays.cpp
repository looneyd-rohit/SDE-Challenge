// Leetcode 2763

class Solution {
public:
    int sumImbalanceNumbers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            int cnt = 0;
            set<int> s;
            s.insert(nums[i]);
            for(int j=i+1; j<n; j++){
                int begin = *s.begin(), rbegin = *s.rbegin();
                if(begin - nums[j] >= 0){
                    if(begin - nums[j] > 1){
                        cnt++;
                    }
                }else if(nums[j] - rbegin >= 0){
                    if(nums[j] - rbegin > 1){
                        cnt++;
                    }
                }else if(s.size() == 1){
                    // no imbalance possible
                }else{  
                    auto gt = s.lower_bound(nums[j]);
                    auto lt = --gt;
                    gt++;
                    int el = nums[j];
                    if(el == *gt){
                        // no change
                    }else if(el-*lt > 1 && *gt-el > 1){
                        cnt++;
                    }else if(el-*lt > 1 || *gt-el > 1){
                        // no change
                    }else{
                        // decrement
                        cnt--;
                    }
                }
                s.insert(nums[j]);
                ans += cnt;
            }
        }
        return ans > 0 ? ans : 0;
    }
};