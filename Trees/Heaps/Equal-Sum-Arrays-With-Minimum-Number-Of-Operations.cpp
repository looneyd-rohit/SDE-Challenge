// Leetcode 1775

class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int sum1 = 0, sum2 = 0;
        for(auto& e: nums1) sum1 += e;
        for(auto& e: nums2) sum2 += e;
        if(sum1 < sum2) return minOperations(nums2, nums1);
        if(n1*1 > n2*6) return -1;
        int abs_diff = sum1 - sum2;
        priority_queue<int> pq1, pq2;
        for(auto& e: nums1) pq1.push(e-1);
        for(auto& e: nums2) pq1.push(6-e);
        int upper = 0, lower = 0;
        while(abs_diff){
            if(!pq1.empty()){
                abs_diff -= pq1.top(); pq1.pop();
                upper++;
            }

            if(abs_diff<=0) break;

            if(!pq2.empty()){
                abs_diff -= pq2.top(); pq2.pop();
                lower++;
            }
        }
        return max(upper, lower);
    }
};