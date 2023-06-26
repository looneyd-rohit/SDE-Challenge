// Leetcode 76
class Solution
{
public:
    string minWindow(string s, string t)
    {
        int n = s.length(), m = t.length();
        unordered_map<char, int> umap;
        for (auto &e : t)
            umap[e]++;
        int count_mp_size = umap.size();
        int i = 0, j = 0;
        int min_len = INT_MAX;
        int min_i = n, min_j = n;
        while (j < n)
        {
            // remove j-th character of s from umap --> taking into account
            umap[s[j]]--;
            if (umap[s[j]] == 0)
            {
                // character used out completely
                count_mp_size--;
            }

            if (count_mp_size > 0)
            {
                // not yet reached
                j++;
            }
            else if (count_mp_size == 0)
            {
                // reached
                while (count_mp_size == 0 && i <= j)
                {
                    if (min_len > (j - i + 1))
                    {
                        min_len = j - i + 1;
                        min_i = i;
                        min_j = j;
                    }
                    umap[s[i]]++;
                    if (umap[s[i]] == 1)
                    {
                        // we check for 1, since count is initially >= 1 for any character in umap
                        // for t, now if we encounter more characters in s while traversing, we
                        // decrease count and it may get negated, now 1 signifies the point where
                        // the current window stores one less character than that required hence
                        // we increase mp_size
                        // character used out completely
                        count_mp_size++;
                    }
                    i++;
                }
                j++;
            }
        }
        // cout<<min_len<<endl;
        if (min_len == INT_MAX)
            return "";
        return s.substr(min_i, min_j - min_i + 1);
    }
};