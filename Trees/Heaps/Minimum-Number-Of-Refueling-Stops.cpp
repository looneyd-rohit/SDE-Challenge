// Leetcode 871

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        // since we have to minimize refuelling, we should refuel only when necessary
        // and refuel from those stations which have maximum fuel
        // target is not present in array, so adding it
        stations.push_back({target, 0});
        int n = stations.size();
        priority_queue<pair<int, int>> maxheap;    // stores <fuel, position>
        int balance = startFuel, stops = 0;
        int i = 0;
        for(; i<n; i++){
            int distanceToTravel = i==0 ? stations[i][0] : stations[i][0] - stations[i-1][0];
            int diff = balance - distanceToTravel;
            if(diff > 0){
                // we can travel with the current fuel, to i-th position, so don't take
                // any fuel for now, take it later
                if(stations[i][0] == target) return stops;
                balance = diff;
                maxheap.push({stations[i][1], stations[i][0]});
            }else if(diff == 0){
                if(stations[i][0] == target) return stops;
                maxheap.push({stations[i][1], stations[i][0]});
                auto top = maxheap.top(); maxheap.pop();
                balance = top.first;
                stops++;
            }else{
                // we cannot travel to the i-th position we current fuel so we have to refuel
                if(maxheap.empty()){
                    // no refueling stops previously, so break out
                    break;
                }else{
                    auto top = maxheap.top(); maxheap.pop();
                    balance += top.first;
                    stops++;
                    i--;
                }
            }
        }
        if(i < n) return -1;
        return stops;
    }
};