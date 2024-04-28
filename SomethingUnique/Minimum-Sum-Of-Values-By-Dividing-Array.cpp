// Leetcode 3117

// Approach 1: using 3D dp (works due to some mathematical proof of 3D not being fully 3D)
class Solution {
public:
    // int dp[(int)1e5+1][11];
    vector<vector<unordered_map<int, int>>> dp;
    int solve(int i, int j, int a, int n, int m, vector<int>& nums, vector<int>& andValues){
        // base cases
        if(i == n && j == m) return 0;
        if(i == n) return 1e9;
        if(j == m) return 1e9;
        
        if(dp[i][j].find(a)!=dp[i][j].end()) return dp[i][j][a];
        
        
        // take
        int take = solve(i+1, j, a&nums[i], n, m, nums, andValues);
        
        
        // not take
        int not_take = 1e9;
        if((a & nums[i])==andValues[j]){
            not_take = nums[i] + solve(i+1, j+1, (1<<30)-1, n, m, nums, andValues);
        }
        
        return dp[i][j][a] = min(take, not_take);
    }
    int minimumValueSum(vector<int>& nums, vector<int>& andValues) {
        int n = nums.size(), m = andValues.size();
        // memset(dp, -1, sizeof(dp));
        dp.resize(n+1, vector<unordered_map<int, int>>(m+1));
        int ans = solve(0, 0, (1<<30)-1, n, m, nums, andValues);
        if(ans == 1e9) return -1;
        return ans;
    }
};


// Approach 2: using 2D dp + merging technique (comes with lot of practice)
class SGTree{
public:
    vector<int> segarr;
    SGTree(int n=0){
        this->segarr.resize(4*n+1, (1<<30)-1);
    }
    void build(int index, int low, int high, vector<int>& arr){
        if(low == high){
            this->segarr[index] = arr[low];
            return;
        }
        int mid = low + ((high - low) >> 1);
        build(2*index+1, low, mid, arr);
        build(2*index+2, mid+1, high, arr);
        this->segarr[index] = this->segarr[2*index+1] & this->segarr[2*index+2];
    }
    void update(int index, int low, int high, int ind, int val){
        if(low == high){
            this->segarr[index] = val;
            return;
        }
        int mid = low + ((high - low) >> 1);
        if(ind <= mid) update(2*index+1, low, mid, ind, val);
        else update(2*index+2, mid+1, high, ind, val);
        this->segarr[index] = this->segarr[2*index+1] & this->segarr[2*index+2];
    }
    int query(int index, int low, int high, int l, int r){
        // no overlap
        if(r<low || high<l) return (1<<30)-1;
        
        // full overlap
        if(l<=low && high<=r) return this->segarr[index];
        
        // partial overlap
        int mid = low + ((high - low) >> 1);
        int left = query(2*index+1, low, mid, l, r);
        int right = query(2*index+2, mid+1, high, l, r);
        return (left & right);
    }
};

class SGTreeMin{
public:
    vector<pair<int, int>> segarr;
    SGTreeMin(int n=0){
        this->segarr.resize(4*n+1);
    }
    void build(int index, int low, int high, vector<int>& arr){
        if(low == high){
            this->segarr[index].first = arr[low];
            this->segarr[index].second = low;
            return;
        }
        int mid = low + ((high - low) >> 1);
        build(2*index+1, low, mid, arr);
        build(2*index+2, mid+1, high, arr);
        if(this->segarr[2*index+1].first > this->segarr[2*index+2].first){
            this->segarr[index].first = this->segarr[2*index+2].first;
            this->segarr[index].second = this->segarr[2*index+2].second;
        }else{
            this->segarr[index].first = this->segarr[2*index+1].first;
            this->segarr[index].second = this->segarr[2*index+1].second;
        }
    }
    void update(int index, int low, int high, int ind, int val){
        if(low == high){
            this->segarr[index].first = val;
            this->segarr[index].second = ind;
            return;
        }
        int mid = low + ((high - low) >> 1);
        if(ind <= mid) update(2*index+1, low, mid, ind, val);
        else update(2*index+2, mid+1, high, ind, val);
        if(this->segarr[2*index+1].first > this->segarr[2*index+2].first){
            this->segarr[index].first = this->segarr[2*index+2].first;
            this->segarr[index].second = this->segarr[2*index+2].second;
        }else{
            this->segarr[index].first = this->segarr[2*index+1].first;
            this->segarr[index].second = this->segarr[2*index+1].second;
        }
    }
    pair<int, int> query(int index, int low, int high, int l, int r){
        // no overlap
        if(r<low || high<l) return make_pair(1e9, -1);
        
        // full overlap
        if(l<=low && high<=r) return this->segarr[index];
        
        // partial overlap
        int mid = low + ((high - low) >> 1);
        auto left = query(2*index+1, low, mid, l, r);
        auto right = query(2*index+2, mid+1, high, l, r);
        if(left.first > right.first){
            return right;
        }else{
            return left;
        }
    }
};

class Solution {
public:
    long long dp[(int)1e5+1][11];
    long long solve(int i, int j, int n, int m, SGTree* sgtree, vector<int>& nums, vector<int>& andValues){
        if(i == n && j == m) return 0;
        if(i == n) return 1e9;
        // don't keep (j==m) as base case since merging is allowed

        if(dp[i][j]!=-1) return dp[i][j];

        // [IMP] : observer the working of the function carefully
        // take (merge the current index with already made previous subarray if AND matches)
        long long take = 1e9;
        if(i > 0 && ((andValues[j-1]&nums[i]) == andValues[j-1])){
            take = -nums[i-1] + nums[i] + solve(i+1, j, n, m, sgtree, nums, andValues);
        }
        
        // {utility for not_take part}
        // [IMP] : binary search to find the first good index
        // AND operation is monotonically decreasing so we can apply binary search
        // since as more numbers get AND-ed the chances of decreasing is more
        int first = n;
        if(j < m){
            int req = andValues[j];
            int low = i, high = n-1;
            while(low <= high){
                int mid = low + ((high - low) >> 1);
                int curr = sgtree->query(0, 0, n-1, i, mid);
                if(curr == req){
                    first = min(first, mid);
                    high = mid - 1;
                }else if(curr < req){
                    high = mid - 1;
                }else{
                    low = mid + 1;
                }
            }
        }

        // not_take (start new subarray from current index and end it at first 
        // possible index)
        long long not_take = 1e9;
        if(first < n){
            not_take = nums[first] + solve(first+1, j+1, n, m, sgtree, nums, andValues);
        }
        
        // [NOTE] : here take is merging step and not_take is creation step
        
        return dp[i][j] = min(take, not_take);
    }
    int minimumValueSum(vector<int>& nums, vector<int>& andValues) {
        int n = nums.size(), m = andValues.size();
        SGTree *sgtree = new SGTree(n);
        sgtree->build(0, 0, n-1, nums);
        memset(dp, -1, sizeof(dp));
        int ans = solve(0, 0, n, m, sgtree, nums, andValues);
        if(ans == 1e9) return -1;
        return ans;
    }
};

// Approach 3: bottom up + optimization by converting dp to segment trees because of the fact that we are taking minimum in a range [l...r]
