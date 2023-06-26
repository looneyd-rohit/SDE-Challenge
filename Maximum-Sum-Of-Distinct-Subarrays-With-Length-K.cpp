// Leetcode 2461
class Solution
{
public:
    long long maximumSubarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        unordered_map<int, int> umap;
        int i = 0, j = 0;
        long long sum = 0;
        long long ans = 0;
        while (j < n)
        {
            sum = sum + nums[j];
            umap[nums[j]]++;
            if (j - i + 1 < k)
            {
                // subarray did not reach size k --> so reduce
                j++;
            }
            else if (j - i + 1 == k)
            {
                // subarray of size k --> check map size
                if (umap.size() == k)
                {
                    // all are distinct
                    ans = max(ans, sum);
                }
                sum = sum - nums[i];
                umap[nums[i]]--;
                if (umap[nums[i]] == 0)
                    umap.erase(nums[i]);
                i++;
                j++;
            }
        }
        return ans;
    }
};