// https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1

class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // sum of lengths gives cost of joining, hence this sum gets
        // carried further and contributes again for joining further
        // hence, if we can take the smallest sum then our job is done
        // use --> minheap
        priority_queue<long long, vector<long long>, greater<long long>> minheap;
        for(long long i=0; i<n; i++) minheap.push(arr[i]);
        long long cost = 0;
        while(minheap.size() >= 2){
            long long first = minheap.top(); minheap.pop();
            long long second = minheap.top(); minheap.pop();
            long long sum = first + second;
            cost += sum;
            minheap.push(sum);
        }
        return cost;
    }
};