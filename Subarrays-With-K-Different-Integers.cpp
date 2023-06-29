// Leetcode 992 (IMP --> Subarrays with COUNT Pattern)
class Solution
{
public:
    int solve(vector<int> &nums, int k)
    {
        int n = nums.size();
        int countOfDistinceInCurrentWindow = 0;
        unordered_map<int, int> umap;
        int i = 0, j = 0;
        int total = 0;
        while (j < n)
        {
            int el = nums[j];
            umap[el]++;
            if (umap[el] == 1)
            {
                // element count is 1
                countOfDistinceInCurrentWindow++;
            }

            if (countOfDistinceInCurrentWindow <= k)
            {
                // count of subarray having count <= k
                total += j - i + 1;
                j++;
            }
            else if (countOfDistinceInCurrentWindow > k)
            {
                while (countOfDistinceInCurrentWindow > k)
                {
                    umap[nums[i]]--;
                    if (umap[nums[i]] == 0)
                    {
                        // element is removed, reduce count
                        countOfDistinceInCurrentWindow--;
                    }
                    i++;
                }
                total += j - i + 1;
                j++;
            }
        }
        return total;
    }
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        return solve(nums, k) - solve(nums, k - 1);
    }
};