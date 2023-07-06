// Leetcode 85

class Solution {
public:
    void getPSME(vector<int>& arr, vector<int>& psme){
        int n = arr.size();
        stack<int> st;
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            if(!st.empty()) psme[i] = st.top();
            st.push(i);
        }
    }
    void getNSME(vector<int>& arr, vector<int>& nsme){
        int n = arr.size();
        stack<int> st;
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            if(!st.empty()) nsme[i] = st.top();
            st.push(i);
        }
    }
    int getMaxArea(vector<int>& arr, vector<int>& psme, vector<int>& nsme){
        int maxArea = 0;
        int n = arr.size();
        for(int i=0; i<n; i++){
            int height = arr[i];
            int prev = psme[i] + 1;
            int next = nsme[i] - 1;
            maxArea = max(maxArea, height * (next-prev+1));
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        // similar to maximal rectange --> for each row
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> new_matrix(m, vector<int>(n, 0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                new_matrix[i][j] = matrix[i][j]-'0';
            }
        }
        int ans = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i > 0){
                    new_matrix[i][j] = new_matrix[i][j] == 0 ? 0 : new_matrix[i][j]+new_matrix[i-1][j];
                }
            }
            // compute psme
            vector<int> psme(n, -1);
            getPSME(new_matrix[i], psme);

            // compute nsme
            vector<int> nsme(n, n);
            getNSME(new_matrix[i], nsme);

            ans = max(ans, getMaxArea(new_matrix[i], psme, nsme));
        }
        return ans;
    }
};