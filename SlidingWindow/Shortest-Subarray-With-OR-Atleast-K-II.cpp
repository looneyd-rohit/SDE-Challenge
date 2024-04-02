// Leetcode 3097

// Approach: khandani sliding window pattern
class Solution {
public:
    int minimumSubarrayLength(vector<int>& A, int k) {
        int n = A.size();
        int i=0, j=0;
        vector<int> h(31, 0);
        int my_mini = INT_MAX;
        while(j < n){
            int ee = A[j];
            int val = 0;
            for(int b=0; b<31; b++){
                if(ee & (1<<b)){
                    h[b]++;
                }
                if(h[b]>0)val = val | (1<<b);
            }
            
            if(val < k){
                j++;
            }else{
                my_mini = min(my_mini, j-i+1);
                while(i<=j && val>=k && j>=i){
                    my_mini = min(my_mini, j-i+1);
                    ee = A[i];
                    int v = 0;
                    for(int b=0; b<31; b++){
                        if(ee & (1<<b)){
                            h[b]--;
                        }
                        if(h[b]>0) v = v | (1<<b);
                    }
                    val = v;
                    i++;
                }
                j++;
            }
        }
        if(my_mini == INT_MAX) return -1;
        return my_mini;
    }
};