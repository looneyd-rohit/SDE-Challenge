// https://practice.geeksforgeeks.org/problems/maximum-meetings-in-one-room/1

class Solution{
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        if(a[1]!=b[1]) return a[1] < b[1];
        return a[2] < b[2];
    }
    vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
        vector<vector<int>> meetings;
        for(int i=0; i<N; i++){
            meetings.push_back({S[i], F[i], i});
        }
        sort(begin(meetings), end(meetings), cmp);
        vector<int> ans;
        ans.push_back(meetings[0][2]+1);
        for(int i=1; i<N; i++){
            if(S[meetings[i][2]] > F[ans.back()-1]){
                ans.push_back(meetings[i][2]+1);
            }
        }
        sort(begin(ans), end(ans));
        return ans;
    }
};