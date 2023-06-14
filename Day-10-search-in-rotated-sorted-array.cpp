class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int low = 0, high = n - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            // check if it exists
            if (nums[mid] == target)
                return mid;

            // otherwise check for sorted half --> since no duplicates, no edge cases
            // left half sorted
            if (nums[low] <= nums[mid])
            {
                if (nums[low] <= target && target <= nums[mid])
                {
                    // present in sorted half
                    high = mid - 1;
                }
                else
                {
                    // not present int sorted half
                    low = mid + 1;
                }
            }
            // right half sorted
            if (nums[mid] <= nums[high])
            {
                if (nums[mid] <= target && target <= nums[high])
                {
                    // present in sorted half
                    low = mid + 1;
                }
                else
                {
                    // not present int sorted half
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};