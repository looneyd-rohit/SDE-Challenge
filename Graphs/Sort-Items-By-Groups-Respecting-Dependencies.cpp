// Leetocode 1203
// [IMP]: TopoSort IMPORTANT Pattern
class Solution {
public:
    vector<int> topoSort(unordered_map<int, list<int>>& adj, int n, vector<int>& indegree){
        queue<int> q;
        for(int i=0; i<n; i++) if(indegree[i]==0) q.push(i);
        vector<int> ans;
        while(!q.empty()){
            int f = q.front(); q.pop();
            ans.push_back(f);
            // visit neighbours
            for(auto& next: adj[f]){
                indegree[next]--;
                if(indegree[next]==0){
                    q.push(next);
                }
            }
        }
        return ans;
    }
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        // assign groups to elements which belong to -1
        for(int i=0; i<n; i++){
            if(group[i]==-1){
                group[i] = m++;
            }
        }
        // first find out the order of items
        unordered_map<int, list<int>> adj1;
        vector<int> indegree1(n, 0);
        for(int i=0; i<n; i++){
            int k = beforeItems[i].size();
            for(int j=0; j<k; j++){
                adj1[beforeItems[i][j]].push_back(i);
                indegree1[i]++;
            }
        }
        vector<int> itemsOrder = topoSort(adj1, n, indegree1);

        // secondly find out the order of groups
        unordered_map<int, list<int>> adj2;
        vector<int> indegree2(m, 0);
        for(int i=0; i<n; i++){
            int groupOfItem = group[i];
            int k = beforeItems[i].size();
            for(int j=0; j<k; j++){
                int beforeItem = beforeItems[i][j];
                int groupOfBeforeItem = group[beforeItem];
                if(groupOfBeforeItem==groupOfItem) continue;
                adj2[groupOfBeforeItem].push_back(groupOfItem);
                indegree2[groupOfItem]++;
            }
        }
        vector<int> groupsOrder = topoSort(adj2, m, indegree2);

        // for(auto& e: itemsOrder) cout<<e<<" ";cout<<endl;
        // for(auto& e: groupsOrder) cout<<e<<" ";cout<<endl;

        // then place items accordingly and return answer
        unordered_map<int, list<int>> groupsToItemsMap;
        for(auto& item: itemsOrder){
            int g = group[item];
            groupsToItemsMap[g].push_back(item);
        }
        vector<int> ans;
        for(auto& g: groupsOrder){
            for(auto& item: groupsToItemsMap[g]){
                ans.push_back(item);
            }
        }
        if(ans.size()!=n) return {};
        return ans;
    }
};