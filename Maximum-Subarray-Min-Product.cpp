// Leetcode 1856
// [IMP]: very nice approach question
class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        const int M = 1e9+7;
        // [accumulated logic]: assume every element to be minimum for a subarray for which
        // it can be, then find the minimum product of that array, since we have to maximize
        // the min product, hence maximizing each of the products will eventually minimize
        // the max product. Now, since array contains (+)ve numbers, sum will be maximized
        // by maximizing subarray itself, hence to find the maximum subarray for which
        // current element can be minimum, we can take the left prev smaller element and 
        // next smaller element
        vector<long long> prefixsum(n, nums[0]);
        for(int i=1; i<n; i++) prefixsum[i] = prefixsum[i-1] + nums[i];
        vector<int> nsme(n, n);
        vector<int> psme(n, -1);
        stack<int> st;
        for(int i=n-1; i>=0; i--){
            int el = nums[i];
            while(!st.empty() && nums[st.top()] >= el) st.pop();
            if(!st.empty()) nsme[i] = st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=0; i<n; i++){
            int el = nums[i];
            while(!st.empty() && nums[st.top()] >= el) st.pop();
            if(!st.empty()) psme[i] = st.top();
            st.push(i);
        }
        // for(auto& e: psme) cout<<e<<" ";cout<<endl;
        // for(auto& e: nsme) cout<<e<<" ";cout<<endl;
        long long ans = LONG_MIN;
        for(int i=0; i<n; i++){
            int el = nums[i];
            // assume el to be minimum
            int prev = psme[i], next = nsme[i];
            long long prevEl = (prev != -1) ? prefixsum[prev] : 0;
            long long nextEl = prefixsum[next-1];
            long long diff = (nextEl - prevEl);
            long long pdt = (el * diff);
            // cout<<pdt<<endl;
            // cout<<el<<" "<<prev<<" "<<next<<" "<<diff<<" "<<pdt<<endl;
            ans = max(ans, pdt);
        }
        return ans % M;
    }
};