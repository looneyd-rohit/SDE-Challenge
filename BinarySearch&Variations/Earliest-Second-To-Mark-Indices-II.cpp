// Leetcode 3049

class Solution {
public:
  bool isPossible(vector<int> &nums, vector<int> &changeIndices, int mid) {
    int n = nums.size(), m = changeIndices.size();
    // find the first occurence of an index on changeIndices as this is where
    // we apply the op2
    unordered_map<int, int> first_occurence;
    for (int i = 0; i < m; i++) {
      if (first_occurence.find(changeIndices[i] - 1) == first_occurence.end()) {
        first_occurence[changeIndices[i] - 1] = i;
      }
    }
    long long buffer = 0; // used to keep track of op1 and op3
    // traverse from the back of the changeIndex array
    // so as to ensure we have buffer for performing op3
    // and also coming from back op2 for any index gets fixed
    // deterministically rather than coming from front where there
    // can be ambiguity that whether we can apply op2 or not
    multiset<int> ms;
    for (int time = mid - 1; time >= 0; time--) {
      int index = changeIndices[time] - 1;
      // if first occurence then try to perform op2
      if (first_occurence[index] == time) {
        if (nums[index] == 0) {
          // edge case --> when nums[index] == 0 only do op3
          buffer++;
          continue;
        }

        ms.insert(nums[index]);
        // check for buffer
        if (buffer == 0) {
          // not possible to perform op2
          // hence pop the lowest valued item
          // as we need to perform op1 on it
          ms.erase(ms.begin());
          // also we get extra buffer space for that
          buffer++;
        } else {
          // possible to perform op2
          buffer--;
        }
      } else {
        // perform either op1 or op3
        buffer++;
      }
    }
    // now check the possibility to perform op1
    long long reqOps = 0;
    for (auto &e : nums)
      reqOps += e;
    reqOps += n;
    // remove items with op2
    for (auto &e : ms)
      reqOps -= e;
    reqOps -= ms.size();
    return (reqOps <= buffer);
  }
  int earliestSecondToMarkIndices(vector<int> &nums,
                                  vector<int> &changeIndices) {
    int n = nums.size(), m = changeIndices.size();
    int low = 1, high = m;
    while (low <= high) {
      int mid = low + ((high - low) >> 1);
      if (isPossible(nums, changeIndices, mid)) {
        // possible with time mid
        // check for lower time
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    return (low > m) ? -1 : low;
  }
};