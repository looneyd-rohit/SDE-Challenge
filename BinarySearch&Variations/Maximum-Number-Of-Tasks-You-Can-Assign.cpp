// Leetcode 2071

class Solution {
public:
    bool isPossible(vector<int>& tasks, vector<int>& workers, int pills, int strength, int numOfTasks){
        int n = tasks.size(),  m = workers.size();
        multiset<int> ms(begin(workers), end(workers));
        int cnt = 0;
        for(int i=numOfTasks-1; i>=0; i--){
            int s = tasks[i];
            auto it = ms.lower_bound(s);
            if(it == ms.end()){
                // task cannot be completed with current workers
                // try with pill
                if(pills){
                    int s_ = s - strength;
                    auto it2 = ms.lower_bound(s_);
                    if(it2 == ms.end()){
                        // cannot be completed even with pills
                    }else{
                        // possbile with taking pills
                        pills--;
                        cnt++;
                        ms.erase(it2);
                    }
                }
            }else{
                // task can be completed, hence do it
                ms.erase(it);
                cnt++;
            }
        }
        return cnt >= numOfTasks;
    }
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int n = tasks.size(),  m = workers.size();
        int low = 0, high = n;
        sort(begin(tasks), end(tasks));
        // complete the large strength tasks at first, because we want to reduce the diff in strength
        // between worker and task at any point in time, which leads to better utilization
        // a smaller strength task may get completed by using pill, but a larger strength may not
        
        // complete tasks from larger to smaller and try going on increasing tasks limit until
        // not possible
        int ans = 0;
        while(low <= high){
            int mid = low + ((high - low) >> 1);
            int numOfTasks = mid;
            bool flag = isPossible(tasks, workers, pills, strength, numOfTasks);
            if(flag){
                // can be completed, look for more
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return high;
    }
};