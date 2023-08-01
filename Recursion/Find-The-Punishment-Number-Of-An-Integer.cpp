// Leetcode 2698

class Solution {
public:
    bool isPossible(int index, int sum, string& s, int n){
        // base case
        if(index >= s.length()){
            return (sum == n);
        }
        bool flag = false;
        for(int i=index; i<s.length(); i++){
            string temp = s.substr(index, i-index+1);
            int num = stoi(temp);
            flag = flag || isPossible(i+1, sum+num, s, n);
        }
        return flag;
    }
    int punishmentNumber(int n) {
        int ans = 0;
        for(int i=1; i<=n; i++){
            int sq = i * i;
            string str = to_string(sq);
            bool flag = isPossible(0, 0, str, i);
            if(flag){
                ans += i*i;
            }
        }
        return ans;
    }
};