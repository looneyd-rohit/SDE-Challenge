// Leetcode 3161

// Approach: segment trees approach for finding maximum
class SGTree{
public:
    vector<int> segarr;
    SGTree(int n=0){
        this->segarr.resize(4*n+1, 0);
    }
    void build(int index, int low, int high, vector<int>& arr){
        if(low == high){
            this->segarr[index] = arr[low];
            return;
        }
        int mid = low + ((high - low) >> 1);
        build(2*index+1, low, mid, arr);
        build(2*index+2, mid+1, high, arr);
        this->segarr[index] = max(this->segarr[2*index+1], this->segarr[2*index+2]);
    }
    void update(int index, int low, int high, int ind, int val){
        if(low == high){
            this->segarr[index] = val;
            return;
        }
        int mid = low + ((high - low) >> 1);
        if(ind <= mid){
            update(2*index+1, low, mid, ind, val);
        }else{
            update(2*index+2, mid+1, high, ind, val);
        }
        this->segarr[index] = max(this->segarr[2*index+1], this->segarr[2*index+2]);
    }
    int query(int index, int low, int high, int l, int r){
        // no overlap
        if(high<l || r<low) return 0;

        // full overlap
        if(l<=low && high<=r) return this->segarr[index];

        // partial overlap
        int mid = low + ((high - low) >> 1);
        int left = query(2*index+1, low, mid, l, r);
        int right = query(2*index+2, mid+1, high, l, r);
        return max(left, right);
    }
};
class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        int n = min((int)(5 * 1e4), (int)(3 * queries.size()));
        vector<bool> ans;
        set<int> st;
        st.insert(0); st.insert(n+1);
        SGTree *sgtree = new SGTree(n);
        for(auto& query: queries){
            if(query[0]==1){
                int x = query[1];
                int next_obs = *st.upper_bound(x);
                int prev_obs = *(--st.upper_bound(x));
                st.insert(x);
                sgtree->update(0, 0, n-1, prev_obs, x-prev_obs);
                sgtree->update(0, 0, n-1, x, next_obs-x);
            }else{
                int x = query[1], sz = query[2];
                int prev_obs = *(--st.upper_bound(x));
                bool flag = (x-prev_obs)>=sz || sgtree->query(0, 0, n-1, 0, prev_obs-1)>=sz;
                if(flag){
                    ans.push_back(true);
                }else{
                    ans.push_back(false);
                }
            }
        }
        return ans;
    }
};