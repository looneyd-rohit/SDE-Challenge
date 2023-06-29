// Leetcode 373
class abc
{
public:
    bool operator()(tuple<int, int, int, int> &a, tuple<int, int, int, int> &b)
    {
        return get<0>(a) + get<1>(a) > get<0>(b) + get<1>(b);
    }
};
class Solution
{
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        // similar to merge k sorted lists pattern
        int n1 = nums1.size(), n2 = nums2.size();
        vector<vector<int>> ans;
        if (n1 == 0 || n2 == 0 || k == 0)
            return ans;
        priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, abc> pq;

        for (int i = 0; i < n1; i++)
            pq.push(tuple<int, int, int, int>(nums1[i], nums2[0], i, 0));

        while (k-- && !pq.empty())
        {
            auto t = pq.top();
            pq.pop();
            ans.push_back({get<0>(t), get<1>(t)});
            if (get<3>(t) < n2 - 1)
            {
                pq.push({nums1[get<2>(t)], nums2[get<3>(t) + 1], get<2>(t), get<3>(t) + 1});
            }
        }

        return ans;
    }
};