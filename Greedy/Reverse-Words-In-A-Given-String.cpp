// https://practice.geeksforgeeks.org/problems/reverse-words-in-a-given-string5459/1

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    {
        int n = S.length();
        reverse(begin(S), end(S));
        int i = 0, j=0;
        for(; j<n; j++){
            if(S[j]=='.'){
                reverse(begin(S)+i, begin(S)+j);
                i = j + 1;
            }
        }
        reverse(begin(S)+i, begin(S)+j);
        return S;
    } 
};