// Leetcode 84

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // assume every bar height can be taken as height of the rectangle and try to
        // maximize the width --> prev/next smaller element
        int n = heights.size();
        vector<int> psme(n, -1);
        vector<int> nsme(n, n);
        stack<int> st;
        for(int i=0; i<n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if(!st.empty()) psme[i] = st.top();
            st.push(i);
        }
        st = stack<int>();
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if(!st.empty()) nsme[i] = st.top();
            st.push(i);
        }
        int maxArea = 0;
        for(int i=0; i<n; i++){
            int height = heights[i];
            int prev = psme[i] + 1;
            int next = nsme[i] - 1;
            maxArea = max(maxArea, height * (next-prev+1));
        }
        return maxArea;
    }
};