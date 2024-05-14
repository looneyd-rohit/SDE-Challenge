// Leetcode 786

// [IMP] Approach 1: using binary search on answer, finding the appropriate fraction with modified check function
class Solution {
public:
    auto check(vector<int>& arr, double mid, int k){
        int n = arr.size();
        int count = 0;
        int i = 0, j = 1;
        int nume = arr.front(), deno = arr.back();
        while(j < n){
            while(i < j && (arr[i] <= arr[j] * mid)) i++;

            count += i;

            if(i > 0 && (arr[i-1] * deno > arr[j] * nume)){
                nume = arr[i-1];
                deno = arr[j];
            }

            j++;
        }
        return tuple<bool, int, int>(count >= k, nume, deno);
    }
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        // binary search to find the actual fraction
        // every fraction is in range (0, 1.0)
        double low = 0.0, high = 1.0;
        tuple<bool, int, int> temp;
        while(low <= high){
            double mid = low + ((high - low) / 2);
            auto t = check(arr, mid, k);
            if(get<0>(t)){
                // check if countOfSmallerThanMid >= k
                high = mid - 1e-7;
                temp = t;
            }else{
                low = mid + 1e-7;
            }
        }
        vector<int> ans;
        ans.push_back(get<1>(temp));
        ans.push_back(get<2>(temp));
        return ans;
    }
};

// Approach 2: using maxheap
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> ans;
        priority_queue<tuple<double, int, int>> pq;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                pq.push(tuple<double, int, int>(arr[i] / (1.0 * arr[j]), arr[i], arr[j]));
                if(pq.size() > k) pq.pop();
            }
        }
        auto t = pq.top();
        ans.push_back(get<1>(t));
        ans.push_back(get<2>(t));
        return ans;
    }
};