// https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int, int>> meetings;
        for(int i=0; i<n; i++){
            meetings.push_back({end[i], start[i]});
        }
        sort(begin(meetings), meetings.end());
        int cnt = 1, s = meetings[0].second, e = meetings[0].first;
        for(int i=1; i<n; i++){
            if(meetings[i].second > e){
                cnt++;
                s = meetings[i].second, e = meetings[i].first;
            }
        }
        return cnt;
    }
};