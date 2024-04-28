// Leetcode 321

// Approach: monotonic stack + maintaining k length largest number from an array where relative positions remain same
class Solution {
public:
    string largestNumberOfLengthK(vector<int>& arr, int k){
        int n = arr.size();
        string ans = "";
        for(int i=0; i<n; i++){
            while((!ans.empty()) && ((n-i) > (k-ans.size())) && ((ans.back()-'0') < arr[i])) ans.pop_back();
            if(ans.size() < k) ans += to_string(arr[i]);
        }
        return ans;
    }
    string largestMerge(string& a, string& b){
        int n = a.length(), m = b.length();
        int i = 0, j = 0;
        string res = "";
        while(i < n && j < m){
            if(a[i] < b[j]){
                res.push_back(b[j++]);
            }else if(a[i] > b[j]){
                res.push_back(a[i++]);
            }else{
                // [IMP]: edge case
                // the string whose remaining part contributes more should be
                // given more priority
                string str1 = a.substr(i), str2 = b.substr(j);
                if(str1 > str2) res.push_back(a[i++]);
                else res.push_back(b[j++]);
            }
        }
        while(i < n) res.push_back(a[i++]);
        while(j < m) res.push_back(b[j++]);
        return res;
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        // try for all possibilities of pairs
        // i length from nums1 and (k-i) length from nums2
        string res = "";
        for(int i=0; i<=k; i++){
            string a = largestNumberOfLengthK(nums1, i);
            string b = largestNumberOfLengthK(nums2, k-i);

            string c = largestMerge(a, b);
            if(res.length() > c.length());
            else if(res.length() < c.length()) res = c;
            else res = max(res, c);
        }
        vector<int> ans;
        for(int i=0; i<k; i++) ans.push_back(res[i]-'0');
        return ans;
    }
};