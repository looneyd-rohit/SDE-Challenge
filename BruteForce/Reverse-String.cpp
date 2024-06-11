// Leetcode 344

// Approach: brute force
class Solution {
public:
    void reverseString(vector<char>& s) {
        reverse(begin(s), end(s));
    }
};