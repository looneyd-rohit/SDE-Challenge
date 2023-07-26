// https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

// Approach 1:
// [IMP]: Greedy + Nice Approach (Finish from end to make room for more)

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool cmp(Job a, Job b){
        return a.profit > b.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    {
        // sort the jobs on basis or decreasing profit and try to do jobs on the last deadline
        // as possible since, it will make more room for jobs with lower deadlines and lower
        // profits to get executed if exists
        int jobs = 0, maxi = 0;
        sort(arr, arr+n, cmp);
        // to track which of the jobs got completed
        vector<int> deadlines(1e5+1, -1);
        for(int i=0; i<n; i++){
            if(deadlines[arr[i].dead]==-1){
                // job can be attended
                jobs++;
                maxi+=arr[i].profit;
                deadlines[arr[i].dead] = arr[i].id;
            }else{
                // try to do the job on a day before the deadline is reached
                int ind = arr[i].dead - 1;
                while(ind >= 1 && deadlines[ind]!=-1) ind--;
                if(ind >= 1){
                    jobs++;
                    maxi+=arr[i].profit;
                    deadlines[ind] = arr[i].id;
                }
            }
        }
        
        return {jobs, maxi};
    } 
};

// Approach 2:
// [IMP]: DSU related problem

class DSU{
    public:
    vector<int> parent;
    DSU(int n){
        parent.resize(n+1);
        for(int i=0; i<=n; i++) parent[i] = i;
    }
    int findParent(int u){
        if(u == parent[u]) return u;
        return parent[u] = findParent(parent[u]);
    }
    void unionSlot(int u, int v){
        // u should be parent of v
        parent[v] = u;
    }
};
class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool cmp(Job a, Job b){
        return a.profit > b.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr, arr+n, cmp);
        // initialize the DSU with maximum deadline possible
        // each time interval is referred to as slot in DSU
        // a job allocated a set, will have its parent as the next free
        // before it [a time slot for deadline t is t-1 to t]
        int maxi = 0;
        for(int i=0; i<n; i++) maxi = max(maxi, arr[i].dead);
        DSU dsu(maxi);
        int cnt = 0, profit = 0;
        for(int i=0; i<n; i++){
            // find the time slot available for this deadline
            int slot = dsu.findParent(arr[i].dead);
            if(slot > 0){
                // slot exists
                // slots are 1-indexed
                dsu.unionSlot(slot-1, slot);
                cnt++; profit += arr[i].profit;
            }
        }
        return {cnt, profit};
    } 
};