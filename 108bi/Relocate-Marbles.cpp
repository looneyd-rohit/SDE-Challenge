// Q2.

class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        set<int> st;
        for(auto& e: nums) st.insert(e);
        int m = moveFrom.size();
        for(int i=0; i<m; i++){
            st.erase(moveFrom[i]); st.insert(moveTo[i]);
        }
        return vector<int>(begin(st), end(st));
    }
};