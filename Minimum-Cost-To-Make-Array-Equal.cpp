// Approach 1: Finding weighted mean
class Solution
{
public:
    long long minCost(vector<int> &nums, vector<int> &cost)
    {
        // simplest median finding problem:
        int n = nums.size();
        if (n == 1)
            return 0;
        long long total = 0;
        for (auto &e : cost)
            total += 1ULL * e;
        vector<pair<int, int>> vpi;
        for (int i = 0; i < n; i++)
        {
            vpi.push_back({nums[i], cost[i]});
        }
        sort(begin(vpi), end(vpi));
        long long cnt = 0;
        int el;
        for (int i = 0; i < n; i++)
        {
            cnt += vpi[i].second;
            el = vpi[i].first;
            if (cnt >= (total + 1) / 2)
            {
                break;
            }
        }
        long long amt = 0;
        for (int i = 0; i < n; i++)
        {
            amt = amt + abs(vpi[i].first - el) * 1LL * vpi[i].second;
        }
        return amt;
    }
};

// Approach 2: Binary Search
class Solution
{
public:
    long long solve(vector<int> &nums, vector<int> &cost, int x)
    {
        long long ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            ans = ans + cost[i] * 1LL * abs(nums[i] - x);
        }
        return ans;
    }
    long long minCost(vector<int> &nums, vector<int> &cost)
    {
        // simplest binary search problem:
        // approach: when finally the array elements become equal then the array becomes
        // [x, x, x, ... ,x]
        // now the cost for this transformation is
        // cost[i]*|x-nums[i]| + cost[i+1]*|x-nums[i+1]| + ... + cost[n-1]*|x-nums[n-1]|
        // we have to minimize this cost
        // since cost will always be positive, we can apply binary search on the
        // search space of range of [1...1e6] to find our x making decisions based on
        // cost incurred
        int n = nums.size();
        long long c = LONG_MAX;
        int low = 1, high = 1e6;
        while (low <= high)
        {
            int mid = low + ((high - low) >> 1);
            int x1 = mid, x2 = mid + 1;
            long long cost1 = solve(nums, cost, x1);
            long long cost2 = solve(nums, cost, x2);
            c = min(cost1, cost2);
            if (cost1 == cost2)
            {
                return cost1;
            }
            else if (cost1 > cost2)
            {
                // move right
                low = mid + 1;
            }
            else
            {
                // move left
                high = mid - 1;
            }
        }
        return c;
    }
};