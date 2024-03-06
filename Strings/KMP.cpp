// https://www.geeksforgeeks.org/problems/search-pattern0205/1

class Solution {
public:
  void calculateLPS(string &pat, vector<int> &lps) {
    int m = pat.size();
    lps[0] = 0;
    int i = 1, length = 0;
    while (i < m) {
      if (pat[i] == pat[length]) {
        lps[i++] = ++length;
      } else {
        if (length > 0) {
          length = lps[length - 1];
        } else {
          i++;
        }
      }
    }
  }
  vector<int> findAllOccurencesKMP(string &text, string &pattern,
                                   vector<int> &lps) {
    int n = text.size(), m = pattern.size();
    vector<int> result;
    int i = 0, j = 0;
    while (i < n) {
      if (text[i] == pattern[j]) {
        // matched
        i++;
        j++;
        if (j == m) {
          // fully matched
          result.push_back(i - j + 1);
          j = lps[j - 1];
        }
      } else {
        // point j to lps[j-1]
        if (j > 0) {
          j = lps[j - 1];
        } else {
          i++;
        }
      }
    }
    return result;
  }
  vector<int> search(string pat, string txt) {
    int n = txt.size(), m = pat.size();
    // 1. find the lps of pattern
    vector<int> lps(m, 0);
    calculateLPS(pat, lps);
    return findAllOccurencesKMP(txt, pat, lps);
  }
};