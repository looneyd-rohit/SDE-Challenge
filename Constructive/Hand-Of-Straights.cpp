// Leetcode 846

// Approach: store frequencies in a map and then iterate for all the consecutive elements and decrement counts
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize != 0) return false;
        map<int, int> mp;
        for(auto& e: hand) mp[e]++;
        for(auto& e: mp){
            int first = e.first;
            int f = e.second;
            if(f==0) continue;
            mp[first] = 0;
            for(int num=first+1; num<(first+groupSize); num++){
                if(mp[num]<f) return false;
                mp[num] -= f;
            }
        }
        return true;
    }
};