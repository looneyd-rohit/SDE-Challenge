// Leetcode 3076

// [IMP] Approach: brute force but well thought
class Solution {
public:
  vector<string> shortestSubstrings(vector<string> &arr) {
    int n = arr.size();
    // to find the shortest substring of a word that does not occur in another
    // words we have to find all unique substrings of all words and store their
    // counts and then take the one which has count 1 and is shortest
    map<string, int> count_mp;
    for (int i = 0; i < n; i++) {
      string word = arr[i];
      unordered_set<string> ust;
      for (int j = 0; j < word.length(); j++) {
        for (int len = 1; len <= word.length(); len++) {
          string str = word.substr(j, len);
          // take the string only if unique
          if (ust.find(str) == ust.end())
            count_mp[str]++;
          ust.insert(str);
        }
      }
    }
    vector<string> result;
    for (int i = 0; i < n; i++) {
      string word = arr[i];
      string uncommon = "";
      for (int j = 0; j < word.length(); j++) {
        string curr_substr = "";
        for (int k = j; k < word.length(); k++) {
          curr_substr.push_back(arr[i][k]);
          if (count_mp[curr_substr] == 1) {
            if (uncommon.size() == 0 || curr_substr.size() < uncommon.size() ||
                (curr_substr.size() == uncommon.size() &&
                 curr_substr < uncommon)) {
              uncommon = curr_substr;
            }
          }
        }
      }
      result.push_back(uncommon);
    }
    return result;
  }
};