// Leetcode 89

// Binary to Gray Code
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        for(int i=0; i<(1<<n); i++){
            ans.push_back(i ^ (i>>1));
        }
        return ans;
    }
};

// Gray Code to Binary
int rev_grayCode (int g) {
 int n = 0;
 for (; g; g >>= 1)
   n ^= g;
 return n;
}