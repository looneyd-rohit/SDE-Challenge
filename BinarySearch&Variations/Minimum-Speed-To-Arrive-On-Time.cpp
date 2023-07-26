// Leetcode 1870

class Solution {
public:
    bool isPossible(vector<int>& dist, double hour, int speed){
        int n = dist.size();
        double count = 0;
        for(int i=0; i<n; i++){
            double t = (dist[i] * 1.0) / speed;
            count += t;
            if(i == n-1) break;
            int t_rem = dist[i] % speed;
            if(t_rem > 0){
                count = ceil(count);
            }
        }
        return count <= hour;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        // we have to find the optimal speed, so binary search on it
        int low = 1, high = 1e7;
        while(low <= high){
            int mid = low + ((high - low) >> 1);
            int speed = mid;
            bool flag = isPossible(dist, hour, speed);
            if(flag){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return low > 1e7 ? -1 : low;
    }
};