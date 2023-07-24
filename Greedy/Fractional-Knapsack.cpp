// https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        double maxi = 0.0;
        vector<pair<double, int>> new_arr;
        for(int i=0; i<n; i++){
            double valuePerKg = (arr[i].value * 1.0) / arr[i].weight;
            new_arr.push_back({valuePerKg, i});
        }
        sort(begin(new_arr), end(new_arr));
        reverse(begin(new_arr), end(new_arr));
        for(int i=0; i<n; i++){
            if(W >= arr[new_arr[i].second].weight){
                maxi += arr[new_arr[i].second].value;
                W -= arr[new_arr[i].second].weight;
            }else{
                maxi += (new_arr[i].first * W);
                W = 0;
                break;
            }
        }
        return maxi;
    }
        
};
