// https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1

class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
        long long mini = LONG_LONG_MAX;
        sort(begin(a), end(a));
        long long i=0, j=m-1;
        while(j<n){
            mini = min(mini, a[j]-a[i]);
            j++; i++;
        }
        return mini;
    }   
};