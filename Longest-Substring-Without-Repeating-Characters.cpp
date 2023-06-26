// Leetcode 3
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.length();
        unordered_map<int, int> freq;
        int i = 0, j = 0;
        int maxi = 0;
        while (j < n)
        {
            freq[s[j]]++;

            // only keep that substring freq count in freq array whose element count == 1
            if (freq[s[j]] == 1)
            {
                maxi = max(maxi, j - i + 1);
                j++;
            }
            else if (freq[s[j]] > 1)
            {
                // duplicate detected --> remove from i-th until it eliminates the repeating
                // element
                while (freq[s[j]] > 1 && i <= j)
                {
                    freq[s[i]]--;
                    i++;
                }
                j++;
            }
        }
        return maxi;
    }
};