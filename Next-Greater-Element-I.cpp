// Leetcode 496

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        unordered_map<int, int> hash;
        for(int i=0; i<n2; i++){
            hash[nums2[i]] = i;
        }
        vector<int> nge(n2, -1);
        stack<int> st;
        for(int i=n2-1; i>=0; i--){
            int e = nums2[i];
            while(!st.empty() && st.top() <= e) st.pop();
            if(!st.empty()) nge[i] = st.top();
            st.push(e);
        }
        vector<int> ans(n1, -1);
        for(int i=0; i<n1; i++){
            int correspondingIndex = hash[nums1[i]];
            int correspondingNGE = nge[correspondingIndex];
            ans[i] = correspondingNGE;
        }
        return ans;
    }
};