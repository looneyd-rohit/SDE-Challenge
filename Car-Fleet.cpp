// Leetcode 853
// [NOTE]: Nice question of sorting + stack

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // start from right hand side keep those in stack which can form a group/fleet
        int n = position.size();
        vector<pair<int, int>> store;
        for(int i=0; i<n; i++){
            store.push_back({position[i], speed[i]});
        }
        sort(begin(store), end(store));
        // now iterate from the back
        stack<pair<int, int>> st;
        // this is because one fleet will always be there, since n>=1
        st.push(store.back());
        for(int i=n-2; i>=0; i--){
            pair<int, int> behind = store[i];
            pair<int, int> ahead = st.top();

            // time for behind one
            float behindTime = (target - behind.first) * 1.0 / behind.second;

            // time for ahead one
            float aheadTime = (target - ahead.first) * 1.0 / ahead.second;

            if(behindTime > aheadTime){
                // if behind one cannot reach target faster than ahead one they will be two different fleets
                st.push(behind);
            }
        }
        return st.size();
    }
};