// Leetcode 60

class Solution {
public:
    int compute(int n, vector<int>& fact){
        if(n==0) return fact[0] = 1;
        return fact[n] = n * compute(n-1, fact);
    }
    string getPermutation(int n, int k) {
        vector<int> fact(n+1, 0);
        compute(n, fact);
        set<int> st;
        for(int i=1; i<=n; i++) st.insert(i);
        k--;
        string ans = "";
        while(!st.empty()){
            int sz = st.size();
            int f = fact[sz-1];
            // compute index to take
            int ind = k / f;
            // compute remaining
            int rem = k % f;
            auto it = begin(st);
            advance(it, ind);
            // take the index
            ans.push_back((char)(*it + '0'));
            // erase the taken index
            st.erase(it);
            // update k for next steps
            k = rem;
        }
        return ans;
    }
};