// Leetcode 1306
// [IMP]: forming different type of graph
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        // seems like a graph problem
        int n = arr.size();
        unordered_map<int, list<int>> adj;
        unordered_set<int> endIndices;
        for(int i=0; i<n; i++){
            int el = arr[i];
            if(el == 0){
                endIndices.insert(i);
                continue;
            }
            int prev = i - el;
            if(prev >= 0) adj[i].push_back(prev);
            int next = i + el;
            if(next < n) adj[i].push_back(next);
        }
        if(endIndices.empty()) return false;
        queue<int> q;
        q.push(start);
        vector<bool> visited(n, false);
        while(!q.empty()){
            auto f = q.front(); q.pop();
            if(endIndices.count(f)) return true;
            if(visited[f]) continue;
            visited[f] = true;
            // visit neighbours
            for(auto& next: adj[f]){
                if(!visited[next]){
                    q.push(next);
                }
            }
        }
        return false;
    }
};