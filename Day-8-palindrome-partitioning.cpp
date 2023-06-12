class Solution {
public:
    bool isPalindrome(string& str){
        int n = str.size();
        for(int i=0; i<n/2; i++){
            if(str[i] != str[n-i-1]){
                return false;
            }
        }
        return true;
    }
    void solve(int index, string& str, vector<string>& temp, vector<vector<string>>& ans){
        // base case
        if(index >= str.size()){
            ans.push_back(temp);
            return ;
        }


        for(int i=index; i<str.size(); i++){
            string t = str.substr(index, i - index + 1);
            if(isPalindrome(t)){
                temp.push_back(t);
                solve(i + 1, str, temp, ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        vector<vector<string>> ans;
        solve(0, s, temp, ans);
        return ans;
    }
};