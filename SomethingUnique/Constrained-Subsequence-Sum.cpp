// Leetcode 1425

// Approach 1: top down dp + memo --> TLE + MLE

// Approach 2: bottom up dp -> TLE

// Approach 3: optimization over bottom up dp -> T.C. ~ O(nlogn) S.C. ~ O(n)
// dp + heaps/sets
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> sums(n, 0);
        for(int i=0; i<n; i++) sums[i] = nums[i];
        long long maxi = sums[0];
        set<pair<long long, int>> st;
        st.insert({sums[0], 0});
        for(int i=1; i<n; i++){
            // since for a particular i-th index we need the j-th that gives maximum sum
            // we can do this, by storing the sums in a particular order such that
            // maximum can be derived in O(logn) time
            // fetch from the data structure
            while(!st.empty() && i-st.rbegin()->second>k) st.erase(*st.rbegin());
            auto p = *st.rbegin();
            long long s = p.first, j = p.second;
            sums[i] = max(sums[i], nums[i]+s);
            // update the data structure
            st.insert({sums[i], i});
            maxi = max(maxi, sums[i]);
        }
        return maxi;
    }
};

// Approach 4: further optimizaton over dp => dp + deque -> T.C. ~ O(n) S.C. ~ O(n)
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> sums(n, 0);
        for(int i=0; i<n; i++) sums[i] = nums[i];
        long long maxi = sums[0];
        deque<pair<long long, long long>> dq;    // decreasing deque -> maximum in front
        dq.push_back({sums[0], 0});
        for(int i=1; i<n; i++){
            // since for a particular i-th index we need the j-th that gives maximum sum
            // we can do this, by storing the sums in a particular order such that
            // maximum can be derived in O(1) time
            // fetch from the data structure
            while(!dq.empty() && (i-dq.front().second)>k) dq.pop_front();

            if(!dq.empty()) sums[i] = max(sums[i], nums[i] + dq.front().first);

            // update the data structure
            while(!dq.empty() && dq.back().first<=sums[i]) dq.pop_back();
            dq.push_back({sums[i], i});

            maxi = max(maxi, sums[i]);
        }
        return maxi;
    }
};