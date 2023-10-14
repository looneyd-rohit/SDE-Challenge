// Leetcode 1996
// [IMP]: slightly differenct -> sorting + stack
class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        if(a[0]!=b[0]) return a[0] < b[0];
        return a[1] > b[1];
    }
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int n = properties.size();
        sort(properties.begin(), properties.end(), cmp);
        stack<int> st;
        int cnt = 0;
        for(int i=0; i<n; i++){
            while(!st.empty() && st.top() < properties[i][1]){
                cnt++;
                st.pop();
            }
            st.push(properties[i][1]);
        }
        return cnt;
    }
};