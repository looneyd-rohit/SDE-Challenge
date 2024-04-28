// Leetcode 239

// Approach: monotonic deque
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int n = nums.size();
        deque<pair<int, int>> dq;
        vector<int> ans;
        int i = 0, j = 0;
        while (j < n)
        {
            int el = nums[j];
            // push to dq only if it greater than already is encountered
            // this ensures us to maintain a monotonically decreasing sequence
            while (!dq.empty() && dq.back().first <= el)
            {
                dq.pop_back();
            }
            dq.push_back({el, j});

            if (j - i + 1 < k)
            {
                // window not yet reached
                j++;
            }
            else if (j - i + 1 == k)
            {
                // we have to pick the maximum element
                ans.push_back(dq.front().first);

                if (!dq.empty() && dq.front().second == i)
                {
                    dq.pop_front();
                }

                i++;
                j++;
            }
        }
        return ans;
    }
};


// Approach: new and revamped
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<pair<int, int>> dq;
        vector<int> ans;
        for(int i=0; i<n; i++){
            while(!dq.empty() && dq.back().first < nums[i]) dq.pop_back();

            while(!dq.empty() && dq.front().second < (i-k+1)) dq.pop_front();

            dq.push_back({nums[i], i});

            if((i+1) >= k) ans.push_back(dq.front().first);
        }
        return ans;
    }
};