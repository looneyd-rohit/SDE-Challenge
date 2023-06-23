// Segment Tree Based Approach where we smartly activate and deactivate the y coordinates
// based on the query input
class SGTree
{

public:
    vector<int> seg;
    SGTree()
    {
        seg.resize(1e5 + 1);
    }

    SGTree(int n)
    {
        seg.resize(4 * n + 1);
    }

    void build(int index, int low, int high, vector<int> &arr)
    {
        // base case
        if (low == high)
        {
            seg[index] = arr[low];
            return;
        }

        int mid = low + ((high - low) >> 1);
        // call for childs
        build(2 * index + 1, low, mid, arr);
        build(2 * index + 2, mid + 1, high, arr);
        seg[index] = max(seg[2 * index + 1], seg[2 * index + 2]);
    }

    int query(int index, int low, int high, vector<int> &arr, int l, int r)
    {
        // we have to find the answer in given range [l...r]
        // we make transitions using variables [low...high]

        // no overlap
        // l...r low...high or low...high l...r
        if (r < low || high < l)
        {
            return INT_MIN;
        }

        // complete overlap
        // l...low...high...r
        if (low >= l && high <= r)
        {
            return seg[index];
        }

        // partial overlap
        int mid = low + ((high - low) >> 1);
        int left = query(2 * index + 1, low, mid, arr, l, r);
        int right = query(2 * index + 2, mid + 1, high, arr, l, r);
        return max(left, right);
    }

    void pointUpdate(int index, int low, int high, vector<int> &arr, int i, int val)
    {
        // base case
        if (low == high)
        {
            seg[index] = val;
            return;
        }

        int mid = low + ((high - low) >> 1);
        // call for childs
        if (i <= mid)
        {
            pointUpdate(2 * index + 1, low, mid, arr, i, val);
        }
        else
        {
            pointUpdate(2 * index + 2, mid + 1, high, arr, i, val);
        }
        seg[index] = max(seg[2 * index + 1], seg[2 * index + 2]);
    }
};

int lower_bound(vector<pair<int, int>> &arr, int val)
{
    int n = arr.size();
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + ((high - low) >> 1);
        int v = arr[mid].first;
        if (v >= val)
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

class Solution
{
public:
    vector<int> maximumSumQueries(vector<int> &nums1, vector<int> &nums2, vector<vector<int>> &queries)
    {
        int n = nums1.size();
        int m = queries.size();
        // we need three sorted structures
        // explanation given here: https://www.youtube.com/watch?v=XU7Wu70XpBw
        vector<pair<int, int>> numsPair;
        for (int i = 0; i < n; i++)
        {
            numsPair.push_back({nums1[i], nums2[i]});
        }
        sort(begin(numsPair), end(numsPair));

        // sort the queries so that smaller valued ones can be evaulated with those from the larger ones
        vector<tuple<int, int, int>> queryIndexPair;
        for (int i = 0; i < m; i++)
        {
            queryIndexPair.push_back(tuple<int, int, int>(queries[i][1], queries[i][0], i));
        }
        sort(rbegin(queryIndexPair), rend(queryIndexPair));

        // sort the y-coordinates in reverse so that only those can be activated which are >=
        // y coord in accordance to index of numsPair
        vector<pair<int, int>> yCoordIndexPair;
        for (int i = 0; i < n; i++)
        {
            yCoordIndexPair.push_back({numsPair[i].second, i});
        }
        sort(rbegin(yCoordIndexPair), rend(yCoordIndexPair));

        // we need the array to build the suffix sum, so that range sum can be computed
        vector<int> suffixSum(n, INT_MIN);
        SGTree seg(n);
        seg.build(0, 0, n - 1, suffixSum);

        // answer the queries
        vector<int> ans(m, -1);
        // updating till yi of query >= value at yCoordIndexPair
        int ind = 0;
        for (int i = 0; i < m; i++)
        {
            int xi = get<1>(queryIndexPair[i]), yi = get<0>(queryIndexPair[i]);
            int queryIndex = get<2>(queryIndexPair[i]);
            // cout<<queryIndex<<endl;

            // activate all values >= yi in suffix sum
            while (ind < n && yCoordIndexPair[ind].first >= yi)
            {
                int respectiveIndex = yCoordIndexPair[ind].second;
                int sum = numsPair[respectiveIndex].first + numsPair[respectiveIndex].second;

                // activate index --> respectiveIndex
                suffixSum[respectiveIndex] = sum;
                seg.pointUpdate(0, 0, n - 1, suffixSum, respectiveIndex, sum);

                // update ind
                ind++;
            }

            // get the lower bound to calculate range maximum in suffix array
            int lb = lower_bound(numsPair, xi);

            if (lb == n)
            {
                // do nothing
                // ans[queryIndex] = -1;
            }
            else
            {
                // xi is satisfied, satisfy yi
                int maxSumVal = seg.query(0, 0, n - 1, suffixSum, lb, n - 1);
                if (maxSumVal == INT_MIN)
                {
                    // do nothing
                }
                else
                {
                    ans[queryIndex] = maxSumVal;
                }
            }
        }
        return ans;
    }
};

// Coordinate Geometry based approach
class SGTree
{

public:
    vector<int> seg;
    SGTree()
    {
        seg.resize(1e5 + 1);
    }

    SGTree(int n)
    {
        seg.resize(4 * n + 1);
    }

    void build(int index, int low, int high, vector<int> &arr)
    {
        // base case
        if (low == high)
        {
            seg[index] = arr[low];
            return;
        }

        int mid = low + ((high - low) >> 1);
        // call for childs
        build(2 * index + 1, low, mid, arr);
        build(2 * index + 2, mid + 1, high, arr);
        seg[index] = max(seg[2 * index + 1], seg[2 * index + 2]);
    }

    int query(int index, int low, int high, vector<int> &arr, int l, int r)
    {
        // we have to find the answer in given range [l...r]
        // we make transitions using variables [low...high]

        // no overlap
        // l...r low...high or low...high l...r
        if (r < low || high < l)
        {
            return INT_MIN;
        }

        // complete overlap
        // l...low...high...r
        if (low >= l && high <= r)
        {

            return seg[index];
        }

        // partial overlap
        int mid = low + ((high - low) >> 1);
        int left = query(2 * index + 1, low, mid, arr, l, r);
        int right = query(2 * index + 2, mid + 1, high, arr, l, r);
        return max(left, right);
    }

    void pointUpdate(int index, int low, int high, vector<int> &arr, int i, int val)
    {
        // base case
        if (low == high)
        {
            seg[index] = val;
            return;
        }

        int mid = low + ((high - low) >> 1);
        // call for childs
        if (i <= mid)
        {
            pointUpdate(2 * index + 1, low, mid, arr, i, val);
        }
        else
        {
            pointUpdate(2 * index + 2, mid + 1, high, arr, i, val);
        }
        seg[index] = max(seg[2 * index + 1], seg[2 * index + 2]);
    }
};

static bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    if (a.first != b.first)
        return a.first < b.first;
    return a.second > b.second;
}

