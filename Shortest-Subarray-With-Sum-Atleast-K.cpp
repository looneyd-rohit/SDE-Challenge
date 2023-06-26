// Leetcode 862
class Solution
{
public:
    int shortestSubarray(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<long long> presum(n, nums[0]);
        for (int i = 1; i < n; i++)
        {
            presum[i] = presum[i - 1] + nums[i];
        }
        int mini = INT_MAX;
        deque<pair<long long, int>> dq;
        for (int i = 0; i < n; i++)
        {
            long long sum = presum[i];

            if (sum >= k)
                mini = min(mini, i + 1);

            long long req = sum - k;
            // now find all those elements which are <= req and find the length of
            // the subarray from that index of req to current i
            // we can safely eliminate all elements which are <= req, because if the element
            // is less than or equal req and it is present before i in the original array
            // then it forms a subarray of length say L, then L can never be smaller than some
            // j > i, j --> next elements of the array
            while (!dq.empty() && req >= dq.front().first)
            {
                mini = min(mini, i - dq.front().second);
                dq.pop_front();
            }

            // push the current sum in dq maintaining a increasing sequence
            // we are removing the elements greater than current sum from deque
            // because we will intend to find the "req" and because out k is always positive
            // so sum-k will always be less than sum, so we will be needing elements lesser than
            // the sum
            while (!dq.empty() && sum <= dq.back().first)
            {
                dq.pop_back();
            }
            dq.push_back({sum, i});
        }
        return mini == INT_MAX ? -1 : mini;
    }
};