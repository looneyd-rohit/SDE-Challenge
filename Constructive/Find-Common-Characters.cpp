// Leetcode 1002

// Approach: find frequency of characters in each word and take minimum
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n = words.size();
        vector<string> ans;
        for(char ch='a'; ch<='z'; ch++){
            int mini = 1e9;
            for(auto& word: words){
                int cnt = 0;
                for(auto& c: word){
                    cnt += (c == ch);
                }
                mini = min(mini, cnt);
            }
            if(mini < 1e9){
                string str = "";
                str.push_back(ch);
                while(mini--){
                    ans.push_back(str);
                }
            }
        }
        return ans;
    }
};