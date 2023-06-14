#include <bits/stdc++.h>
int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k)
{
    // similar to partition approach and applying binary search
    if (m > n)
        return ninjaAndLadoos(row2, row1, n, m, k);

    int low = max(k - n, 0), high = min(m, k);
    while (low <= high)
    {
        int mid1 = low + ((high - low) >> 1);
        int mid2 = k - mid1;

        int left1 = mid1 == 0 ? INT_MIN : row1[mid1 - 1];
        int left2 = mid2 == 0 ? INT_MIN : row2[mid2 - 1];

        int right1 = mid1 > m - 1 ? INT_MAX : row1[mid1];
        int right2 = mid2 > n - 1 ? INT_MAX : row2[mid2];

        if (left1 <= right2 && left2 <= right1)
        {
            return max(left1, left2);
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
    return -1;
}