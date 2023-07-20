// Leetcode 1353
// [IMP]: SJF Pattern Question, very nice question
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        // introduce a timeline variable --> which will go from day 0 to day n
        // this is done, because according to question an event spans through a number of days
        // and we can attend this event anyday in between, so we will basically attend one event
        // in one day, hence the timeline variable will tell us which event to attend on the particular
        // day, also for maximum events we will sort the events based on their starting times
        // and we will use the timeline variable to push those events into the set/pq which have
        // arrived till that time, and attend the one having lower end time first and so on...
        int n = events.size();
        sort(begin(events), end(events));
        int timeline = 0, index = 0;
        int count = 0;
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> minheap;
        while(index < n || !minheap.empty()){
            // edge case when large gap b/w events or start event
            if(minheap.empty() && timeline < events[index][0]){
                timeline = events[index][0];
            }
            
            // pick the events that have arrived till this timeline
            while(index < n && events[index][0] <= timeline){
                minheap.push({events[index][1], index});
                index++;
            }
            
            // now we have events in minheap which can be attended
            // pick the one with lowest endtime
            auto top = minheap.top(); minheap.pop();

            if(timeline <= top.first){
                count++;
                timeline++;
            }
        }
        return count;
    }
};