int lower_bound(vector<pair<int, int>> &arr, int val)
{
    int n = arr.size();
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + ((high - low) >> 1);
        if (arr[mid].first >= val)
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
int upper_bound(vector<pair<int, int>> &arr, int val)
{
    int n = arr.size();
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + ((high - low) >> 1);
        if (arr[mid].second >= val)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return high;
}

class Solution
{
public:
    vector<int> maximumSumQueries(vector<int> &nums1, vector<int> &nums2, vector<vector<int>> &queries)
    {
        int n = nums1.size();
        int m = queries.size();
        // we need three sorted structures
        vector<pair<int, int>> numsPair;
        for (int i = 0; i < n; i++)
        {
            numsPair.push_back({nums1[i], nums2[i]});
        }
        sort(begin(numsPair), end(numsPair), cmp);

        // eliminate non dominating coordinates (monotonic stack)
        vector<pair<int, int>> st;
        for (int i = 0; i < n; i++)
        {
            if (st.empty())
            {
                st.push_back(numsPair[i]);
            }
            else
            {
                auto top = st.back();
                int x1 = top.first, y1 = top.second;
                int x2 = numsPair[i].first, y2 = numsPair[i].second;
                // here since array is sorted according to x
                // so x2 >= x1 always
                if (x2 == x1)
                    continue;

                // now x2 > x1 always
                // only check for y2 and y1
                if (y2 >= y1)
                {
                    // then pop previous elements
                    st.pop_back();
                    i--;
                }
                else
                {
                    // add
                    st.push_back(numsPair[i]);
                }
            }
        }

        int sz = st.size();
        vector<int> sumArray(sz, INT_MAX);
        for (int i = 0; i < sz; i++)
        {
            sumArray[i] = st[i].first + st[i].second;
        }

        // initialize the segment tree
        SGTree seg(sz);
        seg.build(0, 0, sz - 1, sumArray);

        // answer the queries
        vector<int> ans(m, -1);
        for (int i = 0; i < m; i++)
        {
            int xi = queries[i][0], yi = queries[i][1];

            int lb = lower_bound(st, xi);
            int ub = upper_bound(st, yi);

            if (lb <= ub)
            {
                ans[i] = seg.query(0, 0, sz - 1, sumArray, lb, ub);
            }
        }
        return ans;
    }
};