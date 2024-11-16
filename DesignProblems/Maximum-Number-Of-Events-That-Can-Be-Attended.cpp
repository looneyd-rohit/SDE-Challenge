// Leetcode 1353

// Approach [IMP]: SJF Pattern Question, very nice question
class Solution {
public:
  int maxEvents(vector<vector<int>> &events) {
    // introduce a timeline variable --> which will go from day 0 to day n
    // this is done, because according to question an event spans through a
    // number of days and we can attend this event anyday in between, so we will
    // basically attend one event in one day, hence the timeline variable will
    // tell us which event to attend on the particular day, also for maximum
    // events we will sort the events based on their starting times and we will
    // use the timeline variable to push those events into the set/pq which have
    // arrived till that time, and attend the one having lower end time first
    // and so on...
    int n = events.size();
    sort(begin(events), end(events));
    int timeline = 0, index = 0;
    int count = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        minheap;
    while (index < n || !minheap.empty()) {
      // edge case when large gap b/w events or start event
      if (minheap.empty() && timeline < events[index][0]) {
        timeline = events[index][0];
      }

      // pick the events that have arrived till this timeline
      while (index < n && events[index][0] <= timeline) {
        minheap.push({events[index][1], index});
        index++;
      }

      // now we have events in minheap which can be attended
      // pick the one with lowest endtime
      auto top = minheap.top();
      minheap.pop();

      if (timeline <= top.first) {
        count++;
        timeline++;
      }
    }
    return count;
  }
};

// update: (practice same solution)
class Solution {
public:
  int maxEvents(vector<vector<int>> &events) {
    int n = events.size();
    // try to attend the event which has lower end time first
    // shortest job first -> type case
    vector<vector<int>> sorted_events;
    for (int i = 0; i < n; i++) {
      sorted_events.push_back({events[i][0], events[i][1], i});
    }
    sort(begin(sorted_events), end(sorted_events));
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        minheap;
    int timer = 0;
    int index = 0;
    int max_count_of_events = 0;
    while (index < n || !minheap.empty()) {
      if (minheap.empty() && timer < sorted_events[index][0]) {
        timer = sorted_events[index][0]; // idle time
      }
      while (index < n && sorted_events[index][0] <= timer) {
        minheap.push({sorted_events[index][1], sorted_events[index][2]});
        index++;
      }
      auto event = minheap.top();
      minheap.pop();
      if (timer > event.first)
        continue; // timer surpassed event end date (edge case)
      timer += 1; // update timer (by 1 as attending event takes 1 day only)
      max_count_of_events++;
    }
    return max_count_of_events;
  }
};