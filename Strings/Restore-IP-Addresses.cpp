// Leetcode 93

class Solution {
public:
    int compute(string& s, int l, int r){
        bool zero = false;
        if(s[l]=='0') zero = true;
        int n = 0;
        for(int i=l; i<=r; i++){
            if(s[i]>='0' && s[i]<='9'){
                n = n*10 + (s[i]-'0');
            }else{
                return 420;
            }
        }
        if(zero && n!=0) return 420;
        return n;
    }
    void solve(int index, string& s, int n, int dots, string temp, vector<string>& ans){
        // base case
        if(index >= n){
            if(temp.back()=='.' && dots==4){
                temp.pop_back();
                ans.push_back(temp);
                temp.push_back('.');
            }
            return;
        }
        
        if(dots >= 4) return;
        
        
        // from current index, we can make atmost 3 calls
        
        // length 1
        int num = compute(s, index, index);
        if(num >= 0 && num <= 255){
            temp.push_back(s[index]);
            temp.push_back('.');
            solve(index+1, s, n, dots+1, temp, ans);
            temp.pop_back();
            temp.pop_back();
        }
        
        if(index+1 < n){
            int num2 = compute(s, index, index+1);
            if(num2 > 0 && num2 <= 255){
                temp.push_back(s[index]);
                temp.push_back(s[index+1]);
                temp.push_back('.');
                solve(index+2, s, n, dots+1, temp, ans);
                temp.pop_back();
                temp.pop_back();
                temp.pop_back();
            }
        }
        
        if(index+2 < n){
            int num3 = compute(s, index, index+2);
            if(num3 > 0 && num3 <= 255){
                temp.push_back(s[index]);
                temp.push_back(s[index+1]);
                temp.push_back(s[index+2]);
                temp.push_back('.');
                solve(index+3, s, n, dots+1, temp, ans);
                temp.pop_back();
                temp.pop_back();
                temp.pop_back();
                temp.pop_back();
            }
        }
        
    }
    vector<string> restoreIpAddresses(string s) {
        int n = s.length();
        string temp = "";
        vector<string> ans;
        solve(0, s, n, 0, temp, ans);
        return ans;
    }
};