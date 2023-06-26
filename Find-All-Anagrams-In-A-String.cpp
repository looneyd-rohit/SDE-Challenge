// Leetcode 438
class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        int n = s.length();
        int k = p.length();
        unordered_map<char, int> umap;
        for (int i = 0; i < k; i++)
            umap[p[i]]++;
        // count --> stores the no. of distinct characters in the given pattern
        int count = umap.size();
        int i = 0, j = 0;
        vector<int> ans;
        while (j < n)
        {
            umap[s[j]]--;
            if (umap[s[j]] == 0)
            {
                count--;
            }

            if (j - i + 1 < k)
            {
                j++;
            }
            else if (j - i + 1 == k)
            {
                if (count == 0)
                {
                    ans.push_back(i);
                }

                umap[s[i]]++;
                if (umap[s[i]] == 1)
                    count++;
                i++;
                j++;
            }
        }
        return ans;
    }
};