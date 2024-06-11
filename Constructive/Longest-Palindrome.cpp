// Leetcode 409

// Approach: take out all the even length sequences of every character and at last only add 1 if odd sequence is present
class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.length();
        vector<int> freq(52, 0);
        for(auto& ch: s){
            if(ch>='a' && ch<='z') freq[ch-'a']++;
            else freq[26+ch-'A']++;
        }
        int odd_max = 0, len = 0;
        for(auto& e: freq){
            if(e & 1){
                len += e - 1;
                odd_max = 1;
            }else{
                len += e;
            }
        }
        return len + odd_max;
    }
};