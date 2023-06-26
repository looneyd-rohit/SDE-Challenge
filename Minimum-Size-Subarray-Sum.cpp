// Leetcode 209
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int n = nums.size();
        int i = 0, j = 0;
        int mini = INT_MAX;
        int sum = 0;
        while (j < n)
        {
            sum = sum + nums[j];

            if (sum < target)
            {
                // since array contains only +ve nos. and sum < target, we can increase the
                // sum by only adding elements to it
                j++;
            }
            else if (sum >= target)
            {
                // sum >= target --> go on reducing size until it becomes < target and note
                // the minima
                while (sum >= target)
                {
                    mini = min(mini, j - i + 1);
                    sum = sum - nums[i];
                    i++;
                }
                j++;
            }
        }
        return mini == INT_MAX ? 0 : mini;
    }
};