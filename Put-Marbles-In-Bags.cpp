// Leetcode 2551
// [IMP]: Heap/PQ based question

class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        // greedy problem --> [a,b,c,d,e,f]
        // if we form n bags of marbles at max (k tends to n)
        // then the sum of the bag will be a + (a+b) + (b+c) + ....+ f
        // start + [sum of adjacent pairs] + end
        // take the k-1 max pairs & k-1 min pairs of all the formed pairs
        int n = weights.size();
        // min heap will store the largest k-1 pairs
        priority_queue<int, vector<int>, greater<int>> mini;
        // max heap will store the smallest k-1 pairs
        priority_queue<int, vector<int>, less<int>> maxi;
        for(int i=1; i<n; i++){
            mini.push(weights[i-1]+weights[i]);
            maxi.push(weights[i-1]+weights[i]);
            if(mini.size() >= k) mini.pop();
            if(maxi.size() >= k) maxi.pop();
        }
        long long minSum = 0, maxSum = 0;
        while(!mini.empty()) maxSum += mini.top(), mini.pop();
        while(!maxi.empty()) minSum += maxi.top(), maxi.pop();
        return (weights.front()+weights.back()+maxSum) - (weights.front()+weights.back()+minSum);
    }
};