// Leetcode 2391

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size();
        int m = -1, p=-1, g=-1;
        int extra = 0;
        for(int i=0; i<n; i++){
            string temp = garbage[i];
            if(temp.find("M")!=string::npos){
                m = i;
            }
            if(temp.find("P")!=string::npos){
                p = i;
            }
            if(temp.find("G")!=string::npos){
                g = i;
            }
            extra += temp.size();
        }
        for(int i=1; i<n-1; i++) travel[i] += travel[i-1];
        int ans = 0;
        if(m>0) ans += travel[m-1];
        if(p>0) ans += travel[p-1];
        if(g>0) ans += travel[g-1];
        // cout<<extra<<endl;
        return ans + extra;
    }
};