// Leetcode 1238
// [IMP]: Gray Code Generation + Conversion

class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        // gray code problem:
        vector<int> grayCode;
        // start is in grayCode, convert it to binary
        int bin = 0;
        for(; start; start>>=1){
            bin = bin ^ start;
        }
        // generation
        for(int i=bin; i<(1<<n); i++){
            grayCode.push_back(i ^ (i>>1));
        }
        for(int i=0; i<bin; i++){
            grayCode.push_back(i ^ (i>>1));
        }
        return grayCode;
    }
};