// Leetcode 2131
// HashMap + String

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int n = words.size();
        map<string, int> m;
        for(auto& word: words) m[word]++;
        // now, if we have palindrome words we will take all the even count among them
        // and the largest odd count among them will be taken and kept in middle
        // also, for words other than palindrome we will take that word only if its 
        // reverse is present
        int totalLength = 0;
        int middleWordLength = 0;
        for(auto& el: m){
            string word = el.first;
            int cnt = el.second;
            if(cnt > 0){
                string rev = word;
                reverse(rev.begin(), rev.end());
                if(word == rev){
                    // palindrome
                    int qty = cnt / 2;
                    int rem = cnt % 2;
                    totalLength += (2 * qty * word.length());
                    if(rem * word.length() > middleWordLength){
                        middleWordLength = rem * word.length();
                        m[word] = 0;
                    }else{
                        m[word] = rem;
                    }
                }else{
                    // not palindrome
                    int qty = min(cnt, m[rev]);
                    totalLength += (2 * qty * word.length());
                    m[word] -= qty;
                    m[rev] -= qty;
                }
            }
        }
        return (totalLength + ((middleWordLength > 0) ? 2 : 0));
    }
};