class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size(), n2 = nums2.size();
        if (n1 > n2)
            return findMedianSortedArrays(nums2, nums1);
        int n = n1 + n2;
        // this is because, we are partitioning arrays and hence each partition on
        // any array may contain 0 or even all the elements
        int low = 0, high = n1;
        int half = (n1 + n2 + 1) >> 1;
        while (low <= high)
        {
            int mid1 = low + ((high - low) >> 1);
            int mid2 = half - mid1;

            int left1 = mid1 != 0 ? nums1[mid1 - 1] : INT_MIN;
            int left2 = mid2 != 0 ? nums2[mid2 - 1] : INT_MIN;

            int right1 = mid1 <= n1 - 1 ? nums1[mid1] : INT_MAX;
            int right2 = mid2 <= n2 - 1 ? nums2[mid2] : INT_MAX;

            if (left1 <= right2 && left2 <= right1)
            {
                if (n & 1)
                {
                    return max(left1, left2);
                }
                else
                {
                    return ((double)max(left1, left2) + (double)min(right1, right2)) / 2;
                }
            }
            else if (left1 > right2)
            {
                high = mid1 - 1;
            }
            else
            {
                low = mid1 + 1;
            }
        }
        return 0;
    }
};