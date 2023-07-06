// https://www.codingninjas.com/studio/problems/redundant-brackets_975473?leftPanelTab=0&campaign=Lovebabbarcodestudio&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbarcodestudio

#include <bits/stdc++.h> 
bool findRedundantBrackets(string &s)
{
    // just check if operators are surrounded by brackets or not
    int n = s.length();
    stack<int> st;
    for(int i=0; i<n; i++){
        int ch = s[i];
        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            st.push(ch);
        }else if(ch == ')'){
            if(!st.empty() && st.top() == '(') return true;
            while(!st.empty() && (st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/')){
                st.pop();
            }
            if(!st.empty() && st.top()=='(') st.pop();
        }
    }
    return false;
}
