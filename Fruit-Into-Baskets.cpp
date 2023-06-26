// Leetcode 904
class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int n = fruits.size();
        unordered_map<int, int> umap;
        int count = 0;
        int i = 0, j = 0;
        int totalFruits = 0;
        while (j < n)
        {
            umap[fruits[j]]++;
            if (umap[fruits[j]] == 1)
                count++;

            if (count <= 2)
            {
                totalFruits = max(totalFruits, j - i + 1);
                j++;
            }
            else if (count > 2)
            {
                while (count > 2 && i <= j)
                {
                    umap[fruits[i]]--;
                    if (umap[fruits[i]] == 0)
                        count--;
                    i++;
                }
                j++;
            }
        }
        return totalFruits;
    }
};