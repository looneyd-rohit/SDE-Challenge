// Leetcode 752

// Approach: simple bfs shortest path finding
class Solution {
public:
    inline int mySTOI(string& s){
        int n = s.length();
        int ans = 0;
        for(int i=0; i<n; i++){
            ans = ans * 10 + (s[i]-'0');
        }
        return ans;
    }
    int openLock(vector<string>& deadends, string target) {
        int n = deadends.size();
        unordered_set<string> deads;
        for(auto& str: deadends) deads.insert(str);
        queue<pair<string, int>> q;
        q.push({"0000", 0});
        vector<bool> visited(10000, false);
        while(!q.empty()){
            auto f = q.front(); q.pop();
            string node = f.first;
            int dist = f.second;
            if(node==target) return dist;
            if(visited[mySTOI(node)]) continue;
            if(deads.count(node)) continue;
            visited[mySTOI(node)] = true;
            // visit neighbours
            for(int k=0; k<4; k++){
                char temp = node[k];

                node[k] = (char)(((temp-'0'+1) % 10) + '0');
                if(!visited[mySTOI(node)]) q.push({node, dist+1});

                node[k] = (char)(((temp-'0'-1+10) % 10) + '0');
                if(!visited[mySTOI(node)]) q.push({node, dist+1});

                node[k] = temp;
            }
        }
        return -1;
    }
};