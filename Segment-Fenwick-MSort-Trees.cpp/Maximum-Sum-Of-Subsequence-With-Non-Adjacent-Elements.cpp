// Leetcode 3165

// Approach: segment trees logic
class SGTree{
public:
    vector<tuple<int, int, int, int>> segarr;
    // <take_first_take_last, skip_first_take_last, take_first_skip_last, skip_first_skip_last>
    SGTree(int n = 0){
        this->segarr.resize(4*n+1, tuple<int, int, int, int>(0, 0, 0, 0));
    }
    inline auto merge(tuple<int, int, int, int>& t1, tuple<int, int, int, int>& t2){
        int l1 = get<0>(t1), l2 = get<1>(t1), l3 = get<2>(t1), l4 = get<3>(t1);
        int r1 = get<0>(t2), r2 = get<1>(t2), r3 = get<2>(t2), r4 = get<3>(t2);
        int m1 = max({l3+r1, l1+r2, l3+r2});
        int m2 = max({l2+r2, l4+r1, l4+r2});
        int m3 = max({l3+r3, l1+r4, l3+r4});
        int m4 = max({l2+r4, l4+r3, l4+r4});
        return tuple<int, int, int, int>(m1, m2, m3, m4);
    }
    void build(int index, int low, int high, vector<int>& arr){
        if(low == high){
            this->segarr[index] = tuple<int, int, int, int>(arr[low], 0, 0, 0);
            return;
        }
        int mid = low + ((high - low) >> 1);
        build(2*index+1, low, mid, arr);
        build(2*index+2, mid+1, high, arr);
        this->segarr[index] = merge(this->segarr[2*index+1], this->segarr[2*index+2]);
    }
    void update(int index, int low, int high, int ind, int val){
        if(low == high){
            this->segarr[index] = tuple<int, int, int, int>(val, 0, 0, 0);
            return;
        }
        int mid = low + ((high - low) >> 1);
        if(ind <= mid){
            update(2*index+1, low, mid, ind, val);
        }else{
            update(2*index+2, mid+1, high, ind, val);
        }
        this->segarr[index] = merge(this->segarr[2*index+1], this->segarr[2*index+2]);
    }
    auto query(int index, int low, int high, int l, int r){
        // no overlap
        if(high<l || r<low) return tuple<int, int, int, int>(0, 0, 0, 0);

        // full overlap
        if(l<=low && high<=r) return this->segarr[index];

        // partial overlap
        int mid = low + ((high - low) >> 1);
        auto left = query(2*index+1, low, mid, l, r);
        auto right = query(2*index+2, mid+1, high, l, r);
        return merge(left, right);
    }
};
class Solution {
public:
    const int M = 1e9+7;
    int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        SGTree *sgtree = new SGTree(n);
        sgtree->build(0, 0, n-1, nums);
        long long ans = 0;
        for(auto& query: queries){
            int pos = query[0], x = query[1];
            sgtree->update(0, 0, n-1, pos, x);
            auto t = sgtree->query(0, 0, n-1, 0, n-1);
            ans += max({get<0>(t), get<1>(t), get<2>(t), get<3>(t)}) % M;
            ans %= M;
        }
        return ans;
    }
};