// Leetcode 732

class MyCalendarThree {
public:
  // use a sorted map as we need ordering {start comes before end}
  map<int, int> mp;
  MyCalendarThree() {}

  int book(int startTime, int endTime) {
    mp[startTime]++;
    mp[endTime]--;
    int maxi = 0, sum = 0;
    for (auto &it : mp) {
      sum += it.second;
      maxi = max(maxi, sum);
    }
    return maxi;
  }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */