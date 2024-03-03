// Leetcode 2402

// Approach 2: brute force
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int m = meetings.size();
        vector<long long> room_available(n, 0);
        vector<int> hash(n, 0);
        sort(begin(meetings), end(meetings));
        for(int i=0; i<m; i++){
            int start_time = meetings[i][0], end_time = meetings[i][1];
            bool found_room = false;
            long long min_room_ind = 0, min_room_end = LONG_MAX;
            // find the room which is available at the earliest
            for(int i=0; i<n; i++){
                if(start_time >= room_available[i]){
                    room_available[i] = end_time;
                    hash[i]++;
                    found_room = true;
                    break;
                }
                if(min_room_end > room_available[i]){
                    min_room_end = room_available[i];
                    min_room_ind = i;
                }else if(min_room_end == room_available[i]){
                    min_room_ind = min(min_room_ind, 1LL*i);
                }
            }
            if(!found_room){
                room_available[min_room_ind] += (end_time - start_time);
                hash[min_room_ind]++;
            }
        }
        int max_meetings = *max_element(begin(hash), end(hash));
        for(int i=0; i<n; i++){
            if(hash[i]==max_meetings) return i;
        }
        return -1;
    }
};

// Approach 2: optimization using minheap
class Solution {
public:
  int mostBooked(int n, vector<vector<int>> &meetings) {
    int m = meetings.size();
    priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                   greater<pair<long long, int>>>
        room_used;
    set<int> room_not_used;
    for (int i = 0; i < n; i++)
      room_not_used.insert(i);
    vector<int> hash(n, 0);
    sort(begin(meetings), end(meetings));
    for (int i = 0; i < m; i++) {
      int start_time = meetings[i][0], end_time = meetings[i][1];
      // check if any room becomes free by the time meeting starts
      while (!room_used.empty() && room_used.top().first <= start_time) {
        auto t = room_used.top();
        room_used.pop();
        room_not_used.insert(t.second);
      }

      if (!room_not_used.empty()) {
        // empty rooms available use them
        int room_id = *room_not_used.begin();
        room_not_used.erase(room_id);
        room_used.push({end_time, room_id});
        hash[room_id]++;
      } else {
        // meeting has to be delayed
        int diff = end_time - start_time;
        auto t = room_used.top();
        room_used.pop();
        room_used.push({t.first + diff, t.second});
        hash[t.second]++;
      }
    }
    int max_meetings = *max_element(begin(hash), end(hash));
    for (int i = 0; i < n; i++) {
      if (hash[i] == max_meetings)
        return i;
    }
    return -1;
  }
};