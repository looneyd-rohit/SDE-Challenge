// Leetcode 214

// Approach: using lps concept of kmp
class Solution
{
public:
  void computeLPS(string &pattern, vector<int> &lps, int n)
  {
    int len = 0;
    lps[0] = len;
    int i = 1;
    while (i < n)
    {
      if (pattern[i] == pattern[len])
      {
        lps[i++] = ++len;
      }
      else
      {
        // trace back
        if (len > 0)
          len = lps[len - 1];
        else
        {
          lps[i] = 0;
          i++;
        }
      }
    }
  }
  string shortestPalindrome(string s)
  {
    int n = s.length();
    // logic is to find the largest palindrome substring [0....i]
    // and then take the rest part and append it to the front by
    // reversing it
    // to do this, we can take help of lps
    string temp = s + "$" + s;
    reverse(begin(temp) + n + 1, end(temp));
    vector<int> lps(2 * n + 1, 0);
    computeLPS(temp, lps, 2 * n + 1);
    int matched_len = lps.back();
    string rest = s.substr(matched_len);
    reverse(begin(rest), end(rest));
    return (rest + s);
  }
};