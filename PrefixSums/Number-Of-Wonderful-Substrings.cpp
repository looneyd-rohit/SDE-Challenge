// Leetcode 1915

// [IMP] Approach: prefix sum + hashmap type approach
class Solution {
public:
    long long wonderfulSubstrings(string word) {
        int n = word.length();
        unordered_map<int, int> xor_store;
        xor_store[0] = 1;
        int cum_xor = 0;
        long long count = 0;
        for(auto& ch: word){
            cum_xor = cum_xor ^ (1 << (ch - 'a'));
            // all evens
            count += xor_store[cum_xor];
            // all even and one odd
            for(char c='a'; c<='j'; c++){
                int curr_xor = cum_xor ^ (1 << (c - 'a'));

                count += xor_store[curr_xor];
            }

            xor_store[cum_xor]++;
        }
        return count;
    }
};