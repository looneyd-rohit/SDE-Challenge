// Leetcode 3008

// Approach: using kmp + sorting
class Solution {
public:
    void computeLPS(string& pattern, vector<int>& lps, int m){
        int len = 0;
        lps[0] = len;
        int i = 1;
        while(i<m){
            if(pattern[i]==pattern[len]){
                lps[i++] = ++len;
            }else{
                if(len > 0) len = lps[len-1];
                else{
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
    vector<int> findMatchingIndicesKMP(string& text, string& pattern, vector<int>& lps){
        int n = text.length(), m = pattern.length();
        int i=0, j=0;
        vector<int> ans;
        while(i<n){
            if(j<m && text[i]==pattern[j]){
                i++; j++;
                if(j==m){
                    // full match found, 🚀
                    ans.push_back(i-j);
                }
            }else{
                // trace back
                if(j>0) j = lps[j-1];
                else i++;
            }
        }
        return ans;
    }
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        // KMP algorithm variant
        // find all indices where a matches in string s
        // find all indices where b matches in string s
        // then check for which i and j are satisfying conditions
        int n = s.length(), x = a.length(), y = b.length();
        vector<int> a_lps(x, 0);
        computeLPS(a, a_lps, x);
        vector<int> arr = findMatchingIndicesKMP(s, a, a_lps);
        
        vector<int> b_lps(y, 0);
        computeLPS(b, b_lps, y);
        vector<int> brr = findMatchingIndicesKMP(s, b, b_lps);

        // now get all indices from arr that satisfies |brr[j]-arr[i]| <= k
        sort(begin(arr), end(arr));
        sort(begin(brr), end(brr));

        vector<int> ans;
        for(int i=0; i<arr.size(); i++){
            int e = arr[i];
            int k1 = lower_bound(begin(brr), end(brr), e-k) - begin(brr);
            if(k1<brr.size() && abs(e-brr[k1])<=k){
                ans.push_back(e);
            }else{
                int k2 = upper_bound(begin(brr), end(brr), e) - begin(brr);
                if(k2<brr.size() && brr[k2]-e<=k){
                    ans.push_back(e);
                }
            }
        }
        return ans;
    }
};