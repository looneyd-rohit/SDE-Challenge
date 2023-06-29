// Leetcode 1248 (Nice Problem)
class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        int n = nums.size();
        int i = 0, j = 0;
        int countOfOddInCurrentWindow = 0;
        int totalInCurrentWindow = 0;
        int totalAllOver = 0;
        while (j < n)
        {
            int el = nums[j];
            if (el & 1)
            {
                countOfOddInCurrentWindow++;
                // we make current window count to 0, since new formation will take place
                totalInCurrentWindow = 0;
            }

            if (countOfOddInCurrentWindow < k)
            {
                j++;
            }
            else if (countOfOddInCurrentWindow == k)
            {
                while (countOfOddInCurrentWindow == k)
                {
                    totalInCurrentWindow++;
                    if (nums[i] & 1)
                    {
                        countOfOddInCurrentWindow--;
                    }
                    i++;
                }
                j++;
            }
            // totalInCurrentWindow if not 0, gets added all over, since in previous window all
            // conditions were satisfied now if we add some even to it, condition does not
            // change so previous count gets added again --> think once
            totalAllOver += totalInCurrentWindow;
        }
        return totalAllOver;
    }
};

// [Note: Can be solved with approach similar to Leetcode 992]
class Solution
{
public:
    int solve(vector<int> &nums, int k)
    {
        int n = nums.size();
        int i = 0, j = 0;
        int countOfOddInCurrentWindow = 0;
        int totalAllOver = 0;
        while (j < n)
        {
            int el = nums[j];
            if (el & 1)
            {
                countOfOddInCurrentWindow++;
            }

            if (countOfOddInCurrentWindow <= k)
            {
                // count of 1 to k
                totalAllOver += j - i + 1;
                j++;
            }
            else if (countOfOddInCurrentWindow > k)
            {
                while (countOfOddInCurrentWindow > k)
                {
                    if (nums[i] & 1)
                    {
                        countOfOddInCurrentWindow--;
                    }
                    i++;
                }
                totalAllOver += j - i + 1;
                j++;
            }
        }
        return totalAllOver;
    }
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        return solve(nums, k) - solve(nums, k - 1);
    }
};