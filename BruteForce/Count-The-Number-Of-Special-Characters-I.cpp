// Leetcode 3120

// Approach: brute force
class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();
        unordered_map<char, bool> ump;
        for(int i=0; i<n; i++){
            ump[word[i]] = true;
        }
        int count = 0;
        for(int i=0; i<26; i++){
            char ch1 = (char)(i+'a');
            char ch2 = (char)(i+'A');
            if(ump[ch1] && ump[ch2]){
                count++;
            }
        }
        return count;
    }
};