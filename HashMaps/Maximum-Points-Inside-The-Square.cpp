// Leetcode 3143

// Approach: simple two hashmap approach to eliminate duplicate points
class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        int n = points.size();
        unordered_map<char, long long> mp, mp2;
        for(int i=0; i<n; i++){
            int x = abs(points[i][0]), y = abs(points[i][1]);
            long long dist = max(x, y) * 1LL * max(x, y);
            char ch = s[i];
            if(mp.find(ch)==mp.end()) mp[ch] = dist;
            else{
                // conflicting point found
                if(mp[ch]>dist){
                    if(mp2.find(ch)==mp2.end()) mp2[ch] = mp[ch];
                    else mp2[ch] = min(mp2[ch], mp[ch]);
                }else if(mp[ch]<dist){
                    if(mp2.find(ch)==mp2.end()) mp2[ch] = dist;
                    else mp2[ch] = min(mp2[ch], dist);
                }else{
                    if(mp2.find(ch)==mp2.end()) mp2[ch] = dist-1;
                    else mp2[ch] = min(mp2[ch], dist-1);
                }
                mp[ch] = min(mp[ch], dist);
            }
        }
        if(mp2.size()==0) return n;
        long long mini = LONG_MAX;
        for(auto& e: mp2) mini = min(mini, e.second);
        int count = 0;
        for(int i=0; i<n; i++){
            int x = abs(points[i][0]), y = abs(points[i][1]);
            long long dist = max(x, y) * 1LL * max(x, y);
            if(dist < mini) count++;
        }
        return count;
    }
};