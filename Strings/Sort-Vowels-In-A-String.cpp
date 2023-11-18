// Leetcode 2785

class Solution {
public:
    bool isVowel(char &ch){
        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U') return true;
        return false;
    }
    string sortVowels(string s) {
        int n = s.length();
        multiset<char> st;
        for(auto& ch: s) if(isVowel(ch)) st.insert(ch);
        for(int i=0; i<n; i++){
            if(isVowel(s[i])){
                char temp = *st.begin();
                s[i] = temp;
                st.erase(st.find(temp));
            }
        }
        return s;
    }
};