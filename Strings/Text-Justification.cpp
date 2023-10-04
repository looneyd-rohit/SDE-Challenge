// Leetcode 68

class Solution {
public:
    string constructLine(int i, int j, int eachEmptySpace, int extraEmptySpace, vector<string>& words, int maxWidth){
        int n = words.size();
        string line = "";
        for(int k=i; k<j; k++){
            line += words[k];
            if(k==j-1) break;
            for(int sp=1; sp<=eachEmptySpace; sp++) line += " ";
            if(extraEmptySpace){
                line+=" ";
                extraEmptySpace--;
            }
        }
        while(line.length() < maxWidth){
            line+=" ";
        }
        return line;
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        vector<string> ans;
        int i = 0;
        while(i < n){
            int letterCount = words[i].length();
            int spaces = 0;
            int j=i+1;
            while(j < n && words[j].length()+1+letterCount+spaces<=maxWidth){
                letterCount += words[j].length();
                spaces++;
                j++;
            }
            int remainingEmpty = maxWidth - letterCount;
            int eachEmptySpace = spaces == 0 ? 0 : remainingEmpty / spaces;
            int extraEmptySpace = spaces == 0 ? 0 : remainingEmpty % spaces;

            if(j == n){
                // last line --> left justified
                eachEmptySpace = 1; extraEmptySpace = 0;
            }

            ans.push_back(constructLine(i, j, eachEmptySpace, extraEmptySpace, words, maxWidth));

            i = j;
        }
        return ans;
    }
};