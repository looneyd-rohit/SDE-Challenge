// Leetcode 3121

// Approach: hashmap based easy approach
class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();
        unordered_map<char, int> ump;
        for(int i=0; i<n; i++){
            char ch = word[i];
            if(ch>='A' && ch<='Z'){
                ump[ch] = 1;
            }else if(ch>='a' && ch<='z'){
                char temp = (char)(ch-'a' + 'A');
                if(ump[temp]){
                    ump[temp] = -1;
                    ump[ch] = -1;
                }else{
                    ump[ch] = 1;
                }
            }
        }
        int count = 0;
        for(int i=0; i<26; i++){
            char ch1 = (char)(i+'a');
            char ch2 = (char)(i+'A');
            if((ump[ch1]==1) && (ump[ch2]==1)){
                count++;
            }
        }
        return count;
    }
};