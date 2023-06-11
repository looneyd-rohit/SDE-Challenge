// Approach 1: using visited approach
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // using visited approach
        int n = nums.size();
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(nums[abs(nums[i]) - 1] < 0){
                // if already visited push in array
                ans.push_back(abs(nums[i]));
            }else{
                // marking visited
                nums[abs(nums[i]) - 1] *= -1;
            }
        }
        return ans;
    }
};

// Approach 2: using swap sort
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // using swap sort
        // this method works since any duplicate element is present twice, which means after
        // swap sort process one will be at correct index and one will be at incorrect index.
        int n = nums.size();
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(nums[i] != nums[nums[i]-1]){
                swap(nums[i], nums[nums[i]-1]);
                i--;
            }
        }
        for(int i=0; i<n; i++){
            if(nums[i]!=i+1){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};
