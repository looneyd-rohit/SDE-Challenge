// Leetcode 1834

// Approach [IMP]: Shortest Job First Scheduling Alogrithm (No Preemption)
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        // exact SJF Algorithm of Operating Systems
        // using a minheap will help us
        int n = tasks.size();
        vector<vector<int>> sortedTasks;
        for(int i=0; i<n; i++){
            int enqueueTime = tasks[i][0], processingTime = tasks[i][1];
            sortedTasks.push_back({enqueueTime, processingTime, i});
        }
        // sort according to arrival
        sort(begin(sortedTasks), end(sortedTasks));
        // initialize a time line variable
        long long currentTime = 0;
        int index = 0;    // index for traversing the tasks array
        // declare minheap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minheap;
        // declare vector for storing order
        vector<int> ans;
        // traverse until minheap is empty or all jobs completed
        while(index < n || !minheap.empty()){
            // edge case --> when there is huge time gap b/w two tasks or when it is
            // the starting task then, minheap becomes empty so no job can be taken out
            // from it
            if(minheap.empty() && currentTime < sortedTasks[index][0]){
                currentTime = sortedTasks[index][0];
            }
            
            // add tasks to the minheap which have arrived until currentTime
            while(index < n && sortedTasks[index][0] <= currentTime){
                minheap.push({sortedTasks[index][1], sortedTasks[index][2]});
                index++;
            }
            
            // now pull one task from the minheap
            auto minTask = minheap.top(); minheap.pop();
            currentTime += minTask.first;
            
            // store order
            ans.push_back(minTask.second);
        }
        return ans;
    }
};