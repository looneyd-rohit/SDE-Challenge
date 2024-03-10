// https://www.geeksforgeeks.org/problems/check-frequencies4211/1

class Solution {
public:
  bool sameFreq(string s) {
    int n = s.length();
    vector<int> freq(26, 0);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
      int prev = freq[s[i] - 'a'];
      int curr = freq[s[i] - 'a'] + 1;
      freq[s[i] - 'a']++;
      if (prev > 0) {
        mp[prev]--;
        if (mp[prev] <= 0)
          mp.erase(prev);
      }
      mp[curr]++;
    }
    mp.erase(0);
    if (mp.size() > 2)
      return false;
    if (mp.size() == 1)
      return true;
    int first_freq = mp.begin()->first, first_cnt = mp.begin()->second;
    int second_freq = mp.rbegin()->first, second_cnt = mp.rbegin()->second;
    if (first_freq == second_freq)
      return true;
    if (first_freq == 1 && first_cnt == 1)
      return true;
    if (abs(first_freq - second_freq) == 1) {
      return second_cnt == 1;
    }
    return false;
  }
};