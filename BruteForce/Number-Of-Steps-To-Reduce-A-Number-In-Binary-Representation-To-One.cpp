// Leetcode 1404

// Approach: simple while loop
class Solution {
public:
    int numSteps(string s) {
        int n = s.length();
        int cnt = 0;
        while(s.length() > 1){
            if(s.back() == '1'){
                int j = s.length()-1;
                while(j>=0 && s[j]=='1') s[j]='0', j--;
                if(j!=-1) s[j] = '1';
                else s = "1" + s;
            }else{
                s = s.substr(0, s.length()-1);
            }
            cnt++;
        }
        return cnt;
    }
};