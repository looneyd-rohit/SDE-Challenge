// Leetcode 1542
// Bitmask + HashTable + String

class Solution {
public:
    int longestAwesome(string s) {
        int n = s.length();
        vector<int> hash(1<<10, -69);
        hash[0] = -1;
        int mask = 0;
        int maxi = 0;
        for(int i=0; i<n; i++){
            mask = mask ^ (1 << (s[i]-'0'));
            if(!mask || !(mask & (mask-1))){
                // we can take the entire string till i
                maxi = max(maxi, i-hash[0]);
            }else{
                // find for the exact same mask before --> make every occurence of digits even
                // and one digit odd (so used +1)
                if(hash[mask]!=-69){
                    // we can take the entire string between prev mask and current mask
                    maxi = max(maxi, i-hash[mask]+1);
                }

                // toggle every digit in mask, to keep odd count of that digit and even for
                // rest of them
                for(int t=0; t<=9; t++){
                    int m = mask ^ (1 << t);
                    if(hash[m]!=-69){
                        maxi = max(maxi, i-hash[m]);
                    }
                }
            }
            if(hash[mask]==-69) hash[mask] = i;
        }
        return maxi;
    }
};