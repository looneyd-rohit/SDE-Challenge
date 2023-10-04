// Leetcode 2825

class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n1 = str1.length(), n2 = str2.length();
        int j=0;
        for(int i=0; i<n1 && j<n2; ){
            if(str1[i]==str2[j]){
                i++; j++;
            }else{
                if((str1[i]-'a'+1)%26 == (str2[j]-'a')){
                    i++; j++;
                }else{
                    i++;
                }
            }
        }
        if(j == n2) return true;
        return false;
    }
};