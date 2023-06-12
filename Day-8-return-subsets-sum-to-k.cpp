#include<bits/stdc++.h>
void solve(int index, int sum, vector<int>& arr, vector<int>& temp, vector<vector<int>>& ans){
    // base case
    if(index >= arr.size()){
        if(sum == 0){
            ans.push_back(temp);
        }
        return;
    }

    // pick
    temp.push_back(arr[index]);
    solve(index+1, sum-arr[index], arr, temp, ans);
    temp.pop_back();

    // notPick
    solve(index+1, sum, arr, temp, ans);
}
vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    // sort(begin(arr), end(arr));
    vector<int> temp;
    vector<vector<int>> ans;
    solve(0, k, arr, temp, ans);
    return ans;
}