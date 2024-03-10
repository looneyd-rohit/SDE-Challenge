// Leetcode 1481

// Approach 1: sorting frequencies and decrementing
class Solution {
public:
  int findLeastNumOfUniqueInts(vector<int> &arr, int k) {
    int n = arr.size();
    unordered_map<int, int> ump;
    for (auto &e : arr)
      ump[e]++;
    vector<int> freq;
    for (auto &e : ump)
      freq.push_back(e.second);
    sort(begin(freq), end(freq));
    for (int i = 0; i < freq.size(); i++) {
      if (k < freq[i])
        return freq.size() - i;
      k -= freq[i];
    }
    return 0;
  }
};

// Approach 2: without sorting O(N) time complexity
class Solution {
public:
  int findLeastNumOfUniqueInts(vector<int> &arr, int k) {
    int n = arr.size();
    unordered_map<int, int> ump;
    for (auto &e : arr)
      ump[e]++;
    unordered_map<int, int> freq_to_count;
    for (auto &e : ump)
      freq_to_count[e.second]++;
    for (int f = 1; f <= n; f++) {
      int count = freq_to_count[f];
      int can_be_removed = min(count, (k / f));
      int total = f * can_be_removed;
      k -= total;
      freq_to_count[f] -= can_be_removed;
      if (freq_to_count[f] == 0)
        freq_to_count.erase(f);
    }
    int result = 0;
    for (auto &e : freq_to_count)
      result += e.second;
    return result;
  }
};