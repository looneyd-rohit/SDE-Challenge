// Leetcode 41

// Approach 1: using hashmaps + brute force T.C: O(n) S.C: O(n)
// (code not shared)

// Approach 2: sorting + binary search (kth missing positive number) T.C: O(nlogn) S.C: O(n)
class Solution {
public:
    int kthMissingPositive(vector<int>& nums, int k){
        int n = nums.size();
        sort(begin(nums), end(nums));
        int low = 0, high = n-1;
        while(low <= high){
            int mid = low + ((high - low) >> 1);
            int missing = nums[mid] - (mid+1);
            if(missing < k) low = mid + 1;
            else high = mid - 1;
        }
        return (high + 1 + k);
    }
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> unique(begin(nums), end(nums));
        vector<int> positive;
        for(auto& e: unique) if(e > 0) positive.push_back(e);
        return kthMissingPositive(positive, 1);
    }
};

// Approach 3: modifying the array by visiting indices and eliminating out of range elements [1,n] T.C: O(n) S.C: O(1)
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        // check if the array contains 1 and also mark out of range elements [1...n]
        bool contains_one = false;
        for(int i=0; i<n; i++){
            if(nums[i]==1) contains_one = true;
            if(nums[i]<=0 || nums[i]>n) nums[i] = 1;
        }
        if(contains_one==false) return 1;
        // if 1 is present then go and mark indices negative
        for(int i=0; i<n; i++){
            int e = abs(nums[i]);
            int ind = e-1;

            if(nums[ind]<0) continue;
            nums[ind] *= -1;
        }
        for(int i=0; i<n; i++){
            if(nums[i]>0) return i+1;
        }
        return (n+1);
    }
};

// Approach 4: using swap sort T.C: O(n) S.C: O(1)
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        // using swap sort -> nice question \U0001f680
        // only take the valid numbers [1...n] since all others
        // either negative or out of range cannot be a valid answer
        // for array of size n
        for(int i=0; i<n; i++){
            if(nums[i]>=1 && nums[i]<=n){    // check validity
                if(nums[i]!=nums[nums[i]-1]){
                    // swap required
                    swap(nums[i], nums[nums[i]-1]);
                    i--;
                }
            }
        }
        // now re visit the array to find the missing
        for(int i=0; i<n; i++){
            if(i!=1LL*nums[i]-1){
                return (i+1);
            }
        }
        // if none satisfies then n+1 is the answer
        return (n+1);
    }
};