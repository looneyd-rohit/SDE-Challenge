// Leetcode 621
// [IMP]: Greedy type approach, form schedules
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int sz = tasks.size();
        vector<int> taskFreq(26, 0);
        int maxFreq = 0;
        for(int i=0; i<sz; i++){
            char task = tasks[i];
            taskFreq[task-'A']++;
            maxFreq = max(maxFreq, taskFreq[task-'A']);
        }
        int totalTime = (maxFreq-1) * (n+1);
        for(auto& e: taskFreq) if(maxFreq == e) totalTime++;
        return max(sz, totalTime);
    }
};