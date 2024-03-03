// Leetcode 275

class Solution {
public:
  int hIndex(vector<int> &citations) {
    int n = citations.size();
    int low = 0, high = n - 1;
    int ans = 0;
    while (low <= high) {
      int mid = low + ((high - low) >> 1);
      int no_of_papers = (n - mid);
      int citation = citations[mid];
      if (citation >= no_of_papers) {
        high = mid - 1;
        ans = no_of_papers;
      } else {
        low = mid + 1;
      }
    }
    return ans;
  }
};