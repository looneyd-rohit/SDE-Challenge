// https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1
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