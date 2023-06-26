// Leetcode 395
// DNC
class Solution
{
public:
    int longestSubstring(string s, int k)
    {
        int n = s.length();
        if (n == 0 || k > n)
            return 0;
        if (k <= 1)
            return n;

        // divide the string into two parts and recursively call the two parts
        vector<int> freq(26, 0);
        for (auto &ch : s)
            freq[ch - 'a']++;

        int ind = 0;
        while (ind < n)
        {
            if (freq[s[ind] - 'a'] < k)
                break;
            ind++;
        }

        // ind --> first index where there exists a character whose total count < k
        if (ind >= n - 1)
        {
            return ind;
        }
        else
        {
            // call for both left and right parts and take max
            int left = longestSubstring(s.substr(0, ind), k);
            int right = longestSubstring(s.substr(ind + 1), k);
            return max(left, right);
        }
    }
};