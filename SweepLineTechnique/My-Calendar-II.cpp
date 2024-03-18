// Leetcode 731

// Approach 1: using sweep line technique
class MyCalendarTwo {
public:
  map<int, int> mp;
  MyCalendarTwo() {}

  bool book(int start, int end) {
    mp[start]++;
    mp[end]--;
    int maxi = 0, sum = 0;
    for (auto &e : mp) {
      sum += e.second;
      maxi = max(maxi, sum);
      if (maxi >= 3) {
        // remove from map as event could not take place
        mp[start]--;
        mp[end]++;
        return false;
      }
    }
    return true;
  }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */

// Approach 2: storing the double bookings
class MyCalendarTwo {
public:
  vector<pair<int, int>> bookings, double_bookings;
  MyCalendarTwo() {}

  bool book(int start, int end) {
    // check for double bookings
    for (auto &p : double_bookings) {
      if (p.first < end && p.second > start) { // tricky but useful and works
        return false;
      }
    }
    // otherwise booking will happen
    // and also update double_bookings
    for (auto &p : bookings) {
      if (p.first < end && p.second > start) { // tricky but useful and works
        // update
        double_bookings.push_back({max(p.first, start), min(p.second, end)});
      }
    }
    bookings.push_back({start, end});
    return true;
  }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */