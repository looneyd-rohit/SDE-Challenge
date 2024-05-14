// Leetcode 2000

// Approach: brute force
class Solution {
public:
    string reversePrefix(string word, char ch) {
        int n = word.size();
        int ind = n;
        for(int i=0; i<n; i++){
            if(word[i]==ch){
                ind = i;
                break;
            }
        }
        if(ind < n) reverse(begin(word), begin(word) + ind + 1);
        return word;
    }
};