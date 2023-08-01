// Leecode 2697

class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int n = s.length();
        int i=-1, j=-1;
        if(n & 1){
            i = n/2 - 1; j = n/2 + 1;
        }else{
            i = n/2 - 1; j = n/2;
        }
        while(i>=0 && j<n){
            if(s[i]!=s[j]){
                if(s[i] > s[j]){
                    s[i] = s[j];
                }else{
                    s[j] = s[i];
                }
            }
            i--; j++;
        }
        return s;
    }
};