// Leetcode 1122

// Approach 1: using map + sort
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size(), m = arr2.size();
        unordered_map<int, int> umap;
        for(int i=0; i<m; i++) umap[arr2[i]] = i;
        int cnt = arr2.size();
        vector<int> ans, extra;
        for(int i=0; i<n; i++){
            if(umap.find(arr1[i])!=umap.end()){
                ans.push_back(umap[arr1[i]]);
            }else{
                extra.push_back(arr1[i]);
            }
        }
        sort(begin(ans), end(ans));
        sort(begin(extra), end(extra));
        for(auto& e: ans){
            e = arr2[e];
        }
        for(auto& e: extra) ans.push_back(e);
        return ans;
    }
};

// Approach 2: count sort
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        // counting sort
        int n = arr1.size(), m = arr2.size();
        vector<int> counts(1001, 0);
        for(auto& e: arr1) counts[e]++;
        vector<int> ans;
        for(auto& e: arr2){
            while(counts[e]>0){
                ans.push_back(e);
                counts[e]--;
            }
        }
        for(int i=0; i<1001; i++){
            while(counts[i]>0){
                ans.push_back(i);
                counts[i]--;
            }
        }
        return ans;
    }
};

// Approach 3: using lambda functions
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        // counting sort
        int n = arr1.size(), m = arr2.size();
        unordered_map<int, int> umap;
        for(int i=0; i<m; i++) umap[arr2[i]] = i;
        sort(begin(arr1), end(arr1), [&](int a, int b){
            if(umap.find(a)!=umap.end() && umap.find(b)!=umap.end()){
                return umap[a] < umap[b];
            }else if(umap.find(a)!=umap.end() && umap.find(b)==umap.end()){
                return true;
            }else if(umap.find(a)==umap.end() && umap.find(b)!=umap.end()){
                return false;
            }else{
                return a < b;
            }
        });
        return arr1;
    }
};