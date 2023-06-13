class Solution
{
public:
    void solve(int index, string &s, unordered_set<string> &us, string temp, vector<string> &ans)
    {
        // base case
        if (index >= s.size())
        {
            ans.push_back(temp);
            return;
        }

        for (int i = index; i < s.size(); i++)
        {
            string str = s.substr(index, i - index + 1);
            if (us.count(str))
            {
                // word present in dictionary
                // take it into account
                string old = temp;
                if (temp.size() > 0)
                    temp.push_back(' ');
                temp += str;
                solve(i + 1, s, us, temp, ans);
                temp = old;
            }
        }
    }
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> us;
        for (auto &word : wordDict)
            us.insert(word);
        string temp = "";
        vector<string> ans;
        solve(0, s, us, temp, ans);
        return ans;
    }
};