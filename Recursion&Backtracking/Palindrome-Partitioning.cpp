class Solution {
public:
    bool isPalindrome(string& str){
        int n = str.length();
        for(int i=0; i<(n>>1); i++){
            if(str[i] != str[n-1-i]){
                return false;
            }
        }
        return true;
    }
    void solve(int i, int n, string& s, vector<string>& temp, vector<vector<string>>& ans){
        if(i == n){
            if(temp.size() > 0) ans.push_back(temp);
            return ;
        }

        for(int ind=i; ind<n; ind++){
            string str = s.substr(i, ind-i+1);
            if(isPalindrome(str)){
                temp.push_back(str);
                solve(ind+1, n, s, temp, ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<string> temp;
        vector<vector<string>> ans;
        solve(0, n, s, temp, ans);
        return ans;
    }
};