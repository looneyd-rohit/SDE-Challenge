// Leetcode 767

class Solution {
public:
    string reorganizeString(string s) {
        int n = s.length();
        unordered_map<char, int> hash;
        for(auto& e: s) hash[e]++;
        // maxheap or minheap anything will heap --> pick two distinct from heap
        // and append them
        priority_queue<pair<int, char>> maxheap;
        for(auto& e: hash) maxheap.push({e.second, e.first});
        string ans = "";
        while(maxheap.size() > 1){
            auto top1 = maxheap.top(); maxheap.pop();
            auto top2 = maxheap.top(); maxheap.pop();
            // cout<<top1.second<<" : "<<top2.second<<endl;
            ans.push_back(top1.second);
            ans.push_back(top2.second);
            top1.first--; top2.first--;
            if(top1.first > 0) maxheap.push(top1);
            if(top2.first > 0) maxheap.push(top2);
        }
        if(maxheap.empty()) return ans;
        if(!maxheap.empty() && maxheap.top().first == 1){
            ans.push_back(maxheap.top().second);
            return ans;
        }
        return "";
    }
};