class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        int low = 0, high = n - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            // since all other elements are present twice, we check one position left
            // and one position right of mid element to find out the answer
            if (mid < n - 1 && nums[mid] == nums[mid + 1])
            {
                int cnt = mid + 2;
                if (cnt & 1)
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 2;
                }
            }
            else if (mid > 0 && nums[mid - 1] == nums[mid])
            {
                int cnt = mid + 1;
                if (cnt & 1)
                {
                    high = mid - 2;
                }
                else
                {
                    low = mid + 1;
                }
            }
            else
            {
                return nums[mid];
            }
        }
        return -1;
    }
};