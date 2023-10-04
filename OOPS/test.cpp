#include<bits/stdc++.h>
using namespace std;

int getRecommend(int n, unordered_map<int, list<int> >& adj, int start){
    vector<int> distances(n, INT_MAX);
    priority_queue<pair<int, int> > pq;
    pq.push({start, 0});
    distances[start] = 0;
    vector<int> counts(n, 0);
    counts[start] = 1;
    int maxi = 0;
    while(!pq.empty()){
        auto t = pq.top(); pq.pop();
        int node = t.first, dist = t.second;
        if(dist > 2) continue;
        for(auto& next: adj[node]){
            if(distances[next] > 1 + dist){
                distances[next] = 1 + dist;
                pq.push({next, distances[next]});
                counts[next] = 1;
            }else if(distances[next] == 1 + dist){
                counts[next]++;
            }
            maxi = max(maxi, counts[next]);
        }
    }
    for(int i=0; i<n; i++){
        if(maxi == counts[i]){
            return i;
        }
    }
    return -1;
}
void solve(int n, int m, vector<vector<int> > friendships){
    // construct graph
    unordered_map<int, list<int> > adj;
    for(auto& edge: friendships){
        int u = edge[0], v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> ans(n, -1);
    for(int i=0; i<n; i++){
        ans[i] = getRecommend(n, adj, i);
    }
    for(auto& e: ans) cout<<e<<" ";cout<<endl;
}

int main(){
    int n = 5, m = 5;
    vector<vector<int> > friendships;
    friendships.push_back({0,1});
    friendships.push_back({0, 2});
    friendships.push_back({1,3});
    friendships.push_back({2,3});
    friendships.push_back({3,4});
    solve(n, m, friendships);
    return 0;
}