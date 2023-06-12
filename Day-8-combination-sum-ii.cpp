class Solution {
public:
    void solve(int index, int target, vector<int>& arr, vector<int>& temp, vector<vector<int>>& ans){
        // base case
        if(target == 0){
            // as soon as target becomes zero we take it into account, and then return
            ans.push_back(temp);
            return ;
        }

        for(int i=index; i<arr.size(); i++){
            if(i > index && arr[i]==arr[i-1]) continue;

            if(target >= arr[i]){
                temp.push_back(arr[i]);
                solve(i+1, target-arr[i], arr, temp, ans);
                temp.pop_back();
            }else{
                break;
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        vector<vector<int>> ans;
        solve(0, target, candidates, temp, ans);
        return ans;
    }
};