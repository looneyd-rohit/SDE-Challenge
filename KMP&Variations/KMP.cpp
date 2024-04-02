// https://www.geeksforgeeks.org/problems/search-pattern0205/1

class Solution
{
public:
  vector<int> search(string pat, string txt)
  {
    // for kmp we need to first calculate longest proper prefix which is
    // also a suffix (lpps of the pattern string)
    int n = txt.size(), m = pat.size();
    vector<int> lps(m, 0);
    int len = 0;
    lps[0] = len;
    for (int i = 1; i < m; i++)
    {
      if (pat[i] == pat[len])
      {
        len++;
        lps[i] = len;
      }
      else
      {
        // trace back and try again
        if (len > 0)
        {
          len = lps[len - 1];
          i--;
        }
      }
    }
    // now search for the pattern in the text using the lpps
    vector<int> ans;
    int i = 0, j = 0;
    while (i < n)
    {
      if (j<m && txt[i] == pat[j])
      {
        // continue
        i++;
        j++;
        if (j == m)
        {
          ans.push_back((i - m) + 1); // 1 based indexing
        }
      }
      else
      {
        // trace back, j and try again
        if (j > 0)
        {
          j = lps[j - 1];
        }
        else
        {
          // can't be traced back, and no matchings found
          i++;
        }
      }
    }
    return ans;
  }
};