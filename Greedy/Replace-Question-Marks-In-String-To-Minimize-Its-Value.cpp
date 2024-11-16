// Leetcode 3081

class Solution {
public:
    string minimizeStringValue(string s) {
        int n = s.length();
        vector<int> freq(26, 0);
        for(int i=0; i<n; i++){
            if(s[i]=='?') continue;
            freq[s[i]-'a']++;
        }
        string missing = "";
        for(int i=0; i<n; i++){
            if(s[i]!='?') continue;
            // find the minimum character that can be placed at the '?'
            int ind=0, min_freq=1e9;
            for(int j=0; j<26; j++){
                if(min_freq > freq[j]){
                    min_freq = freq[j];
                    ind = j;
                }
            }
            // now we have the most appropriate character to be placed at '?'
            missing.push_back((char)(ind + 'a'));
            freq[ind]++;
        }
        sort(begin(missing), end(missing));
        for(int i=0, k=0; i<n; i++){
            if(s[i]!='?') continue;
            s[i] = missing[k++];
        }
        return s;
    }
};