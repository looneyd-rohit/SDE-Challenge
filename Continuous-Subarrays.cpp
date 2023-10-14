// Leetcode 2762 (IMP Sliding Window variant)

// brute force:
class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        // brute force: check for all possible subarrays
        int n = nums.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            int maxi = 0, mini = 1e9+1;
            for(int j=i; j<n; j++){
                maxi = max(maxi, nums[j]);
                mini = min(mini, nums[j]);
                int diff = maxi - mini;
                if(diff<=2) ans++;
                else break;
            }
        }
        return ans;
    }
};

// Map/Set/MultiSet based approach:
class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        // logic: keep track of the maximum and minimum in a range
        int n = nums.size();
        long long ans = 0;
        multiset<int> ms;
        int i=0, j=0;
        while(j<n){
            ms.insert(nums[j]);
            // if condition meets
            int greatest = *ms.rbegin(), smallest = *ms.begin();
            if(abs(greatest - smallest)<=2){
                // no. of subarray satisfying the condition ending at j
                ans += j-i+1;
                j++;
            }
            // if conditions does not meets
            else{
                while(abs(greatest-smallest) > 2){
                    auto it = ms.find(nums[i]);
                    ms.erase(it);
                    i++;
                    greatest = *ms.rbegin(), smallest = *ms.begin();
                }
                ans += j-i+1;
                j++;
            }
        }
        return ans;
    }
};

// optimization to O(N) over O(NlogN)
class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        // optimized approach: using deques --> optimizing the multiset based approach
        // [IMP]: nice logic to optimize multisets if we only need maximum and minimum
        int n = nums.size();
        deque<int> dq1, dq2;
        // dq1 --> increasing sequence --> minimum at the front, for a particular subarray
        // dq2 --> decreasing sequence --> maximum at the front, for a particular subarray
        long long ans = 0;
        int i=0, j=0;
        while(j<n){
            // maintaining a order in the deque
            while(!dq1.empty() && dq1.back()>nums[j]) dq1.pop_back();
            while(!dq2.empty() && dq2.back()<nums[j]) dq2.pop_back();
            // add to deque
            dq1.push_back(nums[j]);
            dq2.push_back(nums[j]);

            int s = dq1.front();
            int g = dq2.front();
            if(g-s <= 2){
                // condition satisfied --> take all subarrays ending at j
                ans += j-i+1;
            }else{
                // condition not satisfied
                while(g-s>2){
                    // remove from deque
                    if(s==nums[i]){
                        dq1.pop_front();
                        s = dq1.front();
                    }else if(g==nums[i]){
                        dq2.pop_front();
                        g = dq2.front();
                    }
                    i++;
                }
                // after loop breaks condition satisfied --> take all
                ans += j-i+1;
            }
            j++;
        }
        return ans;
    }
};