// Leetcode 2751

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<vector<int>> robots;
        for(int i=0; i<n; i++){
            int dir = directions[i] == 'R' ? 1 : -1;
            robots.push_back({0, positions[i], healths[i], dir, i});
        }
        sort(begin(robots), end(robots));
        for(int i=0; i<n; i++) robots[i][0] = i;
        stack<int> st;
        st.push(0);
        for(int i=1; i<n; i++){
            bool isInsert = true;
            while(!st.empty() && robots[st.top()][3] == 1 && robots[i][3] == -1){
                // collision occurs
                vector<int> leftRobot = robots[st.top()]; st.pop();
                vector<int> rightRobot = robots[i];
                if(leftRobot[2] < rightRobot[2]){
                    robots[i][2]--;
                }else if(leftRobot[2] > rightRobot[2]){
                    robots[leftRobot[0]][2]--;
                    st.push(leftRobot[0]);
                    isInsert = false;
                    break;
                }else{
                    isInsert = false;
                    break;
                }
            }
            if(isInsert) st.push(i);
        }
        vector<vector<int>> modifiedAns;
        while(!st.empty()){
            modifiedAns.push_back({robots[st.top()][4], robots[st.top()][2]});
            st.pop();
        }
        sort(begin(modifiedAns), end(modifiedAns));
        vector<int> ans;
        for(int i=0; i<modifiedAns.size(); i++){
            ans.push_back(modifiedAns[i][1]);
        }
        return ans;
    }
};