// Leetcode 1371
// [IMP]: BitMask String Pattern

class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n = s.length();
        unordered_map<char, int> maps;
        maps['a'] = 0; maps['e'] = 1; maps['i'] = 2; maps['o'] = 3; maps['u'] = 4;
        unordered_map<int, int> hash;
        hash[0] = -1;
        int mask = 0;
        int i=0, j=0;
        int maxi =0;
        for(int i=0; i<n; i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
                mask = mask ^ (1 << (maps[s[i]]));
            }

            // check if mask is 0 or not
            // if mask is zero then [...i] is considered
            if(mask == 0){
                maxi = max(maxi, i - hash[0]);
            }
            // else if mask is not zero, then we need the previous state where the same mask was encountered
            else{
                if(hash.find(mask)!=hash.end()){
                    maxi = max(maxi, i - hash[mask]);
                }
            }

            if(hash.find(mask)==hash.end()){
                hash[mask] = i;
            }
        }
        return maxi;
    }
};