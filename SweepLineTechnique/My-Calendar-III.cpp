// Leetcode 732

// [IMP] Approach 1: using sweep line technique
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

// [IMP] Approach 2: using dynamic (sparse) segment trees
class DynamicSGTree {
public:
  int val;
  int lazy;
  DynamicSGTree *left, *right;
  DynamicSGTree(int val = 0, int lazy = 0) {
    this->val = val;
    this->lazy = lazy;
    this->left = NULL;
    this->right = NULL;
  }
};
class MyCalendarThree {
public:
  DynamicSGTree *sgtree;
  // helper -> performs range updates in a lazy manner
  void helper(DynamicSGTree *root, int low, int high, int l, int r, int v) {
    // since it is a dynamic segment tree we need to create childs dynamically
    if (low != high) {
      // child should exist
      if (!root->left)
        root->left = new DynamicSGTree();
      if (!root->right)
        root->right = new DynamicSGTree();
    }

    // since it is lazy updates, check pending updates
    if (root->lazy != 0) {
      // updates are remaining
      root->val += root->lazy;
      // propagate the updates to childs
      if (low != high) {
        root->left->lazy += root->lazy;
        root->right->lazy += root->lazy;
      }
      // remove the pending update
      root->lazy = 0;
    }

    // since it is lazy segment tree (dynamic also)
    // we need to check range ovelaps

    // 1. no overlap
    if (r < low || high < l)
      return;

    // 2. full ovelap
    if (l <= low && high <= r) {
      // perform lazy update on the node
      root->val += v;
      // propagate the updates to childs
      if (low != high) {
        root->left->lazy += v;
        root->right->lazy += v;
      }
      return;
    }

    // 3. partial overlap
    int mid = low + ((high - low) >> 1);
    helper(root->left, low, mid, l, r, v);
    helper(root->right, mid + 1, high, l, r, v);

    // finally update current node after childs are updated
    root->val = max(root->left->val, root->right->val);
  }
  MyCalendarThree() { this->sgtree = new DynamicSGTree(0, 0); }

  int book(int startTime, int endTime) {
    helper(this->sgtree, 0, 1e9, startTime, endTime - 1, 1);
    return this->sgtree->val;
  }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */