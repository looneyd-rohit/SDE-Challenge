class Solution
{
public:
    bool solve(int &left, int &right, string &s)
    {
        bool flag = false;
        while (left >= 0 && right < s.length() && s[left] == s[right])
        {
            left--;
            right++;
            flag = true;
        }
        return flag;
    }
    string longestPalindrome(string s)
    {
        int n = s.length();
        if (n == 1)
            return s;
        string ans = "";
        int index = 0, len = 0;
        for (int i = 0; i < n - 1; i++)
        {
            // considering odd length string
            int left = i, right = i;
            if (solve(left, right, s))
            {
                left++;
                right--;
            }

            int len1 = right - left + 1;

            // cosidering even length string
            int left2 = i, right2 = i + 1;
            if (solve(left2, right2, s))
            {
                left2++;
                right2--;
            }

            int len2 = s[i] == s[i + 1] ? right2 - left2 + 1 : 0;

            // cout<<len1<<" "<<len2<<endl;

            if (len < len1)
            {
                index = left;
                len = len1;
            }

            if (len < len2)
            {
                index = left2;
                len = len2;
            }
        }
        return s.substr(index, len);
    }
};