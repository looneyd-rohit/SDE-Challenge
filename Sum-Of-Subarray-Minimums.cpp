// Leetcode 907

class Solution {
public:
    const int M = 1e9+7;
    void getPSME(vector<int>& arr, vector<int>& psme){
        int n = arr.size();
        stack<int> st;
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
            if(!st.empty()) psme[i] = st.top();
            st.push(i);
        }
    }
    void getNSME(vector<int>& arr, vector<int>& nsme){
        int n = arr.size();
        stack<int> st;
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()]>arr[i]) st.pop();
            if(!st.empty()) nsme[i] = st.top();
            st.push(i);
        }
    }
    int sumSubarrayMins(vector<int>& arr) {
        // similar to prev smaller and next smaller pattern type
        int n = arr.size();
        vector<int> psme(n, -1);
        vector<int> nsme(n, n);
        // compute stuff
        getPSME(arr, psme);
        getNSME(arr, nsme);

        // keep >= in one psme/nsme to prevent double counting
        long long ans = 0;
        for(int i=0; i<n; i++){
            int prev = psme[i]+1, next= nsme[i]-1;
            int diff = (next - i + 1) * (i - prev + 1);
            ans += arr[i] * 1LL * (diff);
            ans = ans % M;
        }
        return (ans + M) % M;
    }
};