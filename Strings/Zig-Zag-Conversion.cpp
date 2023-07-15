// Leetcode 6

class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.length();
        if(n==1 || numRows==1) return s;
        string ans = "";
        for(int row=0; row<numRows; row++){
            int x = 2*numRows-2;
            for(int i=row; i<n; i+=x){
                ans.push_back(s[i]);
                if(row>0 && row<numRows-1 && (i+x-2*row)<n){
                    ans.push_back(s[i+x-2*row]);
                }
            }
        }
        return ans;
    }
};