// Leetcode 1962

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int n = piles.size();
        priority_queue<int> maxheap;
        for(int i=0; i<n; i++) maxheap.push(piles[i]);
        while(k-- && !maxheap.empty()){
            int top = maxheap.top(); maxheap.pop();
            int res = top - top/2;
            maxheap.push(res);
        }
        int sum = 0;
        while(!maxheap.empty()){
            int top = maxheap.top(); maxheap.pop();
            sum += top;
        }
        return sum;
    }
};