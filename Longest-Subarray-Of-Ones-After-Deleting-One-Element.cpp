// Leetcode 1493
// Groups approach:
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int prev = nums[0];
        int cnt = 1;
        vector<pair<int, int>> groups;
        for(int i=1; i<n; i++){
            if(prev == nums[i]){
                cnt++;
            }else{
                groups.push_back({prev, cnt});
                cnt = 1;
                prev = nums[i];
            }
        }
        groups.push_back({prev, cnt});
        bool deleted = groups.size() > 1;
        // for(auto& e: groups) cout<<e.first<<" "<<e.second<<endl;
        if(!groups.empty() && groups.front().first == 0) groups.erase(groups.begin());
        if(!groups.empty() && groups.back().first == 0) groups.pop_back();
        if(groups.empty()) return 0;
        // for(auto& e: groups) cout<<e.first<<" "<<e.second<<endl;
        int maxi = groups[0].second;
        for(int i=2; i<groups.size(); i+=2){
            if(groups[i-1].second == 1){
                if(groups[i-2].second + groups[i].second > maxi){
                    maxi = groups[i-2].second + groups[i].second;
                }
            }else{
                if(max(groups[i-2].second, groups[i].second)> maxi){
                    maxi = max(groups[i-2].second, groups[i].second);
                }
            }
        }
        if(!deleted) return maxi - 1;
        return maxi;
    }
};

// Counter based approach: (counting two adjacent groups of 1's)
// if two adjacent does not exist we assume it to be of length 0
// like in 1,1,1,1,0,0,0,1,1,1.... --> we can do
// [(1)=(4 times)],0,[(1)=(0 times)],0,[(1)=(0 times)],0,[[(1)=(3 times)]]
// here we can combine two adjancent 1 groups to get answer
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int firstOneGroup = 0, secondOneGroup = 0;
        int maxi = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == 1){
                secondOneGroup++;
            }else{
                firstOneGroup = secondOneGroup;
                secondOneGroup = 0;
            }
            maxi = max(maxi, firstOneGroup + secondOneGroup);
        }
        return (maxi < n) ? maxi : maxi - 1;
    }
};