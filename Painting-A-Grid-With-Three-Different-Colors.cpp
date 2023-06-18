class Solution
{
public:
    void generate(int index, int lastCol, int m, string &temp, vector<string> &ans)
    {
        // base case
        if (index >= m)
        {
            ans.push_back(temp);
            return;
        }
        for (int col = 0; col < 3; col++)
        {
            if (col != lastCol)
            {
                temp.push_back((char)(col + '0'));
                generate(index + 1, col, m, temp, ans);
                temp.pop_back();
            }
        }
    }
    bool isConflict(string &a, string &b)
    {
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] == b[i])
                return true;
        }
        return false;
    }
    int colorTheGrid(int m, int n)
    {
        // first generate all possible color combinations for one row
        // second, compare with previous row and compute for next
        string temp = "";
        vector<string> ans;
        generate(0, -1, m, temp, ans);
        unordered_map<string, unordered_map<int, int>> umap;
        int mod = 1e9 + 7;
        // iterate for n rows
        for (int i = 0; i < n; i++)
        {
            // iterate for all distinct pair of combinations
            for (int j = 0; j < ans.size(); j++)
            {
                if (i == 0)
                {
                    // first row, no need to compare
                    umap[ans[j]][i] = 1;
                }
                else
                {
                    int cnt = 0;
                    for (int k = 0; k < ans.size(); k++)
                    {
                        if (isConflict(ans[j], ans[k]) == false)
                        {
                            cnt += umap[ans[k]][i - 1];
                            cnt %= mod;
                        }
                    }
                    umap[ans[j]][i] = cnt;
                }
            }
        }
        // count the total for the n-th row, taking all possible combinations from ans
        int total = 0;
        for (auto &e : ans)
        {
            total += umap[e][n - 1];
            total %= mod;
        }
        return total;
    }
};