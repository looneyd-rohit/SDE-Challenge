int counter(vector<vector<int>> &matrix, int median)
{
    int cnt = 0;
    for (int i = 0; i < matrix.size(); i++)
    {
        int l = 0, h = matrix[0].size() - 1;
        while (l <= h)
        {
            int m = l + ((h - l) >> 1);
            int el = matrix[i][m];
            if (el <= median)
            {
                l = m + 1;
            }
            else
            {
                h = m - 1;
            }
        }
        cnt += l;
    }
    return cnt;
}
int getMedian(vector<vector<int>> &matrix)
{
    // binary search based approach:
    int n = matrix.size(), m = matrix[0].size();
    int low = 0, high = 1e9;
    int half = (n * m) / 2;
    while (low <= high)
    {
        int mid = low + ((high - low) >> 1);
        int median = mid;
        // cnt of nos. <= median
        int cnt = counter(matrix, median);
        if (cnt > half)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}