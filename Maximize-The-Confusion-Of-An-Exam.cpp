// Leetcode 2024

class Solution {
public:
    int count(string& answerKey, int maxi, bool flag){
        int n = answerKey.length();
        int cnt = 0;
        int ans = n;
        // for true
        if(flag){
            int i = 0, j = 0;
            while(j<n){
                if(answerKey[j]=='F') cnt++;
                if(j-i+1 < maxi){
                    j++;
                }else if(j-i+1 == maxi){
                    ans = min(ans, cnt);
                    j++;
                }else if(j-i+1 > maxi){
                    if(answerKey[i]=='F') cnt--;
                    ans = min(ans, cnt);
                    i++;
                    j++;
                }
            }
            return ans;
        }else{
            int i = 0, j = 0;
            while(j<n){
                if(answerKey[j]=='T') cnt++;
                if(j-i+1 < maxi){
                    j++;
                }else if(j-i+1 == maxi){
                    ans = min(ans, cnt);
                    j++;
                }else if(j-i+1 > maxi){
                    if(answerKey[i]=='T') cnt--;
                    ans = min(ans, cnt);
                    i++;
                    j++;
                }
            }
            return ans;
        }
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.length();
        // search space --> maximum no. of true/false at the end
        int low = 0, high = n;
        while(low <= high){
            int mid = low + ((high - low) >> 1);
            int maxi = mid;
            int maxTrueOperations = count(answerKey, maxi, true);
            int maxFalseOperations = count(answerKey, maxi, false);
            if(maxTrueOperations <= k || maxFalseOperations <= k){
                // we can even get more trues/falses
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return high;
    }
};