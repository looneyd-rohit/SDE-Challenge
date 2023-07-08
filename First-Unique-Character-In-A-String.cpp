// https://www.codingninjas.com/studio/problems/first-unique-character-in-a-string_893404?leftPanelTab=0


#include <bits/stdc++.h> 
vector<char> firstNonRepeating(string stream) 
{
    int n = stream.size();
    vector<int> hash(26, 0);
    queue<char> q;
    vector<char> ans;
    for(int i=0; i<n; i++){
        char ch = stream[i];
        q.push(ch);
        hash[ch-'a']++;
        while(!q.empty() && hash[q.front()-'a'] > 1){
            q.pop();
        }
        if(!q.empty()) ans.push_back(q.front());
    }
    return ans;
}