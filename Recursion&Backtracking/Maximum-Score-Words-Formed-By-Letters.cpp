// Leetcode 1255

// Approach: recursion + backtracking (subsets)
class Solution {
public:
    void generate(int i, int n, vector<string>& words, vector<string>& temp, vector<vector<string>>& subsets){
        if(i == n){
            if(temp.size() > 0) subsets.push_back(temp);
            return;
        }

        // take
        temp.push_back(words[i]);
        generate(i+1, n, words, temp, subsets);
        temp.pop_back();

        // not take
        generate(i+1, n, words, temp, subsets);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int n = words.size();
        vector<string> temp;
        vector<vector<string>> subsets;
        generate(0, n, words, temp, subsets);
        unordered_map<char, int> ump;
        for(auto& ch: letters) ump[ch]++;
        int maxi = 0;
        for(auto& ss: subsets){
            unordered_map<char, int> ump2;
            int curr = 0;
            bool flag = false;
            for(auto& word: ss){
                for(auto& ch: word){
                    ump2[ch]++;
                    if(ump2[ch] > ump[ch]){
                        curr = 0;
                        flag = true;
                        break;
                    }
                    curr += score[ch-'a'];
                }
                if(flag) break;
            }
            maxi = max(maxi, curr);
        }
        return maxi;
    }
};