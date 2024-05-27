// Leetcode 3164

// Approach: brute force
class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size(), m = nums2.size();
        unordered_map<int, int> ump;
        for(auto& e: nums2){
            ump[e * k]++;
        }
        long long cnt = 0;
        for(int i=0; i<n; i++){
            int num = nums1[i];
            for(int z=1; z<=sqrt(num); z++){
                if(num % z == 0){
                    cnt += ump[z];
                    if(z != num/z){
                        cnt += ump[num/z];
                    }
                }
            }
        }
        return cnt;
    }
};