// Leetcode 2559

class Solution {
public:
    bool checkValid(string& str){
        string vowels = "aeiou";
        bool front = false;
        for(auto& ch: vowels) if(ch == str.front()){ front = true; break;};
        if(!front) return false;
        bool back = false;
        for(auto& ch: vowels) if(ch == str.back()){ back = true; break;};
        return back;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        // i am guessing a static range sum query approach:
        // but since this is a sum, it can also be solved using prefix sum
        int n = words.size(), q = queries.size();
        vector<int> values(n, 0);
        for(int i=0; i<n; i++){
            if(checkValid(words[i])){
                values[i] = 1;
            }
            if(i > 0) values[i] += values[i-1];
        }
        vector<int> ans(q, 0);
        for(int i=0; i<q; i++){
            int l = queries[i][0], r = queries[i][1];
            ans[i] = values[r] - ((l > 0) ? values[l-1] : 0);
        }
        return ans;
    }
};