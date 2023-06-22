class SGTree
{
    vector<int> seg;

public:
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
        seg[index] = min(seg[2 * index + 1], seg[2 * index + 2]);
    }

    int query(int index, int low, int high, vector<int> &arr, int l, int r)
    {
        // we have to find the answer in given range [l...r]
        // we make transitions using variables [low...high]

        // no overlap
        // l...r low...high or low...high l...r
        if (r < low || high < l)
        {
            return INT_MAX;
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
        return min(left, right);
    }

    void pointUpdate(int index, int low, int high, vector<int> &arr, int i, int val)
    {
        // base case
        if (low == high)
        {
            seg[index] = arr[low];
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
        seg[index] = min(seg[2 * index + 1], seg[2 * index + 2]);
    }
};