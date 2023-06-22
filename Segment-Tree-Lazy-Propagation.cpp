class SGTree
{
    vector<int> seg;
    vector<int> lazy;

public:
    SGTree()
    {
        seg.resize(1e5 + 1);
        lazy.resize(1e5 + 1);
    }

    SGTree(int n)
    {
        seg.resize(4 * n + 1);
        lazy.resize(4 * n + 1);
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
        seg[index] = seg[2 * index + 1] + seg[2 * index + 2];
    }

    int query(int index, int low, int high, int l, int r)
    {
        // first on reaching a node (here index) during a query confirm the lazy updates
        if (lazy[index] != 0)
        {
            // lazy update is required
            // assuming we add +x to a range
            seg[index] += (high - low + 1) * lazy[index];

            // propagate the update to child nodes
            if (low != high)
            {
                // we have a child
                lazy[2 * index + 1] += lazy[index];
                lazy[2 * index + 2] += lazy[index];
            }
            lazy[index] = 0;
        }

        // we have to find the answer in given range [l...r]
        // we make transitions using variables [low...high]

        // no overlap
        // l...r low...high or low...high l...r
        if (r < low || high < l)
        {
            return 0;
        }

        // complete overlap
        // l...low...high...r
        if (low >= l && high <= r)
        {
            return seg[index];
        }

        // partial overlap
        int mid = low + ((high - low) >> 1);
        int left = query(2 * index + 1, low, mid, l, r);
        int right = query(2 * index + 2, mid + 1, high, l, r);
        return left + right;
    }

    void rangeUpdate(int index, int low, int high, int l, int r, int val)
    {
        // first on reaching a node (here index) during a query confirm the lazy updates
        if (lazy[index] != 0)
        {
            // lazy update is required
            // assuming we add +x to a range
            seg[index] += (high - low + 1) * lazy[index];

            // propagate the update to child nodes
            if (low != high)
            {
                // we have a child
                lazy[2 * index + 1] += lazy[index];
                lazy[2 * index + 2] += lazy[index];
            }
            lazy[index] = 0;
        }

        // no overlap
        // l...r low...high or low...high l...r
        if (r < low || high < l)
        {
            return;
        }

        // complete overlap
        // l...low...high...r
        if (low >= l && high <= r)
        {

            seg[index] += (high - low + 1) * val;

            // propagate the update to child nodes
            if (low != high)
            {
                // we have a child
                lazy[2 * index + 1] += val;
                lazy[2 * index + 2] += val;
            }

            return;
        }

        // partial overlap
        int mid = low + ((high - low) >> 1);
        rangeUpdate(2 * index + 1, low, mid, l, r, val);
        rangeUpdate(2 * index + 2, mid + 1, high, l, r, val);
        seg[index] = seg[2 * index + 1] + seg[2 * index + 2];
    }
};