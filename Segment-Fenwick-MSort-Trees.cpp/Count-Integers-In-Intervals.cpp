// Leetcode 2276

// [IMP] Approach 1: using ordered map + concept of intervals overlal (r2>=l1 &&
// r1>=l2)
class CountIntervals {
public:
  map<int, int> mp;
  int cnt;
  CountIntervals() { this->cnt = 0; }

  void add(int left, int right) {
    // using the concept that given two intervals
    // [l1, r1] && [l2, r2] they will only have overlap
    // if l1<=r2 && r1>=l2 hold simulataneously
    if (mp.empty()) {
      mp[left] = right;
      this->cnt += right - left + 1;
    } else {
      while (true) {
        auto it = mp.upper_bound(right);
        if (it == mp.begin()) {
          mp[left] = right;
          this->cnt += right - left + 1;
          break;
        } else {
          it--;
          if (it->first <= right && it->second >= left) {
            int new_left = min(it->first, left),
                new_right = max(it->second, right);
            this->cnt -= (it->second - it->first + 1);
            mp.erase(it->first);
            left = new_left, right = new_right;
          } else {
            mp[left] = right;
            this->cnt += right - left + 1;
            break;
          }
        }
      }
    }
  }

  int count() { return this->cnt; }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */