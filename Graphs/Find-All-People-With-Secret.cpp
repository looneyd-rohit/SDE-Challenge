// Leetcode 2092

// Approach 1: do bfs at every meeting time
class Solution {
public:
  vector<int> findAllPeople(int n, vector<vector<int>> &meetings,
                            int firstPerson) {
    // perform bfs at a time for spreading the news to others
    int m = meetings.size();
    map<int, vector<pair<int, int>>> mp;
    for (vector<int> &meet : meetings) {
      int u = meet[0], v = meet[1], time = meet[2];
      mp[time].push_back({u, v});
    }
    vector<bool> knowsSecret(n, false);
    knowsSecret[0] = knowsSecret[firstPerson] = true;
    // now traverse in order of time and do bfs
    for (auto &vec : mp) {
      int t = vec.first;
      vector<pair<int, int>> meets = vec.second;
      // construct adjacency list
      unordered_map<int, vector<int>> adj;
      unordered_set<int> queueItems;
      queue<int> q;
      for (auto &pr : meets) {
        int u = pr.first, v = pr.second;
        adj[u].push_back(v);
        adj[v].push_back(u);
        if (knowsSecret[u] && queueItems.find(u) == queueItems.end()) {
          q.push(u);
          queueItems.insert(u);
        }
        if (knowsSecret[v] && queueItems.find(v) == queueItems.end()) {
          q.push(v);
          queueItems.insert(v);
        }
      }
      // bfs
      while (!q.empty()) {
        int node = q.front();
        q.pop();
        // visit neighbours
        for (auto &next : adj[node]) {
          if (!knowsSecret[next]) {
            knowsSecret[next] = true;
            q.push(next);
          }
        }
      }
    }
    vector<int> ans;
    for (int i = 0; i < n; i++)
      if (knowsSecret[i])
        ans.push_back(i);
    return ans;
  }
};

// Approach 2: bfs on person + time
class Solution {
public:
  vector<int> findAllPeople(int n, vector<vector<int>> &meetings,
                            int firstPerson) {
    // bfs --> with people + time
    int m = meetings.size();
    unordered_map<int, list<pair<int, int>>> adj;
    for (auto &meet : meetings) {
      int u = meet[0], v = meet[1], time = meet[2];
      adj[u].push_back({v, time});
      adj[v].push_back({u, time});
    }
    queue<pair<int, int>> q;
    q.push({0, 0});
    q.push({firstPerson, 0});
    vector<int> timeOfSecret(n, 1e9);
    timeOfSecret[0] = timeOfSecret[firstPerson] = 0;
    while (!q.empty()) {
      auto f = q.front();
      q.pop();
      int node = f.first, time = f.second;
      // visit neighbours
      for (auto &next : adj[node]) {
        if (time <= next.second && next.second < timeOfSecret[next.first]) {
          timeOfSecret[next.first] = next.second;
          q.push({next.first, next.second});
        }
      }
    }
    vector<int> ans;
    for (int i = 0; i < n; i++)
      if (timeOfSecret[i] != 1e9)
        ans.push_back(i);
    return ans;
  }
};

// Approach 3: dfs on person + time
class Solution {
public:
  void dfs(int node, int time, unordered_map<int, list<pair<int, int>>> &adj,
           vector<int> &timeOfSecret) {
    for (auto &next : adj[node]) {
      if (time <= next.second && next.second < timeOfSecret[next.first]) {
        timeOfSecret[next.first] = next.second;
        dfs(next.first, next.second, adj, timeOfSecret);
      }
    }
  }
  vector<int> findAllPeople(int n, vector<vector<int>> &meetings,
                            int firstPerson) {
    // dfs --> with people + time
    int m = meetings.size();
    unordered_map<int, list<pair<int, int>>> adj;
    for (auto &meet : meetings) {
      int u = meet[0], v = meet[1], time = meet[2];
      adj[u].push_back({v, time});
      adj[v].push_back({u, time});
    }
    vector<int> timeOfSecret(n, 1e9);
    timeOfSecret[0] = timeOfSecret[firstPerson] = 0;
    // dfs
    dfs(0, 0, adj, timeOfSecret);
    dfs(firstPerson, 0, adj, timeOfSecret);
    vector<int> ans;
    for (int i = 0; i < n; i++)
      if (timeOfSecret[i] != 1e9)
        ans.push_back(i);
    return ans;
  }
};

// Approach 4: bfs + priority queue (dijkstra) on person + time
class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        // bfs + minheap (dijkstra) --> with people + time
        int m = meetings.size();
        unordered_map<int, list<pair<int, int>>> adj;
        for(auto& meet: meetings){
            int u = meet[0], v = meet[1], time = meet[2];
            adj[u].push_back({v, time});
            adj[v].push_back({u, time});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, 0}); q.push({0, firstPerson});
        vector<int> timeOfSecret(n, 1e9);
        timeOfSecret[0] = timeOfSecret[firstPerson] = 0;
        while(!q.empty()){
            auto f = q.top(); q.pop();
            int time = f.first, node = f.second;

            // discard node if time > timeOfSecret
            if(time > timeOfSecret[node]) continue;

            // visit neighbours
            for(auto& next: adj[node]){
                if(time <= next.second && next.second < timeOfSecret[next.first]){
                    timeOfSecret[next.first] = next.second;
                    q.push({next.second, next.first});
                }
            }
        }
        vector<int> ans;
        for(int i=0; i<n; i++) if(timeOfSecret[i]!=1e9) ans.push_back(i);
        return ans;
    }
};