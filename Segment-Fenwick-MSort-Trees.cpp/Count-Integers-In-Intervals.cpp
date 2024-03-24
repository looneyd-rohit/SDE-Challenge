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

// [IMP] Approach 2: using dynamic (sparse) segment trees
struct DynamicSGTree {
public:
  int val;
  DynamicSGTree *left, *right;
  DynamicSGTree(int val = 0) : val(val), left(NULL), right(NULL) {}
};
class CountIntervals {
public:
  DynamicSGTree *sgtree;
  void helper(DynamicSGTree *root, int low, int high, int l, int r, int v) {
    // if current range has all marked then skip further markings
    if (root->val == (high - low + 1) * v)
      return;

    // no overlap
    if (r < low || high < l)
      return;

    // full overlap
    if (l <= low && high <= r) {
      root->val = (high - low + 1) * v;
      return;
    }

    // partial overlap
    int mid = low + ((high - low) >> 1);
    if (!root->left)
      root->left = new DynamicSGTree();
    helper(root->left, low, mid, l, r, v);
    if (!root->right)
      root->right = new DynamicSGTree();
    helper(root->right, mid + 1, high, l, r, v);

    // update
    root->val = root->left->val + root->right->val;
  }
  CountIntervals() { this->sgtree = new DynamicSGTree(); }

  void add(int left, int right) {
    helper(this->sgtree, 0, 1e9, left, right, 1);
  }

  int count() { return this->sgtree->val; }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */