// Leetcode 3163

// Approach: brute force
class Solution {
public:
    string compressedString(string word) {
        int n = word.size();
        string ans = "";
        for(int i=0; i<n; i++){
            int len = 1;
            int j = i+1;
            for(; j<min(n, i+9); j++){
                if(word[j]!=word[j-1]){
                    break;
                }
                len++;
            }
            ans.push_back((char)(len+'0'));
            ans.push_back(word[i]);
            i = j-1;
        }
        return ans;
    }
};