// Leetcode 1441

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int sz = target.size();
        vector<bool> visited(n, false);
        int endInd = -1;
        for(int i=0; i<sz; i++){
            visited[target[i]-1] = true;
            if(visited[target[i]-1]){
                endInd = target[i]-1;
            }
        }
        vector<string> ans;
        for(int i=0; i<=endInd; i++){
            if(!visited[i]){
                ans.push_back("Push");
                ans.push_back("Pop");
            }else{
                ans.push_back("Push");
            }
        }
        return ans;
    }
};