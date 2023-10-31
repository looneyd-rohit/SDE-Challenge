// Leetcode 1356

class Solution {
public:
    static bool cmp(int a, int b){
        int c1 = __builtin_popcount(a), c2 = __builtin_popcount(b);
        if(c1 == c2) return a <= b;
        return c1 < c2;
    }
    vector<int> sortByBits(vector<int>& arr) {
        int n = arr.size();
        // cout<<__builtin_popcount(1024)<<endl;
        sort(begin(arr), end(arr), cmp);
        return arr;
    }
};