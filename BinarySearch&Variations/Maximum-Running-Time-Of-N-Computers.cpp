// Leetcode 2141

// Approach [IMP]: Binary Search on Answer Space (Two variations of possible() function)
class Solution {
public:
    // bool isPossible(int n, vector<int>& batteries, long long time){
    //     int b = batteries.size();
    //     long long total = time * n;    // total time we require from batteries
    //     for(int i=0; i<b; i++){
    //         // subtract the minimum of contribution from each battery
    //         total -= min(1LL*batteries[i], time);
    //         if(total <= 0) return true;
    //     }
    //     return false;;
    // }
    bool isPossible(int n, vector<int>& batteries, long long time){
        int b = batteries.size();
        long long total = 0;
        int count = 0;
        for(int i=0; i<b; i++){
            total += batteries[i];
            if(total >= time){
                total -= time;
                count++;
                if(count == n) return true;
            }
        }
        return false;;
    }
    
    long long maxRunTime(int n, vector<int>& batteries) {
        int b = batteries.size();
        sort(begin(batteries), end(batteries));    // sorting because maximum time will depend
        // on lower powered batteries
        long long low = *min_element(begin(batteries), end(batteries)), high = 0;
        for(auto& e: batteries){
            high += e;
        }
        high /= n;
        while(low <= high){
            long long mid = low + ((high - low) >> 1);
            
            int time = mid;
            bool flag = isPossible(n, batteries, time);
            if(flag){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return high;
    }
};