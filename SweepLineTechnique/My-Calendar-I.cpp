// Leetcode 729

// Approach 1: using sweep line technique
class MyCalendar {
public:
  map<int, int> mp;
  MyCalendar() {}

  bool book(int start, int end) {
    mp[start]++;
    mp[end]--;
    int maxi = 0, sum = 0;
    for (auto &e : mp) {
      sum += e.second;
      maxi = max(maxi, sum);
      if (maxi >= 2) {
        mp[start]--;
        mp[end]++;
        return false;
      }
    }
    return true;
  }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

// Approach 2: checking for double bookings
class MyCalendar {
public:
  vector<pair<int, int>> bookings;
  MyCalendar() {}

  bool book(int start, int end) {
    // check for bookings overlap
    for (auto &p : bookings) {
      if (p.first < end &&
          p.second >
              start) { // not greater equals since it is half open interval
        return false;
      }
    }
    bookings.push_back({start, end});
    return true;
  }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */