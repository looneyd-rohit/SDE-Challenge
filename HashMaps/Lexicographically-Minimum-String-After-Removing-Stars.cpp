// Leetcode 3170

// Approach: map + set based approach
class Solution {
public:
    string clearStars(string s) {
        int n = s.length();
        map<char, set<int>> chodu; unordered_set<int> d;
        for(int i=0; i<n; i++){
            char chara = s[i];
            if(chara!='*'){
                chodu[chara].insert(i);
            }else{
                d.insert(i);
                auto it = chodu.begin();
                char prev = it->first;
                auto it2 = it->second.rbegin();
                int ind = *it2;
                chodu[prev].erase(ind);
                d.insert(ind);
                if(chodu[prev].empty()) chodu.erase(prev);
            }
        }
        string res = "";
        for(int i=0; i<n; i++){
            if(!d.count(i))
                res.push_back(s[i]);
        }
        return res;
    }
};