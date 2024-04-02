// Leetcode 58

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        s.push_back((char)(32));
        n++;
        int i = 0, j = 0;
        int last = 0;
        while(j < n){
            if(s[j]==' '){
                last = j-i;
                while(j < n && s[j]==' '){
                    j++;
                }
                i = j;
            }else{
                j++;
            }
        }
        return last;
    }
};