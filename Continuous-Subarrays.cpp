// Leetcode 2762 (IMP Sliding Window variant)
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

// deque based approach:
class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        // logic: keep track of the maximum and minimum in a range
        int n = nums.size();
        long long ans = 0;
        // to get the minimum and maximum in a range maintain two deques
        deque<int> mini, maxi;
        int i = 0, j = 0;
        while(j<n){
            int el = nums[j];
            // we are maintaining a increasing sequence for maxi -> largest element at back
            while(!maxi.empty() && maxi.front() < el) maxi.pop_front();
            // we are maintaining a decreasing sequence for mini -> smallest element at back
            while(!mini.empty() && mini.front() > el) mini.pop_front();

            maxi.push_front(el);
            mini.push_front(el);

            int greatest = maxi.back(), smallest = mini.back();
            while(greatest - smallest > 2){
                // condition not satisfied
                if(greatest == nums[i]) maxi.pop_back();
                else if(smallest == nums[i]) mini.pop_back();
                greatest = maxi.back(), smallest = mini.back();
                i++;
            }
            ans += j-i+1;
            j++;
        }
        return ans;
    }
};