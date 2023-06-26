// https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    int longestKSubstr(string s, int k)
    {
        int n = s.length();
        vector<int> freq(26, 0);
        int i = 0, j = 0;
        int count = 0;
        int maxi = -1;
        while (j < n)
        {
            freq[s[j] - 'a']++;
            if (freq[s[j] - 'a'] == 1)
                count++;

            if (count < k)
            {
                j++;
            }
            else if (count == k)
            {
                maxi = max(maxi, j - i + 1);
                j++;
            }
            else if (count > k)
            {
                // since we need substrings of exactly k unique characters, so once we
                // reach to k, we must reduce it
                while (count > k && i <= j)
                {
                    freq[s[i] - 'a']--;
                    if (freq[s[i] - 'a'] == 0)
                        count--;
                    i++;
                }
                if (count == k)
                    maxi = max(maxi, j - i + 1);
                j++;
            }
        }
        return maxi;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends
