// Leetcode 658

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        // maxheap will help to prune not needed elements
        priority_queue<pair<int, int>> maxheap;
        for(int i=0; i<n; i++){
            maxheap.push({abs(arr[i]-x), i});
            if(maxheap.size() > k){
                maxheap.pop();
            }
        }
        vector<int> ans;
        while(!maxheap.empty()){
            ans.push_back(arr[maxheap.top().second]);
            maxheap.pop();
        }
        sort(begin(ans), end(ans));
        return ans;
    }
};