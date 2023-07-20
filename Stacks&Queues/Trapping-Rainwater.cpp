// Leetcode 42

class Solution {
public:
    void computePGRE(vector<int>& arr, vector<int>& pgre){
        int n = arr.size();
        deque<int> dq;    // stores index
        for(int i=0; i<n; i++){
            while(!dq.empty() && arr[dq.back()]<=arr[i]) dq.pop_back();
            if(!dq.empty()) pgre[i] = dq.front();
            dq.push_back(i);
        }
    }
    void computeNGRE(vector<int>& arr, vector<int>& ngre){
        int n = arr.size();
        deque<int> dq;    // stores index
        for(int i=n-1; i>=0; i--){
            while(!dq.empty() && arr[dq.back()]<=arr[i]) dq.pop_back();
            if(!dq.empty()) ngre[i] = dq.front();
            dq.push_back(i);
        }
    }
    int trap(vector<int>& height) {
        // similar concept of next greater and prev greatest to be applied
        int n = height.size();
        vector<int> pgre(n, -1);
        vector<int> ngre(n, n);
        // compute previous and next greatest elements [not greater!!!]
        computePGRE(height, pgre);
        computeNGRE(height, ngre);
        
        int ans = 0;
        for(int i=0; i<n; i++){
            int prev = pgre[i], next = ngre[i];
            if(prev!=-1 && next!=n){
                // water can be accomodated
                int prevHeight = height[prev], nextHeight = height[next];
                int currentHeight = height[i];
                int water = 1 * (min(prevHeight, nextHeight)-currentHeight);
                ans += water;
            }
        }
        return ans;
    }
};