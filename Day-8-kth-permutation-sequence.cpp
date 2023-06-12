class Solution {
public:
    void solve(set<int>& s, vector<int>& fact, int k, string& ans){

        // base case
        if(k == 0){
            for(auto& e:s){
                ans.push_back((char)(e + '0'));
            }
            return;
        }

        if(s.size() == 0){
            return ;
        }

        int t = k;

        int f = fact[s.size()-1];

        int index = floor(t / (float)f);

        int next_k = t % f;

        auto it = s.begin();

        advance(it, index);

        int val = *(it);

        ans.push_back((char)(val + '0'));

        s.erase(val);

        solve(s, fact, next_k, ans);
    }
    string getPermutation(int n, int k) {
        set<int> s;
        vector<int> fact(n+1, 1);
        string ans = "";
        for(int i=1; i<=n; i++){
            s.insert(i);
            fact[i] = i * fact[i-1];
        }
        solve(s, fact, --k, ans);
        return ans;
    }
};